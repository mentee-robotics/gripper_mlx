#ifndef RS485Comm_h
#define RS485Comm_h
#include "../include/SoftwareSerial.h"
#include <Arduino.h>

#include <cstddef>

class RS485Comm {
    public:

    RS485Comm();
    void prepare_transmit();
    void prepare_receive();
    // void RS485Comm_setup(int RE , int DE);
    void create_and_send_packet(int actual_pos , float current , int mlx_x , int mlx_y , int mlx_z);
    void floatToBytes(float num, byte *bytes_array);
    int count_ones(byte array[], int length);
    int ReadFromHost();
    int RE = 6;
    int DE = 7;
    int Rx;
    int Tx;
    float current;
    int wanted_pos;
    int actual_pos;
    int mlx_x;
    int mlx_y;
    int mlx_z;
    uint8_t rx_pin = 9;
    uint8_t tx_pin = 8;
    int counter = 1;
    bool normal_message = false;
    char last_rc;
    
    private:
    SoftwareSerial _ofekSerial(7, 8);
    byte message_array[16];
    byte current_array[4];
    byte packet_header{0b11111111};
    byte tail{0b11111111};
    byte actual_pos1{};
    byte actual_pos2{};
    byte current_1{};
    byte current_2{};
    byte current_3{};
    byte current_4{};
    byte mlx_x1{};
    byte mlx_x2{};
    byte mlx_y1{};
    byte mlx_y2{};
    byte mlx_z1{};
    byte mlx_z2{};
    byte crc_1{};
    byte crc_2{};
    int checksum;
    char rs485_message;

    byte byte_rc{};
    char rc;
    int address;
    const int device_address = 1;
    char endMarker = '\n';
    int byte_header = 170;
    int hostReceived[4];
    bool rfhData = false;
    int rfh = 0;
    float WAIT_BETWEEN_SNR = 5;
    unsigned long last_received;
    bool sthData = false;

  

};
#endif