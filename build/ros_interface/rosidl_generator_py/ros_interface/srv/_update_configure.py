# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros_interface:srv/UpdateConfigure.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpdateConfigure_Request(type):
    """Metaclass of message 'UpdateConfigure_Request'."""

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
            module = import_type_support('ros_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_interface.srv.UpdateConfigure_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__update_configure__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__update_configure__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__update_configure__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__update_configure__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__update_configure__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UpdateConfigure_Request(metaclass=Metaclass_UpdateConfigure_Request):
    """Message class 'UpdateConfigure_Request'."""

    __slots__ = [
        '_command',
        '_mode',
        '_area',
        '_threshold_1',
        '_threshold_2',
    ]

    _fields_and_field_types = {
        'command': 'string',
        'mode': 'string',
        'area': 'int64',
        'threshold_1': 'int32',
        'threshold_2': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.command = kwargs.get('command', str())
        self.mode = kwargs.get('mode', str())
        self.area = kwargs.get('area', int())
        self.threshold_1 = kwargs.get('threshold_1', int())
        self.threshold_2 = kwargs.get('threshold_2', int())

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
        if self.command != other.command:
            return False
        if self.mode != other.mode:
            return False
        if self.area != other.area:
            return False
        if self.threshold_1 != other.threshold_1:
            return False
        if self.threshold_2 != other.threshold_2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'command' field must be of type 'str'"
        self._command = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mode' field must be of type 'str'"
        self._mode = value

    @builtins.property
    def area(self):
        """Message field 'area'."""
        return self._area

    @area.setter
    def area(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'area' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'area' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._area = value

    @builtins.property
    def threshold_1(self):
        """Message field 'threshold_1'."""
        return self._threshold_1

    @threshold_1.setter
    def threshold_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'threshold_1' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'threshold_1' field must be an integer in [-2147483648, 2147483647]"
        self._threshold_1 = value

    @builtins.property
    def threshold_2(self):
        """Message field 'threshold_2'."""
        return self._threshold_2

    @threshold_2.setter
    def threshold_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'threshold_2' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'threshold_2' field must be an integer in [-2147483648, 2147483647]"
        self._threshold_2 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_UpdateConfigure_Response(type):
    """Metaclass of message 'UpdateConfigure_Response'."""

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
            module = import_type_support('ros_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_interface.srv.UpdateConfigure_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__update_configure__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__update_configure__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__update_configure__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__update_configure__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__update_configure__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UpdateConfigure_Response(metaclass=Metaclass_UpdateConfigure_Response):
    """Message class 'UpdateConfigure_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

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
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_UpdateConfigure(type):
    """Metaclass of service 'UpdateConfigure'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_interface.srv.UpdateConfigure')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__update_configure

            from ros_interface.srv import _update_configure
            if _update_configure.Metaclass_UpdateConfigure_Request._TYPE_SUPPORT is None:
                _update_configure.Metaclass_UpdateConfigure_Request.__import_type_support__()
            if _update_configure.Metaclass_UpdateConfigure_Response._TYPE_SUPPORT is None:
                _update_configure.Metaclass_UpdateConfigure_Response.__import_type_support__()


class UpdateConfigure(metaclass=Metaclass_UpdateConfigure):
    from ros_interface.srv._update_configure import UpdateConfigure_Request as Request
    from ros_interface.srv._update_configure import UpdateConfigure_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
