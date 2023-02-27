#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#include <cstddef>
#include <Arduino.h>
#include <Wire.h>
#include <functional>
#include <thread>
#include <SoftwareSerial.h>
#include "../include/Pinout.h"

#define VERBOSE false

#define EMA  0.1 //Current Sensing - > Motor Controller

#define SLOW_LOOP_T 1000/40 //millies
#define FAST_LOOP_T  500  //micros

enum eResponse{
    eConfirm,
    eData,
    eError,
};
enum eEndpoints{
    eGripper,
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

    CommandFromHost():_payload(nullptr){};
    ~CommandFromHost(){
        if(_payload)
            delete(_payload);
    }
    eEndpoints _endpoint;
    eCommands _command;
    char *_payload;
    int _payload_size;
};

class ResponseToHost{
   public:

   ResponseToHost():_payload(nullptr){};
    ~ResponseToHost(){
        if(_payload)
            delete(_payload);
    }
    eEndpoints _endpoint;
    eResponse _response;
    char *_payload;
    int _payload_size;
};

#endif