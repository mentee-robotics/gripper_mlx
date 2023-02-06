#include <Wire.h>

#define Kp 0.15
#define Ki 0.001
#define Kd 0
#define IN1 8
#define IN2 6
#define SLEEP 7
#define PMODE 9

#define VERBOSE true
// MLX90393 I2C Address is 0x0C(12)
#define Addr 0x0C

unsigned int sampleCount = 0;
unsigned long sampleRate = 0;

float voltage=0;
int targetPosition = 0; 
int ActualPosition = 0;    // current position in encoder pulses
int ActualPosition1 = 0;    // current position in encoder pulses
int ActualPosition2 = 0;    // current position in encoder pulses

long error = 0;             // error between current and target positions
long lastError = 0;         // previous error value
long integral = 0;          // integral of error over time
long derivative = 0;        // derivative of error over time
long output = 0;            // output value to control motor
unsigned long startTime;
int dir=-1;
int once=0;
float firstVoltage=0;
float position;
int xMag=0;
int yMag=0;
int zMag=0;
int first_xMag;
int first_yMag;
int first_zMag;
float current=0;

int previous=0;
int SLOW_LOOP_PREV=0;
int FAST_LOOP_PREV=0;

float SLOW_LOOP_T = 1000/5;
float FAST_LOOP_T = 500;


const byte value1 = 4; //rfh
char hostReceived[value1];
boolean rfhData = false;
int rfh = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(SLEEP,OUTPUT);
  pinMode(PMODE,OUTPUT);
  digitalWrite(SLEEP,HIGH);
  digitalWrite(PMODE,HIGH);
  Serial.begin(230400);

  //i2c setup
  Wire1.begin();
  // Start I2C Transmission
  Wire1.beginTransmission(Addr);
  // Select Write register command
  Wire1.write(0x60);
  // Set AH = 0x00, BIST disabled
  Wire1.write(0x00);
  // Set AL = 0x5C, Hall plate spinning rate = DEFAULT, GAIN_SEL = 5
  Wire1.write(0x5C);
  // Select address register, (0x00 << 2)
  Wire1.write(0x00);
  // Stop I2C Transmission
  Wire1.endTransmission();
  
  // Request 1 byte of data
  Wire1.requestFrom(Addr, 1);
  
  // Read status byte
  if(Wire1.available() == 1)
  {
  unsigned int c = Wire1.read();
  }

} 



//Main Loop
void loop() {
//first loop one time-zero bias error
  // if (millis() - startTime > 3000 && millis() - startTime < 5000 && once < 1) {  // Check if 100 milliseconds have elapsed
  //   first_xMag=xMag;
  //   first_yMag=yMag;
  //   first_zMag=zMag;
  //   firstVoltage=analogRead(A3);
  //   once++;
  // }

//Communicationloop - 30Hz
  if (millis() - SLOW_LOOP_PREV > SLOW_LOOP_T )
  {
    ReadMlx();
    if(VERBOSE){
    Serial.print("  Mlx_x ");Serial.print(xMag);
    Serial.print("  Mlx_y ");Serial.print(yMag);
    Serial.print("  Mlx_z ");Serial.print(zMag);    
    Serial.print("  Act_Pos ");Serial.print(ActualPosition);
    Serial.print("  Targ_Pos ");Serial.println(targetPosition);
    }
    // #endif
  //voltage=analogRead(A3);
  //  current=(voltage-firstVoltage);
    // targetPosition=mapfloat(analogRead(A1),0,1000,0,100);//analogRead(A2);
  // Serial.println(targetPosition);
    SLOW_LOOP_PREV=millis();
  }  
  
  //Fast Loop - 500-1KHz
  if (micros() - FAST_LOOP_PREV > FAST_LOOP_T )
  {
  ReadFromHost();
  pidStep(targetPosition);
  FAST_LOOP_PREV=micros();
  sampleCount++;
  }

  //Print Samplerate loop 1Hz
  if (millis() - previous>(1000))
  {
    sampleRate=sampleCount;
    previous=millis();
    // Serial.println(sampleCount);  
    // Serial.print(",");
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
        targetPosition = rfh;
        rfhData = false;
        Serial.println(rfh);
        Serial.println("*****************************");
    }
}

void pidStep(int targetPosition)
{
  ActualPosition=mapfloat(analogRead(A0),310,70,0,100);
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

  setMotor(dir,abs(output),IN1,IN2);    
}

void setMotor(int dir, int pwmVal, int in1, int in2){
  if(output==0){
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


float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void ReadMlx(){
  unsigned int data[7];
 
  // Start I2C Transmission
  Wire1.beginTransmission(Addr);
  // Start single meaurement mode, ZYX enabled
  Wire1.write(0x3E);
  // Stop I2C Transmission
  Wire1.endTransmission();
  // Request 1 byte of data
  Wire1.requestFrom(Addr, 1);
  // Read status byte
  if(Wire1.available() == 1)
  {
  unsigned int c = Wire1.read();
  }
  // Start I2C Transmission
  Wire1.beginTransmission(Addr);
  // Send read measurement command, ZYX enabled
  Wire1.write(0x4E);
  // Stop I2C Transmission
  Wire1.endTransmission();
  // Request 7 bytes of data
  Wire1.requestFrom(Addr, 7);
  // Read 7 bytes of data
  // status, xMag msb, xMag lsb, yMag msb, yMag lsb, zMag msb, zMag lsb
  if(Wire1.available() == 7);
  {
  data[0] = Wire1.read();
  data[1] = Wire1.read();
  data[2] = Wire1.read();
  data[3] = Wire1.read();
  data[4] = Wire1.read();
  data[5] = Wire1.read();
  data[6] = Wire1.read();
  }
  
  // Convert the data
  xMag = data[1] * 256 + data[2]-first_xMag;
  yMag = data[3] * 256 + data[4]-first_yMag;
  zMag = data[5] * 256 + data[6]-first_zMag;
  
  //Output data to serial monitor
  //Serial.print("Magnetic Field in X-Axis : ");
  Serial.print(map(xMag,-32768,32768,0,1000));
  Serial.print(",");
  // Serial.print("Magnetic Field in Y-Axis : ");
  Serial.print(map(yMag,-32768,32768,0,1000));
  Serial.print(",");
  // Serial.print("Magnetic Field in Z-Axis : ");
  Serial.print(map(zMag,-32768,32768,0,1000));
}
