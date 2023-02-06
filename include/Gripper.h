#ifndef Gripper_h
#define Gripper_h

class Gripper {
  public:
    Gripper(int IN1,int IN2,int SLEEP,int PMODE);
    void pidStep();
    void setMotor(int dir, int pwmVal, int in1, int in2);
    float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
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
    long error;             // error between current and target positions
    long lastError;         // previous error value
    long integral;          // integral of error over time
    long derivative;        // derivative of error over time
    long output;            // output value to control motor
    int dir;
};

#endif