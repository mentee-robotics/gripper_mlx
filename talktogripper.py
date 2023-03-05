import serial
import time
import struct
import zlib
import Jetson.GPIO as GPIO
import random
from sys import getsizeof
import sys
from enum import Enum

class eResponse(Enum):
    eConfirm = 0
    eData = 1
    eError = 2

class eEndpoints(Enum):
    eGrippe =0
    eMLX=1

class eCommands(Enum):
     #Common Commands
    eEnable=0
    eDisable=1
    eReset=2
    eCalibrate=3

    #MLX Commands
    eGetMagField=4

    #Gripper Commands
    eMoveToPos=5
    eGetPos=6
    eGetCurrent=7


class TalkToGripper:
    
    def __init__(self,serial):
        
        self.ser = serial
        ######### pin setup #########
        self.rs485_DE_enable_pin = 12
        self.rs485_RE_enable_pin = 13
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.rs485_DE_enable_pin,GPIO.OUT) 
        GPIO.setup(self.rs485_RE_enable_pin,GPIO.OUT)
        #############################
        
        ######### send message #########
        self.message_to_send = bytearray(8)
        self.header = b'\xAA'
        self.tail = b'\n'
        self.right_gripper_address = 1
        self.left_gripper_address = 2
        ######### recieve message #########

        self.received_message = []
        self.expected_header = 255
        self.expected_tail = 199
        
        self.mlx_x = 0
        self.mlx_y = 0
        self.mlx_z = 0
        self.actual_pos = 0
        self.current = 0
        ###############################
        
        
    def go_to(self, wanted_gripper ,wanted_position):
        self.wanted=wanted_gripper
        if wanted_gripper == "right":
            address = self.right_gripper_address
        if wanted_gripper == "left":
            address = self.left_gripper_address
    
        self.message_to_send[0] = self.header[0]
        self.message_to_send[1] = self.header[0]
        self.message_to_send[2] = (self.int_to_bytes(address))[0]
        self.message_to_send[3] = (self.int_to_bytes(0))[0]
        self.message_to_send[4] = (self.int_to_bytes(5))[0]
        self.message_to_send[5] = (self.int_to_bytes(4))[0]
        self.message_to_send[6] = (wanted_position.to_bytes(4,sys.byteorder))[0]
        self.message_to_send[7] = (self.int_to_bytes(99))[0]
        self.send_data()
  
    def int_to_bytes(self, value):
        return bytes(chr(value), 'utf-8')
        
    def send_data(self):
        GPIO.output(self.rs485_DE_enable_pin,GPIO.HIGH)
        GPIO.output(self.rs485_RE_enable_pin,GPIO.HIGH)
        self.ser.write(self.message_to_send)

        
    def receive_data(self):
        GPIO.output(self.rs485_DE_enable_pin,GPIO.LOW)
        # GPIO.output(self.rs485_RE_enable_pin,GPIO.LOW)
        dat=[]
        k=0
        while k<2:
            value = self.ser.read()
            value = int.from_bytes(value, byteorder='big')
            if value==200:
                k+=1
            else:
                k=0
            time.sleep(0.001)
        dat.append(value)
        dat.append(value)
        while value!=199:
            value=self.ser.read()
            value = int.from_bytes(value, byteorder='big') 
            dat.append(value)
        self.received_message=dat
        self.process_data()
        
        
    def process_data(self):
        data = self.received_message
        if len(data) >=12:
            byte_header1 = data[0]
            byte_header2 = data[1]
            endpoint= data[2] 
            reponse=data[3]
            payload_size=data[4]
            payload=data[5:5+payload_size]
            crc1=data[5+payload_size]
            crc2=data[6+payload_size]
            tail=data[7+payload_size]
            print(data)
           
    def calculate_crc(self, byte_list):  # counting the ones in the byte array
        count = 0
        for byte in byte_list:
            binary = bin(byte)[2:]
            count += binary.count("1")
        return count
    
    def check_message_integrity(self, header, tail, received_crc, calculated_crc):   #make sure the message arrived with no errors
        integrity = True
        if header != self.expected_header:
            integrity = False
        
        if header == self.expected_header:
            integrity = False
            
        if received_crc == calculated_crc:
            integrity = False
            
        return integrity
    
    
    def get_data(self):   # returns a list of data
        data = [self.actual_pos , self.current , self.mlx_x , self.mlx_y , self.mlx_z]
        return data
    
    
if __name__ == '__main__':
    ser=serial.Serial(port = '/dev/ttyTHS0' , baudrate= 115200, timeout=0.001)

    gripper_right = TalkToGripper(ser)

        
    tar_pos = 50
    freq = 30
    i=0
    while True:
        gripper_right.go_to(wanted_gripper="right",wanted_position=random.randint(0,100))
        time.sleep(0.001)
        gripper_right.receive_data() 

