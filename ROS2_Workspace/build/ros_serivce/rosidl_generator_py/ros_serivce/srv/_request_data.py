# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros_serivce:srv/RequestData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RequestData_Request(type):
    """Metaclass of message 'RequestData_Request'."""

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
            module = import_type_support('ros_serivce')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_serivce.srv.RequestData_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__request_data__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__request_data__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__request_data__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__request_data__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__request_data__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RequestData_Request(metaclass=Metaclass_RequestData_Request):
    """Message class 'RequestData_Request'."""

    __slots__ = [
        '_ros_request_data',
    ]

    _fields_and_field_types = {
        'ros_request_data': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ros_request_data = kwargs.get('ros_request_data', bool())

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
        if self.ros_request_data != other.ros_request_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ros_request_data(self):
        """Message field 'ros_request_data'."""
        return self._ros_request_data

    @ros_request_data.setter
    def ros_request_data(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'ros_request_data' field must be of type 'bool'"
        self._ros_request_data = value


# Import statements for member types

# Member 'data'
import array  # noqa: E402, I100

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RequestData_Response(type):
    """Metaclass of message 'RequestData_Response'."""

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
            module = import_type_support('ros_serivce')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_serivce.srv.RequestData_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__request_data__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__request_data__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__request_data__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__request_data__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__request_data__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RequestData_Response(metaclass=Metaclass_RequestData_Response):
    """Message class 'RequestData_Response'."""

    __slots__ = [
        '_data',
        '_send_success',
    ]

    _fields_and_field_types = {
        'data': 'sequence<int32>',
        'send_success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.data = array.array('i', kwargs.get('data', []))
        self.send_success = kwargs.get('send_success', bool())

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
        if self.data != other.data:
            return False
        if self.send_success != other.send_success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'data' array.array() must have the type code of 'i'"
            self._data = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'data' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._data = array.array('i', value)

    @builtins.property
    def send_success(self):
        """Message field 'send_success'."""
        return self._send_success

    @send_success.setter
    def send_success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'send_success' field must be of type 'bool'"
        self._send_success = value


class Metaclass_RequestData(type):
    """Metaclass of service 'RequestData'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros_serivce')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_serivce.srv.RequestData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__request_data

            from ros_serivce.srv import _request_data
            if _request_data.Metaclass_RequestData_Request._TYPE_SUPPORT is None:
                _request_data.Metaclass_RequestData_Request.__import_type_support__()
            if _request_data.Metaclass_RequestData_Response._TYPE_SUPPORT is None:
                _request_data.Metaclass_RequestData_Response.__import_type_support__()


class RequestData(metaclass=Metaclass_RequestData):
    from ros_serivce.srv._request_data import RequestData_Request as Request
    from ros_serivce.srv._request_data import RequestData_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
