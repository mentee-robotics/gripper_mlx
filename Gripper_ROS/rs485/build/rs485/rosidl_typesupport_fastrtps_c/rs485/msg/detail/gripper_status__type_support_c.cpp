// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice
#include "rs485/msg/detail/gripper_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rs485/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rs485/msg/detail/gripper_status__struct.h"
#include "rs485/msg/detail/gripper_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GripperStatus__ros_msg_type = rs485__msg__GripperStatus;

static bool _GripperStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GripperStatus__ros_msg_type * ros_message = static_cast<const _GripperStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: position
  {
    cdr << ros_message->position;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  // Field name: xmag
  {
    cdr << ros_message->xmag;
  }

  // Field name: ymag
  {
    cdr << ros_message->ymag;
  }

  // Field name: zmag
  {
    cdr << ros_message->zmag;
  }

  // Field name: targetpos
  {
    cdr << ros_message->targetpos;
  }

  return true;
}

static bool _GripperStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GripperStatus__ros_msg_type * ros_message = static_cast<_GripperStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: position
  {
    cdr >> ros_message->position;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  // Field name: xmag
  {
    cdr >> ros_message->xmag;
  }

  // Field name: ymag
  {
    cdr >> ros_message->ymag;
  }

  // Field name: zmag
  {
    cdr >> ros_message->zmag;
  }

  // Field name: targetpos
  {
    cdr >> ros_message->targetpos;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rs485
size_t get_serialized_size_rs485__msg__GripperStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GripperStatus__ros_msg_type * ros_message = static_cast<const _GripperStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position
  {
    size_t item_size = sizeof(ros_message->position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xmag
  {
    size_t item_size = sizeof(ros_message->xmag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ymag
  {
    size_t item_size = sizeof(ros_message->ymag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zmag
  {
    size_t item_size = sizeof(ros_message->zmag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name targetpos
  {
    size_t item_size = sizeof(ros_message->targetpos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GripperStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rs485__msg__GripperStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rs485
size_t max_serialized_size_rs485__msg__GripperStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: xmag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ymag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: zmag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: targetpos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _GripperStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rs485__msg__GripperStatus(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GripperStatus = {
  "rs485::msg",
  "GripperStatus",
  _GripperStatus__cdr_serialize,
  _GripperStatus__cdr_deserialize,
  _GripperStatus__get_serialized_size,
  _GripperStatus__max_serialized_size
};

static rosidl_message_type_support_t _GripperStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GripperStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rs485, msg, GripperStatus)() {
  return &_GripperStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
