#include "../include/CommController.h"

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
    // mySerial->flush();
    digitalWrite(DE, HIGH); 
    digitalWrite(RE, HIGH);
}

void RS485Comm::prepare_receive() {
    mySerial->flush();
    digitalWrite(DE, LOW); 
    digitalWrite(RE, LOW);
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

void RS485Comm::ReadFromHost() {
    byte byte_rc;
    int i=0;
    while(i<2)
    {
        byte_rc = mySerial->read();
        // Serial.println(byte_rc);
        if(byte_rc ==170)
        {    
            i++;
        }
        else{
            if(byte_rc!=0)
                i=0;
        }
        delay(1);
    }
    CommandFromHost new_command;
    if (mySerial->available()>=6)
    {
        byte address=mySerial->read();
        // Serial.print(address);Serial.print(",");
        new_command._endpoint=(eEndpoints)mySerial->read();
        // Serial.print(new_command._endpoint);Serial.print(",");
        new_command._command=(eCommands)mySerial->read();
        // Serial.print(new_command._command);Serial.print(",");
        new_command._payload_size=(int)mySerial->read();
        // Serial.print(new_command._payload_size);Serial.print(",");
        byte payload=mySerial->read();
        new_command._payload[0]=payload;
        // Serial.print((uint8_t)payload);Serial.print(",");
        char tail=mySerial->read();
        // Serial.print((int)tail);Serial.println();

    if ((tail)!=99 || (address)!=device_address)
    {
        return;
    }
    _distribute_callback(new_command);   
    }
    }

void RS485Comm:: sendRes(ResponseToHost res)
{    
    delay(3);

    prepare_transmit();

    message_array[0]=packet_header;
    message_array[1]=packet_header;
    message_array[2]=res._endpoint;
    message_array[3]=res._response;
    message_array[4]=res._payload_size;
    memcpy(&(message_array[5]), res._payload, res._payload_size);
   
    checksum = count_ones(message_array, 5+res._payload_size);

    crc_1 = (checksum >>8);
    crc_2 = (checksum);

    message_array[5+res._payload_size] = crc_1;
    message_array[6+res._payload_size] = crc_2;
    message_array[7+res._payload_size] = tail;
    

    mySerial->write(message_array, 8+res._payload_size);
    delay(1);
    prepare_receive();
}


