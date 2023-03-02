// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rs485:msg/GripperStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rs485/msg/detail/gripper_status__struct.h"
#include "rs485/msg/detail/gripper_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rs485__msg__gripper_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rs485.msg._gripper_status.GripperStatus", full_classname_dest, 39) == 0);
  }
  rs485__msg__GripperStatus * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // position
    PyObject * field = PyObject_GetAttrString(_pymsg, "position");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->position = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // current
    PyObject * field = PyObject_GetAttrString(_pymsg, "current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // xmag
    PyObject * field = PyObject_GetAttrString(_pymsg, "xmag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xmag = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // ymag
    PyObject * field = PyObject_GetAttrString(_pymsg, "ymag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ymag = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // zmag
    PyObject * field = PyObject_GetAttrString(_pymsg, "zmag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->zmag = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // targetpos
    PyObject * field = PyObject_GetAttrString(_pymsg, "targetpos");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->targetpos = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rs485__msg__gripper_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GripperStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rs485.msg._gripper_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GripperStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rs485__msg__GripperStatus * ros_message = (rs485__msg__GripperStatus *)raw_ros_message;
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xmag
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->xmag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xmag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ymag
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->ymag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ymag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zmag
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->zmag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zmag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // targetpos
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->targetpos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "targetpos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
