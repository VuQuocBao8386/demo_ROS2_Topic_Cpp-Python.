// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_interface:srv/UpdateConfigure.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__STRUCT_H_
#define ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/UpdateConfigure in the package ros_interface.
typedef struct ros_interface__srv__UpdateConfigure_Request
{
  rosidl_runtime_c__String command;
  rosidl_runtime_c__String mode;
  int64_t area;
  int32_t threshold_1;
  int32_t threshold_2;
} ros_interface__srv__UpdateConfigure_Request;

// Struct for a sequence of ros_interface__srv__UpdateConfigure_Request.
typedef struct ros_interface__srv__UpdateConfigure_Request__Sequence
{
  ros_interface__srv__UpdateConfigure_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interface__srv__UpdateConfigure_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/UpdateConfigure in the package ros_interface.
typedef struct ros_interface__srv__UpdateConfigure_Response
{
  bool success;
  rosidl_runtime_c__String message;
} ros_interface__srv__UpdateConfigure_Response;

// Struct for a sequence of ros_interface__srv__UpdateConfigure_Response.
typedef struct ros_interface__srv__UpdateConfigure_Response__Sequence
{
  ros_interface__srv__UpdateConfigure_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_interface__srv__UpdateConfigure_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__STRUCT_H_
