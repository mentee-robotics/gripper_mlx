// MLX90393.cpp
#include "../include/MLX90393.h"

extern RS485Comm comms;
MLX90393::MLX90393() {
  x=0;
  y=0;
  z=0;
  _Addr=0x18;

}
void MLX90393::Setup() {

//i2c setup
  Wire1.begin();
  // Start I2C Transmission
  Wire1.beginTransmission(_Addr);
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
  Wire1.requestFrom(_Addr, 1);
  
  // Read status byte
  if(Wire1.available() == 1)
  {
  unsigned int c = Wire1.read();
  }
}
void MLX90393::Read() {
 
    
  // Start I2C Transmission
  Wire1.beginTransmission(_Addr);
  // Start single meaurement mode, ZYX enabled
  Wire1.write(0x3E);
  // Stop I2C Transmission
  Wire1.endTransmission();
  // Request 1 byte of data
  Wire1.requestFrom(_Addr, 1);
  // Read status byte
  if(Wire1.available() == 1)
  {
  unsigned int c = Wire1.read();
  }
  // Start I2C Transmission
  Wire1.beginTransmission(_Addr);
  // Send read measurement command, ZYX enabled
  Wire1.write(0x4E);
  // Stop I2C Transmission
  Wire1.endTransmission();
  // Request 7 bytes of data
  Wire1.requestFrom(_Addr, 7);
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
  x = data[1] * 256 + data[2];
  y = data[3] * 256 + data[4];
  z = data[5] * 256 + data[6];
}
void MLX90393::distribute(CommandFromHost i_command,SoftwareSerial *Serial){
  if(i_command._command==eGetMagField)
  {
  Read();
  int readings[3];
  ResponseToHost res;
  res._endpoint=eHost;
  res._response=eConfirm;
  res._payload_size = sizeof(int) * 3;
  readings[0]=x;
  readings[1]=y;
  readings[2]=z;
  memcpy(res._payload, (char*)readings, sizeof(int) * 3);
  comms.sendRes(res);
  }
}

