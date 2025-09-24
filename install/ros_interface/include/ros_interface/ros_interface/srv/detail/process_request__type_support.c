// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros_interface:srv/ProcessRequest.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros_interface/srv/detail/process_request__rosidl_typesupport_introspection_c.h"
#include "ros_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros_interface/srv/detail/process_request__functions.h"
#include "ros_interface/srv/detail/process_request__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros_interface__srv__ProcessRequest_Request__init(message_memory);
}

void ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_fini_function(void * message_memory)
{
  ros_interface__srv__ProcessRequest_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_member_array[1] = {
  {
    "start_requestdata",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_interface__srv__ProcessRequest_Request, start_requestdata),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_members = {
  "ros_interface__srv",  // message namespace
  "ProcessRequest_Request",  // message name
  1,  // number of fields
  sizeof(ros_interface__srv__ProcessRequest_Request),
  ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_member_array,  // message members
  ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_type_support_handle = {
  0,
  &ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest_Request)() {
  if (!ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_type_support_handle.typesupport_identifier) {
    ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros_interface__srv__ProcessRequest_Request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ros_interface/srv/detail/process_request__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ros_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ros_interface/srv/detail/process_request__functions.h"
// already included above
// #include "ros_interface/srv/detail/process_request__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros_interface__srv__ProcessRequest_Response__init(message_memory);
}

void ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_fini_function(void * message_memory)
{
  ros_interface__srv__ProcessRequest_Response__fini(message_memory);
}

size_t ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__size_function__ProcessRequest_Response__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__get_const_function__ProcessRequest_Response__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__get_function__ProcessRequest_Response__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__fetch_function__ProcessRequest_Response__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__get_const_function__ProcessRequest_Response__data(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__assign_function__ProcessRequest_Response__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__get_function__ProcessRequest_Response__data(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__resize_function__ProcessRequest_Response__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_member_array[2] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_interface__srv__ProcessRequest_Response, data),  // bytes offset in struct
    NULL,  // default value
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__size_function__ProcessRequest_Response__data,  // size() function pointer
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__get_const_function__ProcessRequest_Response__data,  // get_const(index) function pointer
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__get_function__ProcessRequest_Response__data,  // get(index) function pointer
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__fetch_function__ProcessRequest_Response__data,  // fetch(index, &value) function pointer
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__assign_function__ProcessRequest_Response__data,  // assign(index, value) function pointer
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__resize_function__ProcessRequest_Response__data  // resize(index) function pointer
  },
  {
    "send_success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_interface__srv__ProcessRequest_Response, send_success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_members = {
  "ros_interface__srv",  // message namespace
  "ProcessRequest_Response",  // message name
  2,  // number of fields
  sizeof(ros_interface__srv__ProcessRequest_Response),
  ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_member_array,  // message members
  ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_type_support_handle = {
  0,
  &ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest_Response)() {
  if (!ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_type_support_handle.typesupport_identifier) {
    ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros_interface__srv__ProcessRequest_Response__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ros_interface/srv/detail/process_request__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_members = {
  "ros_interface__srv",  // service namespace
  "ProcessRequest",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_Request_message_type_support_handle,
  NULL  // response message
  // ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_Response_message_type_support_handle
};

static rosidl_service_type_support_t ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_type_support_handle = {
  0,
  &ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest)() {
  if (!ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_type_support_handle.typesupport_identifier) {
    ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_interface, srv, ProcessRequest_Response)()->data;
  }

  return &ros_interface__srv__detail__process_request__rosidl_typesupport_introspection_c__ProcessRequest_service_type_support_handle;
}
