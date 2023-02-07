#ifndef RS485Comm_h
#define RS485Comm_h
#include <SoftwareSerial.h>

class RS485Comm {
    private:
        
        SoftwareSerial mySerial;
        byte message_array[16];
        byte current_array[4];
        byte packet_header = 0b11111111;
        byte tail = 0b11111111;
        byte actual_pos1;
        byte actual_pos2;
        byte current_1;
        byte current_2;
        byte current_3;
        byte current_4;
        byte mlx_x1;
        byte mlx_x2;
        byte mlx_y1;
        byte mlx_y2;
        byte mlx_z1;
        byte mlx_z2;
        byte crc_1;
        byte crc_2;
        int checksum;
        float current;
        int actual_pos;
        int mlx_x;
        int mlx_y;
        int mlx_z;
        char rs485_message;

    public:

    RS485Comm(int RE , int DE, int Rx , int Tx);
    void prepare_transmit();
    void prepare_receive();
    void create_and_send_packet(int actual_pos , float current , int mlx_x , int mlx_y , int mlx_z);
    void floatToBytes(float num, byte *bytes_array);
    int count_ones(byte array[], int length);

