// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rs485:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rs485/msg/detail/battery_status__rosidl_typesupport_introspection_c.h"
#include "rs485/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rs485/msg/detail/battery_status__functions.h"
#include "rs485/msg/detail/battery_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rs485__msg__BatteryStatus__init(message_memory);
}

void BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_fini_function(void * message_memory)
{
  rs485__msg__BatteryStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_member_array[4] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__BatteryStatus, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vbat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__BatteryStatus, vbat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "soc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__BatteryStatus, soc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_temp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__BatteryStatus, max_temp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_members = {
  "rs485__msg",  // message namespace
  "BatteryStatus",  // message name
  4,  // number of fields
  sizeof(rs485__msg__BatteryStatus),
  BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_member_array,  // message members
  BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_type_support_handle = {
  0,
  &BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rs485
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rs485, msg, BatteryStatus)() {
  if (!BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_type_support_handle.typesupport_identifier) {
    BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &BatteryStatus__rosidl_typesupport_introspection_c__BatteryStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
