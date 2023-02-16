// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rs485:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_
#define RS485__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rs485__msg__BatteryStatus __attribute__((deprecated))
#else
# define DEPRECATED__rs485__msg__BatteryStatus __declspec(deprecated)
#endif

namespace rs485
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BatteryStatus_
{
  using Type = BatteryStatus_<ContainerAllocator>;

  explicit BatteryStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->vbat = 0l;
      this->soc = 0l;
      this->max_temp = 0l;
    }
  }

  explicit BatteryStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->vbat = 0l;
      this->soc = 0l;
      this->max_temp = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _vbat_type =
    int32_t;
  _vbat_type vbat;
  using _soc_type =
    int32_t;
  _soc_type soc;
  using _max_temp_type =
    int32_t;
  _max_temp_type max_temp;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__vbat(
    const int32_t & _arg)
  {
    this->vbat = _arg;
    return *this;
  }
  Type & set__soc(
    const int32_t & _arg)
  {
    this->soc = _arg;
    return *this;
  }
  Type & set__max_temp(
    const int32_t & _arg)
  {
    this->max_temp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rs485::msg::BatteryStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rs485::msg::BatteryStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rs485::msg::BatteryStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rs485::msg::BatteryStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rs485::msg::BatteryStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rs485::msg::BatteryStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rs485::msg::BatteryStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rs485::msg::BatteryStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rs485::msg::BatteryStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rs485::msg::BatteryStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rs485__msg__BatteryStatus
    std::shared_ptr<rs485::msg::BatteryStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rs485__msg__BatteryStatus
    std::shared_ptr<rs485::msg::BatteryStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BatteryStatus_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->vbat != other.vbat) {
      return false;
    }
    if (this->soc != other.soc) {
      return false;
    }
    if (this->max_temp != other.max_temp) {
      return false;
    }
    return true;
  }
  bool operator!=(const BatteryStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BatteryStatus_

// alias to use template instance with default allocator
using BatteryStatus =
  rs485::msg::BatteryStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rs485

#endif  // RS485__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_
