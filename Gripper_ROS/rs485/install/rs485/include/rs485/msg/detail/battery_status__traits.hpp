// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rs485:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
#define RS485__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_

#include "rs485/msg/detail/battery_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rs485::msg::BatteryStatus>()
{
  return "rs485::msg::BatteryStatus";
}

template<>
inline const char * name<rs485::msg::BatteryStatus>()
{
  return "rs485/msg/BatteryStatus";
}

template<>
struct has_fixed_size<rs485::msg::BatteryStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rs485::msg::BatteryStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rs485::msg::BatteryStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RS485__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
