// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__GRIPPER_STATUS__STRUCT_HPP_
#define RS485__MSG__DETAIL__GRIPPER_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rs485__msg__GripperStatus __attribute__((deprecated))
#else
# define DEPRECATED__rs485__msg__GripperStatus __declspec(deprecated)
#endif

namespace rs485
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GripperStatus_
{
  using Type = GripperStatus_<ContainerAllocator>;

  explicit GripperStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->position = 0l;
      this->current = 0.0f;
      this->xmag = 0ll;
      this->ymag = 0ll;
      this->zmag = 0ll;
      this->targetpos = 0l;
    }
  }

  explicit GripperStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->position = 0l;
      this->current = 0.0f;
      this->xmag = 0ll;
      this->ymag = 0ll;
      this->zmag = 0ll;
      this->targetpos = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _position_type =
    int32_t;
  _position_type position;
  using _current_type =
    float;
  _current_type current;
  using _xmag_type =
    int64_t;
  _xmag_type xmag;
  using _ymag_type =
    int64_t;
  _ymag_type ymag;
  using _zmag_type =
    int64_t;
  _zmag_type zmag;
  using _targetpos_type =
    int32_t;
  _targetpos_type targetpos;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__position(
    const int32_t & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__current(
    const float & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__xmag(
    const int64_t & _arg)
  {
    this->xmag = _arg;
    return *this;
  }
  Type & set__ymag(
    const int64_t & _arg)
  {
    this->ymag = _arg;
    return *this;
  }
  Type & set__zmag(
    const int64_t & _arg)
  {
    this->zmag = _arg;
    return *this;
  }
  Type & set__targetpos(
    const int32_t & _arg)
  {
    this->targetpos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rs485::msg::GripperStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rs485::msg::GripperStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rs485::msg::GripperStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rs485::msg::GripperStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rs485::msg::GripperStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rs485::msg::GripperStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rs485::msg::GripperStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rs485::msg::GripperStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rs485::msg::GripperStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rs485::msg::GripperStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rs485__msg__GripperStatus
    std::shared_ptr<rs485::msg::GripperStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rs485__msg__GripperStatus
    std::shared_ptr<rs485::msg::GripperStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperStatus_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->xmag != other.xmag) {
      return false;
    }
    if (this->ymag != other.ymag) {
      return false;
    }
    if (this->zmag != other.zmag) {
      return false;
    }
    if (this->targetpos != other.targetpos) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperStatus_

// alias to use template instance with default allocator
using GripperStatus =
  rs485::msg::GripperStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rs485

#endif  // RS485__MSG__DETAIL__GRIPPER_STATUS__STRUCT_HPP_
