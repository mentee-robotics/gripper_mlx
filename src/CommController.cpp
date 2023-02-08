#include "../include/CommController.h"
#include <SoftwareSerial.h>
#include <cstddef>

RS485Comm::RS485Comm(){
    // mySerial->begin(115200);
    ofekSerial.begin(115200);
    pinMode(RE, OUTPUT);
    pinMode(DE, OUTPUT);
    // digitalWrite(DE, LOW); // Disable RS485 transmission
    // digitalWrite(RE, LOW);
    prepare_receive();
}

// void RS485Comm::RS485Comm_setup(int RE , int DE){
//     mySerial.begin(115200);
//     pinMode(RE, OUTPUT);
//     pinMode(DE, OUTPUT);
//     digitalWrite(DE, LOW); // Disable RS485 transmission
//     digitalWrite(RE, LOW);
// }

void RS485Comm:: prepare_transmit() {
    digitalWrite(DE, HIGH); 
    digitalWrite(RE, HIGH);
}

void RS485Comm::prepare_receive() {
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

    ofekSerial.write(message_array, 16);
    ofekSerial.flush();
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
    static byte ndx = 0;
    static int counter = 1;
    static bool normal_message = false;
    char endMarker = '\n';
    byte byte_rc;
    int rc;
    int address;
    int wanted_pos;
    static char last_rc;
    int byte_header = 170;
    if (ofekSerial.available()) 
    { 
        byte_rc = ofekSerial.read();
    if (byte_rc != 0) {       //bandage
        Serial.println(byte_rc);
        if (byte_rc == byte_header) {
            hostReceived[0] = byte_rc;
            normal_message = true;
        }
        if (normal_message == true) {
            hostReceived[counter] = byte_rc;
            counter ++;
        }
        if (counter >= 4) {
            address = hostReceived[1];
            if (address == device_address) {
                wanted_pos = hostReceived[2];
            }
            
            normal_message = false;
            counter = 0;
            last_received = millis();
            sthData = true;
        }
    }
    

    }
    if(sthData == true){
        if(millis() - last_received > WAIT_BETWEEN_SNR){
            sthData = false;
            create_and_send_packet(actual_pos ,  current ,  mlx_x ,  mlx_y ,  mlx_z);
            ofekSerial.flush();
    }
    }
    return wanted_pos;
}

