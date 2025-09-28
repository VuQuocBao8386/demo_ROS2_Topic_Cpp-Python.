// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_serivce:srv/RequestData.idl
// generated code does not contain a copyright notice

#ifndef ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__STRUCT_H_
#define ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RequestData in the package ros_serivce.
typedef struct ros_serivce__srv__RequestData_Request
{
  bool ros_request_data;
} ros_serivce__srv__RequestData_Request;

// Struct for a sequence of ros_serivce__srv__RequestData_Request.
typedef struct ros_serivce__srv__RequestData_Request__Sequence
{
  ros_serivce__srv__RequestData_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_serivce__srv__RequestData_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/RequestData in the package ros_serivce.
typedef struct ros_serivce__srv__RequestData_Response
{
  rosidl_runtime_c__int32__Sequence data;
  bool send_success;
} ros_serivce__srv__RequestData_Response;

// Struct for a sequence of ros_serivce__srv__RequestData_Response.
typedef struct ros_serivce__srv__RequestData_Response__Sequence
{
  ros_serivce__srv__RequestData_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_serivce__srv__RequestData_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__STRUCT_H_
