import abc
import serial
from abc import abstractmethod
from .Gripper import Gripper
from .Battery import Battery

class RS485_Module(abc.ABC):
    def __init__(self,serial,config) -> None:
      self.ser=serial
      self.config=config
      
    def create_module(self, name,node,frequency):
        module_config = self.config.get(name, None)
        if module_config is None:
            return None

        if module_config['type'] == 'Gripper':
            return Gripper(module_config['id'],self.ser,node,frequency)
        elif module_config['type'] == 'Battery':
            return Battery(module_config['id'],self.ser,node,frequency)
        else:
            pass
        
    @abstractmethod 
    def update(self): #Over serial
        "Update Gripper and battery data"
        
    @abstractmethod 
    def publish(self):#ROS
        "Publish Gripper and battery data to topics"
