#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#include <cstddef>
#include <Arduino.h>
#include <Wire.h>
#include <functional>
#include <SoftwareSerial.h>
#include <FreeRTOS.h>
#include <task.h>
#include "../include/Pinout.h"
#include <string>
#include <memory>

#define VERBOSE false

#define EMA  0.1 //Current Sensing - > Motor Controller

#define SLOW_LOOP_T 1000/30 //millies
#define FAST_LOOP_T  500  //micros

enum eResponse{
    eConfirm,
    eData,
    eError,
};
enum eEndpoints{
    eGripper,
    eHost,
    eMLX,
};

enum eCommands{
    //Common Commands
    eEnable,
    eDisable,
    eReset,
    eCalibrate,

    //MLX Commands
    eGetMagField,

    //Gripper Commands
    eMoveToPos,
    eGetPos,
    eGetCurrent,

};
class CommandFromHost{
    public:

    CommandFromHost(){};
    ~CommandFromHost(){
    }
    eEndpoints _endpoint;
    eCommands _command;
    char _payload[20];
    int _payload_size;
};

class ResponseToHost{
   public:

   ResponseToHost(){};
    ~ResponseToHost(){
    }
    eEndpoints _endpoint;
    eResponse _response;
    char _payload[20];
    int _payload_size;
};

#endif