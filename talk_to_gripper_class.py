import serial
import time
import struct
import zlib
import Jetson.GPIO as GPIO


class TalkToGripper:
    
    def __init__(self):
        
        self.gripper = serial.Serial(port = '/dev/ttyTHS0' , baudrate= 115200, timeout=1)

        
        ######### pin setup #########
        self.rs485_DE_enable_pin = 12
        self.rs485_RE_enable_pin = 13
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.rs485_DE_enable_pin,GPIO.OUT) 
        GPIO.setup(self.rs485_RE_enable_pin,GPIO.OUT)
        #############################
        
        ######### send message #########
        self.message_to_send = bytearray(4)
        self.header = b'\xAA'
        self.tail = b'\x0A'
        self.right_gripper_address = 1
        self.left_gripper_address = 2
        #############################
        
        
        ######### receive message ######
        self.received_message = []
        self.expected_header = 0b11111111
        self.expected_tail = b'\x0A'
        
        self.mlx_x = 0
        self.mlx_y = 0
        self.mlx_z = 0
        self.actual_pos = 0
        self.current = 0
        ###############################
        
        
    def go_to(self, wanted_gripper ,wanted_position):
        if wanted_gripper == "right":
            address = self.right_gripper_address
        if wanted_gripper == "left":
            address = self.left_gripper_address
        
        
        self.message_to_send[0] = self.header
        self.message_to_send[1] = address
        self.message_to_send[2] = wanted_position
        self.message_to_send[3] = self.tail
  
        
    def send_data(self):
        
        GPIO.output(self.rs485_DE_enable_pin,GPIO.HIGH)
        GPIO.output(self.rs485_RE_enable_pin,GPIO.HIGH)
        
        self.gripper.write(self.message_to_send)
        self.gripper.flush()
        
        #after the gripper receives the message he will send a message back
        self.receive_data()
   
        
    def receive_data(self):
        
        GPIO.output(self.rs485_DE_enable_pin,GPIO.LOW)
        GPIO.output(self.rs485_RE_enable_pin,GPIO.LOW)
        
        get_data = self.gripper.read_until(expected="0x0a")
        self.received_message = get_data[1:19]   # the script reads the RE/DE HIGH/LOW changes as  bytes. this how we remove them

        # extracting data from the raw message:
        self.process_data()
        
        
    def process_data(self):
        data = self.received_message
        if len(data) > 17:
        
            byte_header = data[0]
            byte_actual_pos = [data[1],data[2]]
            byte_current = [data[6],data[5],data[4],data[3]]
            byte_mlx_X = [data[7],data[8]]
            byte_mlx_y = [data[9],data[10]]
            byte_mlx_z = [data[11],data[12]]
            byte_crc = [data[13],data[14],data[15],data[16]]
            byte_tail = data[17]

            actual_pos = struct.unpack('>h', bytes(byte_actual_pos))[0]
            current = struct.unpack('>f', bytes(byte_current))[0]
            mlx_x = struct.unpack('>h', bytes(byte_mlx_X))[0]
            mlx_y = struct.unpack('>h', bytes(byte_mlx_y))[0]
            mlx_z = struct.unpack('>h', bytes(byte_mlx_z))[0]
            crc = struct.unpack('>i', bytes(byte_crc))[0]

            # find the crc of the message
            data_without_crc = bytes([data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11],data[12]])
            calculated_crc = self.calculate_crc(data_without_crc)
            
            # check integrity of message by comparing header, tail and crc:
            message_integrity = self.check_message_integrity(byte_header, byte_tail, crc , calculated_crc)
            
            if message_integrity:
                self.mlx_x = mlx_x
                self.mlx_y = mlx_y
                self.mlx_z = mlx_z
                self.actual_pos = actual_pos
                self.current = current
            
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
    
    
    def get_data(self)    # returns a list of data
        data = [self.actual_pos , self.current , self.mlx_x , self.mlx_y , self.mlx_z]
        return data
        