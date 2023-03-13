// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rs485/msg/detail/gripper_status__rosidl_typesupport_introspection_c.h"
#include "rs485/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rs485/msg/detail/gripper_status__functions.h"
#include "rs485/msg/detail/gripper_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rs485__msg__GripperStatus__init(message_memory);
}

void GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_fini_function(void * message_memory)
{
  rs485__msg__GripperStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_member_array[7] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, current),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, xmag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, ymag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zmag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, zmag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "targetpos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rs485__msg__GripperStatus, targetpos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_members = {
  "rs485__msg",  // message namespace
  "GripperStatus",  // message name
  7,  // number of fields
  sizeof(rs485__msg__GripperStatus),
  GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_member_array,  // message members
  GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_type_support_handle = {
  0,
  &GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rs485
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rs485, msg, GripperStatus)() {
  if (!GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_type_support_handle.typesupport_identifier) {
    GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GripperStatus__rosidl_typesupport_introspection_c__GripperStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
