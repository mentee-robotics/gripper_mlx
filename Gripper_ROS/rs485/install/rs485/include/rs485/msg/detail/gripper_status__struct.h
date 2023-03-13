// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__GRIPPER_STATUS__STRUCT_H_
#define RS485__MSG__DETAIL__GRIPPER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/GripperStatus in the package rs485.
typedef struct rs485__msg__GripperStatus
{
  int32_t id;
  int32_t position;
  float current;
  int64_t xmag;
  int64_t ymag;
  int64_t zmag;
  int32_t targetpos;
} rs485__msg__GripperStatus;

// Struct for a sequence of rs485__msg__GripperStatus.
typedef struct rs485__msg__GripperStatus__Sequence
{
  rs485__msg__GripperStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rs485__msg__GripperStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RS485__MSG__DETAIL__GRIPPER_STATUS__STRUCT_H_
