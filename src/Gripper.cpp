// Gripper.cpp
#include "../include/Gripper.h"
#include <Arduino.h>

Gripper::Gripper(int IN1,int IN2,int SLEEP,int PMODE) {
  _IN1=IN1;
  _IN2=IN2;
  _SLEEP=SLEEP;
  _PMODE=PMODE;

}
void Gripper::init_gripper(){
  pinMode(_IN1, OUTPUT);
  pinMode(_IN2, OUTPUT);
  pinMode(_SLEEP,OUTPUT);
  pinMode(_PMODE,OUTPUT);
  digitalWrite(_SLEEP,HIGH);
  digitalWrite(_PMODE,HIGH);
  Kp =0.15;
  Ki =0.001;
  Kd =0;
  lastError=0;         // previous error value
  integral=0;         // integral of error over time
  derivative=0;        // derivative of error over time
  // output=0;      // output value to control motor
  dir=-1;
  targetPosition = 5; 
  ActualPosition = 0;
}
float Gripper::pidStep(int target) {
  
  targetPosition=target;
  // Serial.println(analogRead(A0));
  ActualPosition=mapfloat(analogRead(A0),260,65,0,100);
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

float Gripper::mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float Gripper::measureCurrent(int cur_pin){
  int sensorValue = analogRead(cur_pin);
  float voltage = (sensorValue * 5 / 1024) - 2.5;  // convert the ADC value to voltage and remove the offset
  float current = voltage / 0.4;  // sensitivity of the current sensor is 400mV/A
  return current;
}

