#include "../include/battery_grippers.h"

Battery::Battery() {
    ser.port = "/dev/ttyTHS1";
    ser.baudrate = 9600;
    ser.bytesize = SerialPort::EIGHTBITS;
    ser.parity = SerialPort::PARITY_NONE;
    ser.stopbits = SerialPort::STOPBITS_ONE;
    ser.timeout = 1;
    ser.xonxoff = false;
    ser.rtscts = false;
    ser.dsrdtr = false;
    ser.writeTimeout = 0;
    ser.open();
    data = "";
}

std::vector<int> Battery::read() {
    ser.write(std::vector<char>{':', '0', '0', '0', '2', '0', '0', '0', '0', '0', 'e', 'e', '8', '~'});
    std::string message = ser.readline();
    std::vector<std::string> serial_data = split(message, ":018252");
    data = serial_data[1];
    return read_data();
}

std::string Battery::get_time() {
    return data.substr(4, 18);
}

std::vector<int> Battery::read_data() {
    std::vector<int> data_list;
    int vbat = std::stoi(data.substr(18, 22), nullptr, 16) * 2;
    int soc = std::stoi(data.substr(112, 114), nullptr, 16);
    int temp_0 = std::stoi(data.substr(58, 60), nullptr, 16);
    int temp_1 = std::stoi(data.substr(60, 62), nullptr, 16);
    int temp_2 = std::stoi(data.substr(62, 64), nullptr, 16);
    int temp_3 = std::stoi(data.substr(64, 66), nullptr, 16);
    int max_temp = std::max({temp_0, temp_1, temp_2, temp_3});
    data_list.push_back(vbat);
        data_list.push_back(soc);
    data_list.push_back(max_temp);
    return data_list;
}

std::vector<int> ReadBattery::get_unsorted_data() {
    std::vector<int> data_list;
    int length = std::stoi(data.substr(0, 4));
    int number_of_cells = std::stoi(data.substr(22, 24), nullptr, 16);
    int v_state = std::stoi(data.substr(66, 70), nullptr, 16);
    int c_state = std::stoi(data.substr(70, 74), nullptr, 16);
    int t_state = std::stoi(data.substr(74, 78), nullptr, 16);
    int alarm = std::stoi(data.substr(78, 82), nullptr, 16);
    int FET_state = std::stoi(data.substr(82, 84), nullptr, 16);
    int warn_vov = std::stoi(data.substr(84, 88), nullptr, 16);
    int warn_vuv = std::stoi(data.substr(88, 92), nullptr, 16);
    int num_warn_v_high = std::stoi(data.substr(92, 96), nullptr, 16);
    int num_warn_v_low = std::stoi(data.substr(96, 100), nullptr, 16);
    int balance_state = std::stoi(data.substr(100, 104), nullptr, 16);
    int discharge_num = std::stoi(data.substr(104, 108), nullptr, 16);
    int charge_num = std::stoi(data.substr(108, 112), nullptr, 16);
    data_list.push_back(length);
    data_list.push_back(number_of_cells);
    data_list.push_back(v_state);
    data_list.push_back(c_state);
    data_list.push_back(t_state);
    data_list.push_back(alarm);
    data_list.push_back(FET_state);
    data_list.push_back(warn_vov);
    data_list.push_back(warn_vuv);
    data_list.push_back(num_warn_v_high);
    data_list.push_back(num_warn_v_low);
    data_list.push_back(balance_state);
    data_list.push_back(discharge_num);
    data_list.push_back(charge_num);
    return data_list;
}

std::vector<int> ReadBattery::get_voltage() {
    std::vector<int> data_list;
    int v1 = std::stoi(data.substr(24, 28), nullptr, 16);
    int v2 = std::stoi(data.substr(28, 32), nullptr, 16);
    int v3 = std::stoi(data.substr(32, 36), nullptr, 16);
    int v4 = std::stoi(data.substr(36, 40), nullptr, 16);
    int v5 = std::stoi(data.substr(40, 44), nullptr, 16);
    int v6 = std::stoi(data.substr(44, 48), nullptr, 16);
    data_list.push_back(v1);
    data_list.push_back(v2);
    data_list.push_back(v3);
    data_list.push_back(v4);
    data_list.push_back(v5);
    data_list.push_back(v6);
    return data_list;
}

std::vector<int> ReadBattery::get_current() {
    std::vector<int> data_list;
    int curr_0 = std::stoi(data.substr(48, 52), nullptr, 16);
    int curr_1 = std::stoi(data.substr(52, 56), nullptr, 16);
    data_list.push_back(curr_0);
    data_list.push_back(curr_1);
    return data_list;
}

std::vector<int> ReadBattery::get_temperature() {
    std::vector<int> data_list;
    int temp_num = std::stoi(data.substr(56, 58), nullptr, 16);
    int temp_0 = std::stoi(data.substr(58, 60), nullptr, 16);
    int temp_1 = std::stoi(data.substr(60, 62), nullptr, 16);
    int temp_2 = std::stoi(data.substr(62, 64), nullptr, 16);
    int temp_3 = std::stoi(data.substr(64, 66), nullptr, 16);
    int max_temp = std::max({temp_0, temp_1, temp_2, temp_3});
    data_list.push_back(max_temp);
    data_list.push_back(temp_num);
    data_list.push_back(temp_0);
    data_list.push_back(temp_1);
    data_list.push_back(temp_2);
    data_list.push_back(temp_3);
    return data_list;
}

std::vector<int> ReadBattery::get_capacitance() {
    std::vector<int> data_list;
    int cap_now = std::stoi(data.substr(114, 118), nullptr, 16);
    int cap_full = std::stoi(data.substr(118, 122), nullptr, 16);
    data_list.push_back(cap_now);
    data_list.push_back(cap_full);
    return data_list;
}

int ReadBattery::get_crc() {
    return std::stoi(data.substr(122, 124), nullptr, 16);
}


