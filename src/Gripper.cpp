// Gripper.cpp
#include "../include/Gripper.h"
#include <Arduino.h>

Gripper::Gripper(int IN1,int IN2,int SLEEP,int PMODE) {
  _IN1=IN1;
  _IN2=IN2;
  _SLEEP=SLEEP;
  _PMODE=PMODE;
  pinMode(_IN1, OUTPUT);
  pinMode(_IN2, OUTPUT);
  pinMode(_SLEEP,OUTPUT);
  pinMode(_PMODE,OUTPUT);
  digitalWrite(_SLEEP,HIGH);
  digitalWrite(_PMODE,HIGH);
  Kp =0.15;
  Ki =0.0035;
  Kd =0;
  error=0;           // error between current and target positions
  lastError=0;         // previous error value
  integral=0;         // integral of error over time
  derivative=0;        // derivative of error over time
  output=0;      // output value to control motor
  dir=-1;
  targetPosition = 5; 
  ActualPosition = 0;
}

void Gripper::pidStep() {
  ActualPosition=mapfloat(analogRead(A0),280,90,0,100);
  // ActualPosition=analogRead(A0);
  error = targetPosition - ActualPosition;
  // update the integral and derivative terms
  integral +=error;
  if (integral >= 100) integral = 100;
  else if (integral < -100) integral = -100;

  derivative = error - lastError;
  lastError = error;
  // calculate the output value using the PID equation
  output = (Kp * error) + (Ki * integral) + (Kd * derivative);

  if(output>=0) dir=1;
  else dir=-1;

  setMotor(dir,abs(output),_IN1,_IN2);  
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
