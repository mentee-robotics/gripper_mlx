#include "../include/CommController.h"
#include "../include/Pinout.h"

RS485Comm::RS485Comm(SoftwareSerial *Serial){
    mySerial=Serial;
}

void RS485Comm::RS485Comm_setup(){
    mySerial->begin(115200);
    pinMode(RE, OUTPUT);
    pinMode(DE, OUTPUT);
    prepare_receive();
}

void RS485Comm:: prepare_transmit() {
        mySerial->flush();

    digitalWrite(DE, HIGH); 
    digitalWrite(RE, HIGH);

}

void RS485Comm::prepare_receive() {
        mySerial->flush();

    digitalWrite(DE, LOW); 
    digitalWrite(RE, LOW);

}


void RS485Comm::create_and_send_packet(int actual_pos , float current , int mlx_x , int mlx_y , int mlx_z) {
    prepare_transmit();
    // digitalWrite(DE, HIGH); 
    // digitalWrite(RE, HIGH);
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

    mySerial->write(message_array, 16);

    // digitalWrite(DE, LOW); 
    // digitalWrite(RE, LOW);
    prepare_receive();


}

void RS485Comm::floatToBytes(float num, byte *bytes_array) {
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


int RS485Comm::count_ones(byte array[], int length) {
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

int RS485Comm::ReadFromHost() {
    // static byte ndx = 0;
    // static int counter = 0;
    // static bool normal_message = false;
    // char endMarker = '\n';
    byte byte_rc;
    // int rc;
    int address;
    int i=0;
    // int byte_header = 170;
    // int byte_tail=10;
    if (mySerial->available()>=4) 
    { 
    byte_rc = mySerial->read();

        if(byte_rc ==170){
        hostReceived[i]= byte_rc;
        // Serial.println(byte_rc);    
        while(byte_rc!=10)
            {
                i++;
                byte_rc = mySerial->read();
                // Serial.println(byte_rc);    
                hostReceived[i] = byte_rc;
            }
            address = hostReceived[1];
            if (address == device_address) {
                 wanted_pos = hostReceived[2];
             }
                    
            }
    }
        if(i == 3){
            delay(3);
            create_and_send_packet(actual_pos ,  current ,  mlx_x ,  mlx_y ,  mlx_z);
        }

    return wanted_pos;
}

