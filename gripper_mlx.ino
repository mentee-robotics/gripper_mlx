#include "include/Pinout.h"
#include "include/Configuration.h"
#include "include/Gripper.h"
#include "include/MLX90393.h"
#include "include/CommController.h"
#include <SoftwareSerial.h>
#include "include/Thread.h"
#include "include/ThreadController.h"

// ThreadController that will controll all threads
ThreadController controll = ThreadController();

//My Thread (as a pointer)
Thread* Read = new Thread();

int sampleCount = 0;
int sampleRate = 0;
int previous=0;
float last_current;
float output;
int SLOW_LOOP_PREV =0;
int FAST_LOOP_PREV =0;
int target; 

SoftwareSerial mySerial(rx_pin,tx_pin);
Gripper grip(IN1,IN2,SLEEP,PMODE);
RS485Comm comms(&mySerial);
MLX90393 MagneticSensor_right(0x1A);
MLX90393 MagneticSensor_left(0x18);

void distribute(CommandFromHost i_command){
  if(i_command._endpoint == eGripper)
  {
    grip.distribute(i_command,&mySerial);
  }
  else if(i_command._endpoint == eMLX_right)
  {
    MagneticSensor_right.distribute(i_command,&mySerial);
}
else if(i_command._endpoint == eMLX_left)
  {
    MagneticSensor_left.distribute(i_command,&mySerial);
}
  else
  {
    mySerial.write("E4");
  }
}
void read()
{
comms.ReadFromHost();
sampleCount++;
}
void setup() {
  Serial.begin(115200);
  grip.init_gripper();
  grip.calibrateGripper();
  MagneticSensor_right.Setup();
  MagneticSensor_left.Setup();
  comms.RS485Comm_setup();
  comms.setCallback(&distribute); 
  Read->onRun(read);
	controll.add(Read);
} 

//Main Loop
void loop() {
    controll.run();
    if (millis() - SLOW_LOOP_PREV > SLOW_LOOP_T )
  {

    if(VERBOSE){
    MagneticSensor_right.Read();
    MagneticSensor_left.Read();
    Serial.print(MagneticSensor_right.x);
    Serial.print(",");Serial.print(MagneticSensor_right.y);
    Serial.print(",");Serial.print(MagneticSensor_right.z);    
    Serial.print(",");Serial.print(MagneticSensor_left.x);
    Serial.print(",");Serial.print(MagneticSensor_left.y);
    Serial.print(",");Serial.print(MagneticSensor_left.z); 
    Serial.println();
    }
    SLOW_LOOP_PREV=millis();

  }  

  //Fast Loop - 500-1KHz
  if (micros() - FAST_LOOP_PREV > FAST_LOOP_T )
  {
  grip.pidStep();
  FAST_LOOP_PREV=micros();
  }

  //Print Samplerate loop 1Hz
  if (millis() - previous>(1000))
  {
    sampleRate=sampleCount;
    previous=millis();
    // Serial.println(sampleRate);

    sampleCount=0;    
  }  
}


