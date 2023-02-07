#include "CommController.h"
#include <SoftwareSerial.h>
#include "Arduino.h"


    RS485Comm::RS485Comm(int RE , int DE, int Rx , int Tx) {
        softwareSerial mySerial(Rx , Tx)
        mySerial.begin(115200);
        pinMode(RE, OUTPUT);
        pinMode(DE, OUTPUT);
        digitalWrite(DE, LOW); // Disable RS485 transmission
        digitalWrite(RE, LOW);
    }

    RS485Comm::void prepare_transmit() {
        digitalWrite(DE, HIGH); 
        digitalWrite(RE, HIGH);
    }

    RS485Comm::void prepare_receive() {
        digitalWrite(DE, LOW); 
        digitalWrite(RE, LOW);
    }


    RS485Comm::void create_and_send_packet(int actual_pos , float current , int mlx_x , int mlx_y , int mlx_z) {
        prepare_transmit()
        
        actual_pos1 = (actual_pos >> 8);
        actual_pos2 = (actual_pos);
        floatToBytes(current, current_array);
        current_1 = current_array[0];
        current_2 = current_array[1];
        current_3 = current_array[2];
        current_4 = current_array[3];

        mlx_x1 = (mlx_x >> 8);
        mlx_x2 = (mlx_x);
        mlx_y1 = (mlx_y >> 8);
        mlx_y2 = (mlx_y);
        mlx_z1 = (mlx_z >> 8);
        mlx_z2 = (mlx_z);

        message_array[0] = packet_header;
        message_array[1] = actual_pos1;
        message_array[2] = actual_pos2;
        message_array[3] = current_1;
        message_array[4] = current_2;
        message_array[5] = current_3;
        message_array[6] = current_4;
        message_array[7] = mlx_x1;
        message_array[8] = mlx_x2;
        message_array[9] = mlx_y1;
        message_array[10] = mlx_y2;
        message_array[11] = mlx_z1;
        message_array[12] = mlx_z2;

        checksum = count_ones(message_array, 13);

        crc_1 = (checksum >>8);
        crc_2 = (checksum);

        message_array[13] = crc_1;
        message_array[14] = crc_2;
        message_array[15] = tail;

        mySerial.write(message_array, 16);
        mySerial.flush();
        prepare_receive()
    }

    RS485Comm::void floatToBytes(float num, byte *bytes_array) {
        // Converts a float into an array of 4 bytes
        union {
            float float_variable;
            byte temp_array[4];
        } u;
    
        u.float_variable = num;
    
        for (int i = 0; i < 4; i++) {
            bytes_array[i] = u.temp_array[i];
        }
    }


    RS485Comm::int count_ones(byte array[], int length) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            byte currentByte = array[i];
            for (int j = 0; j < 8; j++) {
            count += (currentByte & 0x01);
            currentByte >>= 1;
            }
        }
        return count;
    }

    RS485Comm::int read_from_buffer() {


        return pos
    }

