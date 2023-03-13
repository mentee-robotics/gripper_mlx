from .RS485_Module import RS485_Module
import rclpy
import serial
import time
import struct
import zlib
import Jetson.GPIO as GPIO
import random
from std_msgs.msg import String, Int32
from rs485.msg import GripperStatus

class Gripper(RS485_Module):
    def __init__(self,id,serial,node):
        super().__init__(id,serial,node)
        self.id=id
        self.ser=serial
        self.node=node
        
        ######### send message #########
        self.message_to_send = bytearray(4)
        self.header = b'\xAA'
        self.tail = b'\n'
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

        ######### Publisher+Subscriber ######
        if id==self.right_gripper_address:
            grip="right"
        elif id==self.left_gripper_address:
            grip="left"
        else:
            print("id doesn't match right/left grippers")
        self.publisher=self.node.create_publisher(GripperStatus,'/rs485/gripper/'+grip+'/status/',10)
        self.subscriber=self.node.create_subscription(Int32,'/rs485/gripper/'+str(id)+'/'+grip+'/targetPos/',self.gripper_command_callback,10)

        
        #####################################

    def update(self):
        self.message_to_send[0] = self.header[0]
        self.message_to_send[1] = (self.int_to_bytes(self.id))[0]
        self.message_to_send[2] = (self.int_to_bytes(self.target_pos))[0]
        self.message_to_send[3] = self.tail[0]
        self.send_data()
        
    def int_to_bytes(self, value):
        return bytes(chr(value), 'utf-8')
        
    def send_data(self):
        GPIO.output(self.rs485_DE_enable_pin,GPIO.HIGH)
        GPIO.output(self.rs485_RE_enable_pin,GPIO.HIGH)
        self.gripper.write(self.message_to_send)
        time.sleep(0.001)
        GPIO.output(self.rs485_DE_enable_pin,GPIO.LOW)
        # GPIO.output(self.rs485_RE_enable_pin,GPIO.LOW)  
        self.receive_data()
     
    def receive_data(self):
        get_data = self.gripper.read_until(expected="0x0a")
        self.received_message = get_data   
        # extracting data from the raw message:
        self.process_data()
        
    def process_data(self):
        data = self.received_message
        if len(data) > 15:
            byte_header = data[0]
            byte_actual_pos = [data[1],data[2]]
            byte_current = [data[6],data[5],data[4],data[3]]
            byte_mlx_X = [data[7],data[8]]
            byte_mlx_y = [data[9],data[10]]
            byte_mlx_z = [data[11],data[12]]
            byte_crc = [data[13],data[14]]
            byte_tail = data[15]
            actual_pos = struct.unpack('>h', bytes(byte_actual_pos))[0]
            current = struct.unpack('>f', bytes(byte_current))[0]
            mlx_x = struct.unpack('>h', bytes(byte_mlx_X))[0]
            mlx_y = struct.unpack('>h', bytes(byte_mlx_y))[0]
            mlx_z = struct.unpack('>h', bytes(byte_mlx_z))[0]
            crc = struct.unpack('>h', bytes(byte_crc))[0]
            # find the crc of the message
            data_without_crc = bytes([data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11],data[12]])
            calculated_crc = self.calculate_crc(data_without_crc)
            # check integrity of message by comparing header, tail and crc:
            # message_integrity = self.check_message_integrity(byte_header, byte_tail, crc , calculated_crc)#Not Working
            
            # if message_integrity:
            self.mlx_x = mlx_x
            self.mlx_y = mlx_y
            self.mlx_z = mlx_z
            self.actual_pos = actual_pos
            self.current = current
                
            print(f"current: {current} actual_pos: {actual_pos} mlx-x {mlx_x} mlx-y {mlx_y} mlx-z {mlx_z}")

            
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
    
        
    def gripper_command_callback(self, pos):
        self.target_pos=pos

    def publish(self):
        msg = GripperStatus()
        msg.id = self.id
        msg.position = self.actual_pos
        msg.current = self.current
        msg.xmag=self.mlx_x
        msg.ymag=self.mlx_y
        msg.zmag=self.mlx_z
        self.publisher.publish(msg)
        # self.get_logger().info('Publishing: "%s"' % msg.data)
