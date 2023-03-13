// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__GRIPPER_STATUS__BUILDER_HPP_
#define RS485__MSG__DETAIL__GRIPPER_STATUS__BUILDER_HPP_

#include "rs485/msg/detail/gripper_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rs485
{

namespace msg
{

namespace builder
{

class Init_GripperStatus_targetpos
{
public:
  explicit Init_GripperStatus_targetpos(::rs485::msg::GripperStatus & msg)
  : msg_(msg)
  {}
  ::rs485::msg::GripperStatus targetpos(::rs485::msg::GripperStatus::_targetpos_type arg)
  {
    msg_.targetpos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

class Init_GripperStatus_zmag
{
public:
  explicit Init_GripperStatus_zmag(::rs485::msg::GripperStatus & msg)
  : msg_(msg)
  {}
  Init_GripperStatus_targetpos zmag(::rs485::msg::GripperStatus::_zmag_type arg)
  {
    msg_.zmag = std::move(arg);
    return Init_GripperStatus_targetpos(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

class Init_GripperStatus_ymag
{
public:
  explicit Init_GripperStatus_ymag(::rs485::msg::GripperStatus & msg)
  : msg_(msg)
  {}
  Init_GripperStatus_zmag ymag(::rs485::msg::GripperStatus::_ymag_type arg)
  {
    msg_.ymag = std::move(arg);
    return Init_GripperStatus_zmag(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

class Init_GripperStatus_xmag
{
public:
  explicit Init_GripperStatus_xmag(::rs485::msg::GripperStatus & msg)
  : msg_(msg)
  {}
  Init_GripperStatus_ymag xmag(::rs485::msg::GripperStatus::_xmag_type arg)
  {
    msg_.xmag = std::move(arg);
    return Init_GripperStatus_ymag(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

class Init_GripperStatus_current
{
public:
  explicit Init_GripperStatus_current(::rs485::msg::GripperStatus & msg)
  : msg_(msg)
  {}
  Init_GripperStatus_xmag current(::rs485::msg::GripperStatus::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_GripperStatus_xmag(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

class Init_GripperStatus_position
{
public:
  explicit Init_GripperStatus_position(::rs485::msg::GripperStatus & msg)
  : msg_(msg)
  {}
  Init_GripperStatus_current position(::rs485::msg::GripperStatus::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_GripperStatus_current(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

class Init_GripperStatus_id
{
public:
  Init_GripperStatus_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperStatus_position id(::rs485::msg::GripperStatus::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_GripperStatus_position(msg_);
  }

private:
  ::rs485::msg::GripperStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rs485::msg::GripperStatus>()
{
  return rs485::msg::builder::Init_GripperStatus_id();
}

}  // namespace rs485

#endif  // RS485__MSG__DETAIL__GRIPPER_STATUS__BUILDER_HPP_
