
#include <Wire.h>
#include <ADS1115_WE.h> 
#include <SoftwareSerial.h>
#define I2C_ADDRESS 0x48
#define Kp 0.3
#define Ki 0
#define Kd 0.4
#define IN1 6
#define IN2 7
#define SLEEP 4
// MLX90393 I2C Address is 0x0C(12)
#define Addr 0x0C 
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;

const long interval = 5;
const long interval2 = 15;

const byte rxPin = 9;
const byte txPin = 8;
SoftwareSerial mySerial (rxPin, txPin);
float voltage=0;
int targetPosition = 0;  
long ActualPosition = 0;    // current position in encoder pulses
long error = 0;             // error between current and target positions
long lastError = 0;         // previous error value
long integral = 0;          // integral of error over time
long derivative = 0;        // derivative of error over time
long output = 0;            // output value to control motor
unsigned long time_us;
unsigned long startTime;
double Setpoint, Input, Output;
int dir;
float temp;
int once;
float firstVoltage=0;
float position;
int xMag=0;
int yMag=0;
int zMag=0;
int first_xMag;
int first_yMag;
int first_zMag;
float current=0;
long val;
char recieve[4];
char aMessage[200];                               // to hold the message received
char cha;        
String input;
                                 // for reading char one at a time
byte messageSize;
ADS1115_WE adc = ADS1115_WE(I2C_ADDRESS);


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(SLEEP,OUTPUT);
  digitalWrite(SLEEP,LOW);
  Wire.begin();
  Wire1.begin();
  Serial.begin(230400);
  mySerial.begin(230400);
  adc.setVoltageRange_mV(ADS1115_RANGE_6144);
  adc.setConvRate(ADS1115_860_SPS);
  adc.setMeasureMode(ADS1115_CONTINUOUS);
  targetPosition=map(analogRead(A0),1,1019,0,1000);
  dir=-1;
  digitalWrite(SLEEP,HIGH);
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
  
  // Start I2C Transmission
  Wire1.beginTransmission(Addr);
  // Select Write register command
  Wire1.write(0x60);
  // Set AH = 0x02
  Wire1.write(0x02);
  // Set AL = 0xB4, RES for magnetic measurement = 0
  Wire1.write(0xB4);
  // Select address register, (0x02 << 2)
  Wire1.write(0x08);
  // Stop I2C Transmission
  Wire1.endTransmission();
  
  // Request 1 byte of data
  Wire1.requestFrom(Addr, 1);
  
  // Read status byte
  if(Wire1.available() == 1)
  {
  unsigned int c = Wire1.read();
  }
  
  once=0;
} 
float readChannel(ADS1115_MUX channel) {
  float voltage = 0.00000;
  adc.setCompareChannels(channel);
  voltage = adc.getResult_V(); // alternative: getResult_mV for Millivolt
  return voltage;
}
void setMotor(int dir, int pwmVal, int in1, int in2){

  if(output==0)
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }
  else
  {
  if(dir == -1){
    //analogWrite(in1,pwmVal);
    analogWrite(in1,pwmVal);
    digitalWrite(in2,LOW);
  }
  else if(dir == 1){
    //analogWrite(in2,pwmVal);
    digitalWrite(in1,LOW);
    analogWrite(in2,pwmVal);
    }
  }
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
  if (millis() - startTime >1000 && millis() - startTime < 3000 && once<1) {  // Check if 100 milliseconds have elapsed
    first_xMag=xMag;
    first_yMag=yMag;
    first_zMag=zMag;
    firstVoltage=readChannel(ADS1115_COMP_0_GND);
    once++;
  }
//   if (millis() - previousMillis >= interval && mySerial.available()) {
//     previousMillis = millis();
//         Serial.println("in");

//     String input = mySerial.readString();
//     int x = input.toInt();
//     Serial.println(x);
        
//     targetPosition=val;
//   }
//  if (millis() - previousMillis2 >= interval2 ) {
//     previousMillis2 = millis();
//     ActualPosition=mapfloat(readChannel(ADS1115_COMP_0_GND)*1000,2077,1359,0,1000);
//   }


  targetPosition=mapfloat(readChannel(ADS1115_COMP_0_GND),0,3.3,0,1000);
  ActualPosition=mapfloat(readChannel(ADS1115_COMP_3_GND)*1000,2100,1385,0,1000);

  // calculate the error between the current and target positions
  error = targetPosition - ActualPosition;
  // update the integral and derivative terms
  integral += error;
  derivative = error - lastError;
  lastError = error;
  // calculate the output value using the PID equation
  output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  // wait a short time before repeating the loop
  // Set the motor output
  if(output>=0)
  {
    dir=-1;
  }
  else{
    dir=1;
  }
  if(output>=255)
  {
    output=255;
  }
  if(output<=-255)
  {
    output=-255;
  }
  setMotor(dir, abs(output), IN1, IN2);
  voltage=readChannel(ADS1115_COMP_1_GND);
  current=(firstVoltage-voltage)*0.2;
  position=readChannel(ADS1115_COMP_3_GND);
  current=map(current*1000,0,3000,0,1000);
  position=map(position*1000,2077,1359,0,1000);
  Serial.print(current);
  Serial.print(",");
  Serial.print(ActualPosition);
  Serial.print(",");  

  unsigned int data[7];
  unsigned int data_x;
  unsigned int data_y;
  unsigned int data_z;
 
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
  //Serial.print(",");  
  // Serial.print(",");
  // Serial.print(ActualPosition);
  Serial.println();

}


