from .RS485_Module import RS485_Module
from rs485.msg import BatteryStatus

class Battery(RS485_Module):
    def __init__(self,id,serial,node):
        super().__init__(id, serial,node)
        self.ser=serial
        self.id=id
        self.node=node
        self.right_battery_address = 4
        self.left_battery_address = 3
         ######### Publisher+Subscriber ######
        if id==self.right_battery_address:
            bat="right"
        elif id==self.left_battery_address:
            bat="left"
        else:
            print("id doesn't match right/left batteries")
        self.publisher=self.node.create_publisher(BatteryStatus,'/rs485/battery/'+str(id)+'/'+bat+'/status/',10)

        
        #####################################
    def read(self):
        self.ser.write(bytes(':000200000ee8~', encoding='utf-8'))
        message = self.ser.readline().decode()
        serial_data = message.split(':018252')
        self.data = serial_data[1]   #this is where the important data is stored
        data = self.read_data()
        return data

    def get_time(self):
        time = (self.data[4:18])
        return time

    def read_data(self):
        data_list = []
        self.vbat = int(self.data[18:22], 16) * 2
        self.soc = int(self.data[112:114], 16)
        temp_0 = int(self.data[58:60], 16)        
        temp_1 = int(self.data[60:62], 16)
        temp_2 = int(self.data[62:64], 16)
        temp_3 = int(self.data[64:66], 16)
        self.max_temp = max(temp_0, temp_1, temp_2 , temp_3)
        data_list.append(vbat)
        data_list.append(soc)
        data_list.append(self.max_temp)
        return (data_list)


    def get_unsorted_data(self):
        data_list = []
        length = int(self.data[:4])
        number_of_cells = int(self.data[22:24], 16)
        v_state = int(self.data[66:70], 16)
        c_state = int(self.data[70:74], 16)
        t_state = int(self.data[74:78], 16)
        alarm = int(self.data[78:82], 16)
        FET_state = int(self.data[82:84], 16)
        warn_vov = int(self.data[84:88], 16)
        warn_vuv = int(self.data[88:92], 16)
        num_warn_v_high = int(self.data[92:96], 16)
        num_warn_v_low = int(self.data[96:100], 16)
        balance_state = int(self.data[100:104], 16)
        discharge_num = int(self.data[104:108], 16)
        charge_num = int(self.data[108:112], 16)
        data_list.append(length)
        data_list.append(number_of_cells)
        data_list.append(v_state)
        data_list.append(c_state)
        data_list.append(t_state)
        data_list.append(alarm)
        data_list.append(FET_state)
        data_list.append(warn_vov)
        data_list.append(warn_vuv)
        data_list.append(num_warn_v_high)
        data_list.append(num_warn_v_low)
        data_list.append(balance_state)
        data_list.append(discharge_num)
        data_list.append(charge_num)
        return data_list

    def get_voltage(self):
        data_list = []
        #  
        v1 = int(self.data[24:28], 16)
        v2 = int(self.data[28:32], 16)
        v3 = int(self.data[32:36], 16)
        v4 = int(self.data[36:40], 16)
        v5 = int(self.data[40:44], 16)
        v6 = int(self.data[44:48], 16)
        
        data_list.append(v1)
        data_list.append(v2)
        data_list.append(v3)
        data_list.append(v4)
        data_list.append(v5)
        data_list.append(v6)
        return data_list
        
    def get_current(self):
        data_list = []
        curr_0 = int(self.data[48:52], 16)
        curr_1 = int(self.data[52:56], 16)
        data_list.append(curr_0)
        data_list.append(curr_1)

    def get_temperature(self):
        data_list = []
        temp_num = int(self.data[56:58], 16)
        temp_0 = int(self.data[58:60], 16)        
        temp_1 = int(self.data[60:62], 16)
        temp_2 = int(self.data[62:64], 16)
        temp_3 = int(self.data[64:66], 16)
        max_temp = max(temp_0, temp_1, temp_2 , temp_3)
        data_list.append(max_temp)
        data_list.append(temp_num)
        data_list.append(temp_0)
        data_list.append(temp_1)
        data_list.append(temp_2)
        data_list.append(temp_3)
        return data_list

    def get_capacitance(self):
        data_list =[]
        cap_now = int(self.data[114:118], 16)
        cap_full = int(self.data[118:122], 16)
        data_list.append(cap_now)
        data_list.append(cap_full)
        return data_list
    
    def get_crc(self):
        crc = int(self.data[122:124], 16)
        return crc
    
    def publish(self):
        msg = BatteryStatus()
        msg.id = self.id
        msg.vbat = self.vbat
        msg.soc = self.soc
        msg.max_temp=self.max_temp
        self.publisher.publish(msg)
        # self.get_logger().info('Publishing: "%s"' % msg.data)
