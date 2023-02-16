// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rs485:msg/BatteryStatus.idl
// generated code does not contain a copyright notice
#include "rs485/msg/detail/battery_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rs485__msg__BatteryStatus__init(rs485__msg__BatteryStatus * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // vbat
  // soc
  // max_temp
  return true;
}

void
rs485__msg__BatteryStatus__fini(rs485__msg__BatteryStatus * msg)
{
  if (!msg) {
    return;
  }
  // id
  // vbat
  // soc
  // max_temp
}

bool
rs485__msg__BatteryStatus__are_equal(const rs485__msg__BatteryStatus * lhs, const rs485__msg__BatteryStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // vbat
  if (lhs->vbat != rhs->vbat) {
    return false;
  }
  // soc
  if (lhs->soc != rhs->soc) {
    return false;
  }
  // max_temp
  if (lhs->max_temp != rhs->max_temp) {
    return false;
  }
  return true;
}

bool
rs485__msg__BatteryStatus__copy(
  const rs485__msg__BatteryStatus * input,
  rs485__msg__BatteryStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // vbat
  output->vbat = input->vbat;
  // soc
  output->soc = input->soc;
  // max_temp
  output->max_temp = input->max_temp;
  return true;
}

rs485__msg__BatteryStatus *
rs485__msg__BatteryStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rs485__msg__BatteryStatus * msg = (rs485__msg__BatteryStatus *)allocator.allocate(sizeof(rs485__msg__BatteryStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rs485__msg__BatteryStatus));
  bool success = rs485__msg__BatteryStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rs485__msg__BatteryStatus__destroy(rs485__msg__BatteryStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rs485__msg__BatteryStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rs485__msg__BatteryStatus__Sequence__init(rs485__msg__BatteryStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rs485__msg__BatteryStatus * data = NULL;

  if (size) {
    data = (rs485__msg__BatteryStatus *)allocator.zero_allocate(size, sizeof(rs485__msg__BatteryStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rs485__msg__BatteryStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rs485__msg__BatteryStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rs485__msg__BatteryStatus__Sequence__fini(rs485__msg__BatteryStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rs485__msg__BatteryStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rs485__msg__BatteryStatus__Sequence *
rs485__msg__BatteryStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rs485__msg__BatteryStatus__Sequence * array = (rs485__msg__BatteryStatus__Sequence *)allocator.allocate(sizeof(rs485__msg__BatteryStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rs485__msg__BatteryStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rs485__msg__BatteryStatus__Sequence__destroy(rs485__msg__BatteryStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rs485__msg__BatteryStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rs485__msg__BatteryStatus__Sequence__are_equal(const rs485__msg__BatteryStatus__Sequence * lhs, const rs485__msg__BatteryStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rs485__msg__BatteryStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rs485__msg__BatteryStatus__Sequence__copy(
  const rs485__msg__BatteryStatus__Sequence * input,
  rs485__msg__BatteryStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rs485__msg__BatteryStatus);
    rs485__msg__BatteryStatus * data =
      (rs485__msg__BatteryStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rs485__msg__BatteryStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rs485__msg__BatteryStatus__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rs485__msg__BatteryStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
