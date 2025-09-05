// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_interface:srv/ProcessRequest.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__STRUCT_H_
#define ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_communication'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ProcessRequest in the package ros_interface.
typedef struct ros_interface__srv__ProcessRequest_Request
{
  rosidl_runtime_c__String start_communication;
} ros_interface__srv__ProcessRequest_Request;

// Struct for a sequence of ros_interface__srv__ProcessRequest_Request.
typedef struct ros_interface__srv__ProcessRequest_Request__Sequence
{
  ros_interface__srv__ProcessRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interface__srv__ProcessRequest_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/ProcessRequest in the package ros_interface.
typedef struct ros_interface__srv__ProcessRequest_Response
{
  rosidl_runtime_c__int32__Sequence data;
  bool send_success;
} ros_interface__srv__ProcessRequest_Response;

// Struct for a sequence of ros_interface__srv__ProcessRequest_Response.
typedef struct ros_interface__srv__ProcessRequest_Response__Sequence
{
  ros_interface__srv__ProcessRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interface__srv__ProcessRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__STRUCT_H_
