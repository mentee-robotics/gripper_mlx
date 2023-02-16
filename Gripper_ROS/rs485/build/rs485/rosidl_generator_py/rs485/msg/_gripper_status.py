# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rs485:msg/GripperStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GripperStatus(type):
    """Metaclass of message 'GripperStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rs485')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rs485.msg.GripperStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gripper_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gripper_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gripper_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gripper_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gripper_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperStatus(metaclass=Metaclass_GripperStatus):
    """Message class 'GripperStatus'."""

    __slots__ = [
        '_id',
        '_position',
        '_current',
        '_xmag',
        '_ymag',
        '_zmag',
        '_targetpos',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'position': 'int32',
        'current': 'float',
        'xmag': 'int64',
        'ymag': 'int64',
        'zmag': 'int64',
        'targetpos': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.position = kwargs.get('position', int())
        self.current = kwargs.get('current', float())
        self.xmag = kwargs.get('xmag', int())
        self.ymag = kwargs.get('ymag', int())
        self.zmag = kwargs.get('zmag', int())
        self.targetpos = kwargs.get('targetpos', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.id != other.id:
            return False
        if self.position != other.position:
            return False
        if self.current != other.current:
            return False
        if self.xmag != other.xmag:
            return False
        if self.ymag != other.ymag:
            return False
        if self.zmag != other.zmag:
            return False
        if self.targetpos != other.targetpos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'position' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'position' field must be an integer in [-2147483648, 2147483647]"
        self._position = value

    @property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current' field must be of type 'float'"
        self._current = value

    @property
    def xmag(self):
        """Message field 'xmag'."""
        return self._xmag

    @xmag.setter
    def xmag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmag' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'xmag' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._xmag = value

    @property
    def ymag(self):
        """Message field 'ymag'."""
        return self._ymag

    @ymag.setter
    def ymag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymag' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'ymag' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._ymag = value

    @property
    def zmag(self):
        """Message field 'zmag'."""
        return self._zmag

    @zmag.setter
    def zmag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'zmag' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'zmag' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._zmag = value

    @property
    def targetpos(self):
        """Message field 'targetpos'."""
        return self._targetpos

    @targetpos.setter
    def targetpos(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'targetpos' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'targetpos' field must be an integer in [-2147483648, 2147483647]"
        self._targetpos = value
