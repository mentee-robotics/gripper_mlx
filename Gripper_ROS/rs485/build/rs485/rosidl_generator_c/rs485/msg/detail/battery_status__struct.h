// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rs485:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef RS485__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_
#define RS485__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/BatteryStatus in the package rs485.
typedef struct rs485__msg__BatteryStatus
{
  int32_t id;
  int32_t vbat;
  int32_t soc;
  int32_t max_temp;
} rs485__msg__BatteryStatus;

// Struct for a sequence of rs485__msg__BatteryStatus.
typedef struct rs485__msg__BatteryStatus__Sequence
{
  rs485__msg__BatteryStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rs485__msg__BatteryStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RS485__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_
