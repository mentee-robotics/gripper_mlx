// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rs485:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
#define RS485__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_

#include "rs485/msg/detail/battery_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rs485
{

namespace msg
{

namespace builder
{

class Init_BatteryStatus_max_temp
{
public:
  explicit Init_BatteryStatus_max_temp(::rs485::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  ::rs485::msg::BatteryStatus max_temp(::rs485::msg::BatteryStatus::_max_temp_type arg)
  {
    msg_.max_temp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rs485::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_soc
{
public:
  explicit Init_BatteryStatus_soc(::rs485::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_max_temp soc(::rs485::msg::BatteryStatus::_soc_type arg)
  {
    msg_.soc = std::move(arg);
    return Init_BatteryStatus_max_temp(msg_);
  }

private:
  ::rs485::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_vbat
{
public:
  explicit Init_BatteryStatus_vbat(::rs485::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_soc vbat(::rs485::msg::BatteryStatus::_vbat_type arg)
  {
    msg_.vbat = std::move(arg);
    return Init_BatteryStatus_soc(msg_);
  }

private:
  ::rs485::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_id
{
public:
  Init_BatteryStatus_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryStatus_vbat id(::rs485::msg::BatteryStatus::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_BatteryStatus_vbat(msg_);
  }

private:
  ::rs485::msg::BatteryStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rs485::msg::BatteryStatus>()
{
  return rs485::msg::builder::Init_BatteryStatus_id();
}

}  // namespace rs485

#endif  // RS485__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
