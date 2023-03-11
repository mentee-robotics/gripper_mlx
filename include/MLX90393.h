#ifndef MLX90393_h
#define MLX90393_h

#include "../include/Configuration.h"
#include "../include/CommController.h"

class MLX90393 {
  public:
    MLX90393( unsigned char adr);
    void Read();
    void Setup();
    void distribute(CommandFromHost i_command,SoftwareSerial *Serial);
    int x; 
    int y; 
    int z;
    unsigned char _Addr;
  private:
    unsigned int data[7];
};

#endif