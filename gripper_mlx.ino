#include "include/Gripper.h"
#include "include/MLX90393.h"
#include "include/Pinout.h"
#include "include/Configuration.h"
#include "include/CommController.h"
#include <SoftwareSerial.h>




int sampleCount = 0;
int sampleRate = 0;
int previous=0;
float last_current;
float output;
int SLOW_LOOP_PREV =0;
int FAST_LOOP_PREV =0;
int target; 
// SoftwareSerial mySerial(rx_pin,tx_pin);
Gripper grip(IN1,IN2,SLEEP,PMODE);
// RS485Comm comms(&mySerial);
// MLX90393 MagneticSensor(Addr);

void setup() {
  Serial.begin(115200);
  grip.init_gripper();
  grip.calibrateGripper();
  // MagneticSensor.Setup(Addr);
  // comms.RS485Comm_setup();
} 

//Main Loop
void loop() {
//Communicationloop - 30Hz
  if (millis() - SLOW_LOOP_PREV > SLOW_LOOP_T )
  {
    // MagneticSensor.Read();
    // comms.mlx_x=MagneticSensor.x;
    // comms.mlx_y=MagneticSensor.y;
    // comms.mlx_z=MagneticSensor.z;
    // comms.actual_pos=grip.ActualPosition;
    // comms.current=grip.measureCurrent(Current);
    target=50;//comms.ReadFromHost();
    // Serial.print(target);
    // Serial.print(",");
    // Serial.println(grip.ActualPosition);
    // if(VERBOSE){
    // Serial.print("  Mlx_x ");Serial.print(MagneticSensor.x);
    // Serial.print("  Mlx_y ");Serial.print(MagneticSensor.y);
    // Serial.print("  Mlx_z ");Serial.print(MagneticSensor.z);    
    // Serial.print("  Act_Pos ");Serial.print(grip.ActualPosition);
    // Serial.print("  Targ_Pos ");Serial.println(grip.targetPosition);

    // }
    SLOW_LOOP_PREV=millis();
  }  

  //Fast Loop - 500-1KHz
  if (micros() - FAST_LOOP_PREV > FAST_LOOP_T )
  {
  // output=grip.pidStep(target);

  FAST_LOOP_PREV=micros();
  sampleCount++;
  }

  //Print Samplerate loop 1Hz
  if (millis() - previous>(1000))
  {
    sampleRate=sampleCount;
    previous=millis();
    sampleCount=0;    
  }  
}


