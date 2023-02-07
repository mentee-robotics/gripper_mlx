#include "include/Gripper.h"
#include "include/MLX90393.h"
#define IN1 0
#define IN2 1
#define SLEEP 7
#define PMODE 9

#define VERBOSE true
#define Addr 0x0C


unsigned int sampleCount = 0;
unsigned long sampleRate = 0;

int previous=0;
int SLOW_LOOP_PREV=0;
int FAST_LOOP_PREV=0;

float SLOW_LOOP_T = 1000/5;
float FAST_LOOP_T = 500;

const byte value1 = 4; //rfh
char hostReceived[value1];
boolean rfhData = false;
int rfh = 0;
Gripper grip(IN1,IN2,SLEEP,PMODE);
MLX90393 MagneticSensor(Addr);

void setup() {
  Serial.begin(230400);
  MagneticSensor.Setup(Addr);
} 

//Main Loop
void loop() {

//Communicationloop - 30Hz
  if (millis() - SLOW_LOOP_PREV > SLOW_LOOP_T )
  {
    MagneticSensor.Read();
    if(VERBOSE){
    Serial.print("  Mlx_x ");Serial.print(MagneticSensor.x);
    Serial.print("  Mlx_y ");Serial.print(MagneticSensor.y);
    Serial.print("  Mlx_z ");Serial.print(MagneticSensor.z);    
    Serial.print("  Act_Pos ");Serial.print(grip.ActualPosition);
    Serial.print("  Targ_Pos ");Serial.print(grip.targetPosition);
   Serial.print("  Current ");Serial.println(analogRead(A1));

    }
    SLOW_LOOP_PREV=millis();
  }  
  
  //Fast Loop - 500-1KHz
  if (micros() - FAST_LOOP_PREV > FAST_LOOP_T )
  {
  ReadFromHost();
  grip.pidStep();
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

void ReadFromHost()
{
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    if (Serial.available() > 0) 
    { 

        rc = Serial.read();
        if (rc != endMarker) 
        {
          hostReceived[ndx] = rc;
          ndx++;
          if (ndx >= value1) 
          {
              ndx = value1 - 1;
          }
        }
        else 
        {
          hostReceived[ndx] = '\0'; 
          ndx = 0;
          rfhData = true;
        }
    }  
    if (rfhData == true) 
    {
        rfh = 0;             
        rfh = atoi(hostReceived);   
        grip.targetPosition = rfh;
        rfhData = false;
        Serial.println(rfh);
        Serial.println("*****************************");
    }
}

