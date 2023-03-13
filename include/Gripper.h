#ifndef Gripper_h
#define Gripper_h
#include "../include/Configuration.h"
#include "../include/CommController.h"
class Gripper {
  public:
    Gripper(int in1,int in2,int sleep,int pmode);
    float pidStep();
    void setMotor(int dir, int pwmVal, int in1, int in2);
    float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
    float measureCurrent(int cur_pin);
    void calibrateGripper();
    void init_gripper();
    void moveMotorSlow(int time,int dir);
    void executeCommand(eCommands _in_command, void *_payload, int _payload_size);
    void distribute(CommandFromHost _in_command,SoftwareSerial *Ser);

    int targetPosition; 
    int ActualPosition; 
    int maxposition;
    int minposition;

  private:
    float Kp;
    float Ki;
    float Kd;
    int _IN1;
    int _IN2;
    int _SLEEP;
    int _PMODE;
    int _current_pin;
    float lastError;         // previous error value
    float integral;          // integral of error over time
    float derivative;        // derivative of error over time

    float dir;
};

#endif