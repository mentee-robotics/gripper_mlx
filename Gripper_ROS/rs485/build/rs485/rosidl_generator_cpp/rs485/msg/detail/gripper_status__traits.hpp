// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__GRIPPER_STATUS__TRAITS_HPP_
#define RS485__MSG__DETAIL__GRIPPER_STATUS__TRAITS_HPP_

#include "rs485/msg/detail/gripper_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rs485::msg::GripperStatus>()
{
  return "rs485::msg::GripperStatus";
}

template<>
inline const char * name<rs485::msg::GripperStatus>()
{
  return "rs485/msg/GripperStatus";
}

template<>
struct has_fixed_size<rs485::msg::GripperStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rs485::msg::GripperStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rs485::msg::GripperStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RS485__MSG__DETAIL__GRIPPER_STATUS__TRAITS_HPP_
