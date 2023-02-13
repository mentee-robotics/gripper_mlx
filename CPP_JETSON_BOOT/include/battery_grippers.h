#ifndef battery_grippers_h
#define battery_grippers_h

#include <vector>
#include <string>
#include <algorithm>
#include "SerialPort.h"

class main{
    public:
    boot(Battery B1,Gripper G1,Gripper G2);
    private:

};

class Battery {
public:
    ReadBattery();

    std::vector<int> read();
    std::string get_time();
    std::vector<int> read_data();
    std::vector<int> get_unsorted_data();
    std::vector<int> get_voltage();
    std::vector<int> get_current();
    std::vector<int> get_temperature();
    std::vector<int> get_capacitance();
    int get_crc();

private:
    SerialPort ser;
    std::string data;
};



class Gripper{
    public:
    Gripper();
    private:
};