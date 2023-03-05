#ifndef RS485Comm_h
#define RS485Comm_h

#include "../include/Configuration.h"


class RS485Comm {
    public:
    RS485Comm(SoftwareSerial *Serial);
    void prepare_transmit();
    void prepare_receive();
    void RS485Comm_setup();
    void create_and_send_packet(int actual_pos , float current , int mlx_x , int mlx_y , int mlx_z);
    void floatToBytes(float num, byte *bytes_array);
    int count_ones(byte array[], int length);
    void ReadFromHost();
    void sendRes(ResponseToHost res);
    void setCallback(std::function<void(CommandFromHost)> i_callback){
        _distribute_callback = i_callback;
    }
    SoftwareSerial *mySerial;
    float current;
    int wanted_pos;
    int actual_pos;
    int mlx_x;
    int mlx_y;
    int mlx_z;

    int counter = 1;
    bool normal_message = false;
    char last_rc;
    
    private:

    std::function<void(CommandFromHost)> _distribute_callback;


    byte message_array[16];
    byte current_array[4];
    byte packet_header{0b11001000};
    byte tail{0b11000111};
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
    int device_address = 1;
    char endMarker = '\n';
    int byte_header = 170;
    int hostReceived[4];

    float WAIT_BETWEEN_SNR = 3;


  

};
#endif