import rclpy
from rclpy.node import Node
import time
import yaml
from .Gripper import Gripper
from .Battery import Battery
import serial
import Jetson.GPIO as GPIO
from .RS485_Module import RS485_Module

YAML_PATH="/home/nir/code/gripper_mlx/Bat_and_grip/rs485.yaml"

class rs485(Node):
    def __init__(self):
        super().__init__('rs485')

        self.initSerial()
        
        self.rs485 = RS485_Module(self.config)
        self.freq= self.config["communication"]["frequency"]
        # Create instances of gripper and battery
        self.modules = {}
        for name in self.config.keys():
            module = self.rs485.create_module(name,self)
            if module is not None:
                self.modules[name] = module
                
       
        # Start main loop
        self.timer = self.create_timer(1/self.freq, self.main_loop)
        
    def initSerial(self):
        if not self.ser.open():
                self.config=self.Read_YAML(YAML_PATH)
                ######### pin setup #########
                self.rs485_DE_enable_pin = self.config["communication"]["DE_pin"]
                self.rs485_RE_enable_pin = self.config["communication"]["RE_pin"]
                
                self.ser=serial.Serial(
                    port=self.config["communication"]["serial_port"],
                    baudrate=self.config["communication"]["baudrate"],
                    timeout=self.config["communication"]["timeout"],
                    bytesize = serial.EIGHTBITS,
                    parity = serial.PARITY_NONE,
                    stopbits = serial.STOPBITS_ONE, 
                    xonxoff = self.config["communication"]["software_flow_control"],   
                    rtscts = self.config["communication"]["clear_to_send"],
                    dsrdtr = self.config["communication"]["data_terminal_ready"],       
                    writeTimeout = self.config["communication"]["writeTimeout"]             
                )
                GPIO.setmode(GPIO.BCM)
                GPIO.setup(self.rs485_DE_enable_pin,GPIO.OUT) 
                GPIO.setup(self.rs485_RE_enable_pin,GPIO.OUT)
                #############################
                self.ser.open()


    def Read_YAML(self,path):
        with open(path,'r') as file:
            config=yaml.safe_load(file)
            return config

    def main_loop(self):    
        for module in self.modules.items():
            module.update()
            module.publish()


def main(args=None):
    rclpy.init(args=args)
    node = rs485()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()