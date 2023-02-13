#ifndef Gripper_h
#define Gripper_h

class Gripper {
  public:
    Gripper(int IN1,int IN2,int SLEEP,int PMODE);
    float pidStep(int target);
    void setMotor(int dir, int pwmVal, int in1, int in2);
    float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
    float measureCurrent(int cur_pin);
    void init_gripper();
    int targetPosition; 
    int ActualPosition; 

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