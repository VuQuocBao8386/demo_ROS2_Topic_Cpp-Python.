# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros_interface:srv/ProcessRequest.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ProcessRequest_Request(type):
    """Metaclass of message 'ProcessRequest_Request'."""

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
                'ros_interface.srv.ProcessRequest_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__process_request__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__process_request__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__process_request__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__process_request__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__process_request__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ProcessRequest_Request(metaclass=Metaclass_ProcessRequest_Request):
    """Message class 'ProcessRequest_Request'."""

    __slots__ = [
        '_start_requestdata',
    ]

    _fields_and_field_types = {
        'start_requestdata': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.start_requestdata = kwargs.get('start_requestdata', bool())

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
        if self.start_requestdata != other.start_requestdata:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start_requestdata(self):
        """Message field 'start_requestdata'."""
        return self._start_requestdata

    @start_requestdata.setter
    def start_requestdata(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'start_requestdata' field must be of type 'bool'"
        self._start_requestdata = value


# Import statements for member types

# Member 'data'
import array  # noqa: E402, I100

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ProcessRequest_Response(type):
    """Metaclass of message 'ProcessRequest_Response'."""

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
                'ros_interface.srv.ProcessRequest_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__process_request__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__process_request__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__process_request__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__process_request__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__process_request__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ProcessRequest_Response(metaclass=Metaclass_ProcessRequest_Response):
    """Message class 'ProcessRequest_Response'."""

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


class Metaclass_ProcessRequest(type):
    """Metaclass of service 'ProcessRequest'."""

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
                'ros_interface.srv.ProcessRequest')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__process_request

            from ros_interface.srv import _process_request
            if _process_request.Metaclass_ProcessRequest_Request._TYPE_SUPPORT is None:
                _process_request.Metaclass_ProcessRequest_Request.__import_type_support__()
            if _process_request.Metaclass_ProcessRequest_Response._TYPE_SUPPORT is None:
                _process_request.Metaclass_ProcessRequest_Response.__import_type_support__()


class ProcessRequest(metaclass=Metaclass_ProcessRequest):
    from ros_interface.srv._process_request import ProcessRequest_Request as Request
    from ros_interface.srv._process_request import ProcessRequest_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
