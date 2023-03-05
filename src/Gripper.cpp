// Gripper.cpp
#include "../include/Gripper.h"

extern RS485Comm comms;

Gripper::Gripper(int in1,int in2,int sleep,int pmode) {
  _IN1=in1;
  _IN2=in2;
  _SLEEP=sleep;
  _PMODE=pmode;

}
void Gripper::init_gripper(){
  pinMode(_IN1, OUTPUT);
  pinMode(_IN2, OUTPUT);
  pinMode(_SLEEP,OUTPUT);
  pinMode(_PMODE,OUTPUT);
  digitalWrite(_SLEEP,HIGH);
  digitalWrite(_PMODE,HIGH);
  Kp =0.15;//faster gripper 0.04
  Ki =0.001;
  Kd =0;
  lastError=0;         // previous error value
  integral=0;         // integral of error over time
  derivative=0;        // derivative of error over time
  // output=0;      // output value to control motor
  dir=-1;
  targetPosition = 50; 
  ActualPosition = 0;
}
float Gripper::pidStep() {
  
  ActualPosition=mapfloat(analogRead(A0),maxposition,minposition,0,100);

  // ActualPosition=analogRead(A0);
  float error =  targetPosition - ActualPosition;
  // update the integral and derivative terms
  integral +=error;
  if (integral >= 100) integral = 100;
  else if (integral < -100) integral = -100;

  derivative = error - lastError;
  lastError = error;
  // calculate the output value using the PID equation
  float output = (Kp * error) + (Ki * integral) + (Kd * derivative);

  if(output>=0) dir=1;
  else dir=-1;
  setMotor(dir,abs(output),_IN1,_IN2);  
  return output;
}

void Gripper::setMotor(int dir, int out, int in1, int in2) {
  if(out==0){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
    }
    else{
      if(dir == 1){
        // analogWrite(in1,pwmVal);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
      } else if(dir == -1){

        // analogWrite(in2,pwmVal);
        digitalWrite(in2,HIGH);
        digitalWrite(in1,LOW);
      }
    }
}
void Gripper::moveMotorSlow(int time,int dir)
{
  unsigned long enter=millis();
  while(millis() -enter<time)
  {
  setMotor(dir,1,_IN1,_IN2);  
  delay(75);//faster gripper 20
  setMotor(dir,0,_IN1,_IN2);  
  delay(5);//faster gripper 10
  }
}
void Gripper::calibrateGripper()
{

int gripperOpenDelay = 10; // milliseconds
int minPos = 1023; // maximum value of analogRead
int maxPos = 0; // minimum value of analogRead

 moveMotorSlow(1500,1);
  int pos = analogRead(A0);
  int prevPos = pos;
  unsigned long stuckStart = millis();
    int now=millis();

  while (millis() - stuckStart < gripperOpenDelay && millis()-now<1000) {
    prevPos = pos;
    pos = analogRead(A0);
    if (pos == prevPos) {
      // Gripper is mechanically stuck, update min position
      if (pos < minPos) minPos = pos;
    } else {
      // Gripper is still moving, reset stuckStart
      stuckStart = millis();
    }
  }

  // Stop the motor and wait for the gripper to come to a complete stop
  setMotor(1,0,_IN1,_IN2);  

  delay(200);

  // Move the gripper in the other direction until it's mechanically stuck
 moveMotorSlow(1500,-1);

  pos = analogRead(A0);
  prevPos = pos;
  stuckStart = millis();
  now=millis();
  while (millis() - stuckStart < gripperOpenDelay && millis()-now<1500) {
    prevPos = pos;
    pos = analogRead(A0);
    if (pos == prevPos) {
      // Gripper is mechanically stuck, update max position
      if (pos > maxPos) maxPos = pos;
    } 
    else {
      // Gripper is still moving, reset stuckStart
      stuckStart = millis();
    }
  }

  // Stop the motor and wait for the gripper to come to a complete stop
  setMotor(1,0,_IN1,_IN2);  

  delay(200);
  maxposition=maxPos;
  minposition=minPos;
    now=millis();

  while(ActualPosition!=50 && millis()-now<1500)
  {
  targetPosition=50;
  pidStep();//First position
  }
Serial.println("Finished calibration succesfully");

}

float Gripper::mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float Gripper::measureCurrent(int cur_pin){
  int sensorValue = analogRead(cur_pin);
  float voltage = (sensorValue * 5 / 1024) - 2.5;  // convert the ADC value to voltage and remove the offset
  float current = voltage / 0.4;  // sensitivity of the current sensor is 400mV/A
  return current;
}

void Gripper::distribute(CommandFromHost _in_command,SoftwareSerial *Ser){

if(_in_command._command == eMoveToPos){
  int target;
  target=int(_in_command._payload[0]);
  targetPosition=target;
  ResponseToHost res;
  res._endpoint=eHost;
  res._response=eConfirm;
  res._payload_size = sizeof(int);
  *(int*)res._payload = 101;
  comms.sendRes(res);
  }
else if(_in_command._command == eGetPos){
  ResponseToHost res;
  res._endpoint=eHost;
  res._response=eData;
  res._payload_size = sizeof(int);
  *(int*)res._payload = ActualPosition;
  comms.sendRes(res);
}
else if(_in_command._command == eGetCurrent){
  ResponseToHost res;
  res._endpoint=eHost;
    res._response=eData;
  res._payload_size = sizeof(float);
  *(float*)res._payload = measureCurrent(A2);
  comms.sendRes(res);
}
else if(_in_command._command == eEnable){
  digitalWrite(SLEEP,HIGH);
    ResponseToHost res;
  res._endpoint=eHost;
  res._response=eConfirm;
  res._payload_size = sizeof(int);
  *(int*)res._payload = 102;
  comms.sendRes(res);
}
else if(_in_command._command == eDisable){
    digitalWrite(_SLEEP,LOW);
    ResponseToHost res;
  res._endpoint=eHost;
    res._response=eConfirm;
  res._payload_size = sizeof(int);
  *(int*)res._payload = 103;
  comms.sendRes(res);
}
else if(_in_command._command == eReset){
    ResponseToHost res;
  res._endpoint=eHost;
    res._response=eConfirm;
  res._payload_size = sizeof(int);
  *(int*)res._payload = 104;
  comms.sendRes(res);
}
else if(_in_command._command == eCalibrate){
  calibrateGripper();
    ResponseToHost res;
  res._endpoint=eHost;
  res._response=eConfirm;
  res._payload_size = sizeof(int);
  *(int*)res._payload = 105;
  comms.sendRes(res);
}
else{
  comms.prepare_transmit();
  Ser->write("E5");
}

}
