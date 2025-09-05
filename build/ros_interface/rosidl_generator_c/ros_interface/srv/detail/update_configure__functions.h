// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ros_interface:srv/UpdateConfigure.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__FUNCTIONS_H_
#define ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ros_interface/msg/rosidl_generator_c__visibility_control.h"

#include "ros_interface/srv/detail/update_configure__struct.h"

/// Initialize srv/UpdateConfigure message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ros_interface__srv__UpdateConfigure_Request
 * )) before or use
 * ros_interface__srv__UpdateConfigure_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Request__init(ros_interface__srv__UpdateConfigure_Request * msg);

/// Finalize srv/UpdateConfigure message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Request__fini(ros_interface__srv__UpdateConfigure_Request * msg);

/// Create srv/UpdateConfigure message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ros_interface__srv__UpdateConfigure_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
ros_interface__srv__UpdateConfigure_Request *
ros_interface__srv__UpdateConfigure_Request__create();

/// Destroy srv/UpdateConfigure message.
/**
 * It calls
 * ros_interface__srv__UpdateConfigure_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Request__destroy(ros_interface__srv__UpdateConfigure_Request * msg);

/// Check for srv/UpdateConfigure message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Request__are_equal(const ros_interface__srv__UpdateConfigure_Request * lhs, const ros_interface__srv__UpdateConfigure_Request * rhs);

/// Copy a srv/UpdateConfigure message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Request__copy(
  const ros_interface__srv__UpdateConfigure_Request * input,
  ros_interface__srv__UpdateConfigure_Request * output);

/// Initialize array of srv/UpdateConfigure messages.
/**
 * It allocates the memory for the number of elements and calls
 * ros_interface__srv__UpdateConfigure_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Request__Sequence__init(ros_interface__srv__UpdateConfigure_Request__Sequence * array, size_t size);

/// Finalize array of srv/UpdateConfigure messages.
/**
 * It calls
 * ros_interface__srv__UpdateConfigure_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Request__Sequence__fini(ros_interface__srv__UpdateConfigure_Request__Sequence * array);

/// Create array of srv/UpdateConfigure messages.
/**
 * It allocates the memory for the array and calls
 * ros_interface__srv__UpdateConfigure_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
ros_interface__srv__UpdateConfigure_Request__Sequence *
ros_interface__srv__UpdateConfigure_Request__Sequence__create(size_t size);

/// Destroy array of srv/UpdateConfigure messages.
/**
 * It calls
 * ros_interface__srv__UpdateConfigure_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Request__Sequence__destroy(ros_interface__srv__UpdateConfigure_Request__Sequence * array);

/// Check for srv/UpdateConfigure message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Request__Sequence__are_equal(const ros_interface__srv__UpdateConfigure_Request__Sequence * lhs, const ros_interface__srv__UpdateConfigure_Request__Sequence * rhs);

/// Copy an array of srv/UpdateConfigure messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Request__Sequence__copy(
  const ros_interface__srv__UpdateConfigure_Request__Sequence * input,
  ros_interface__srv__UpdateConfigure_Request__Sequence * output);

/// Initialize srv/UpdateConfigure message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ros_interface__srv__UpdateConfigure_Response
 * )) before or use
 * ros_interface__srv__UpdateConfigure_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Response__init(ros_interface__srv__UpdateConfigure_Response * msg);

/// Finalize srv/UpdateConfigure message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Response__fini(ros_interface__srv__UpdateConfigure_Response * msg);

/// Create srv/UpdateConfigure message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ros_interface__srv__UpdateConfigure_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
ros_interface__srv__UpdateConfigure_Response *
ros_interface__srv__UpdateConfigure_Response__create();

/// Destroy srv/UpdateConfigure message.
/**
 * It calls
 * ros_interface__srv__UpdateConfigure_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Response__destroy(ros_interface__srv__UpdateConfigure_Response * msg);

/// Check for srv/UpdateConfigure message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Response__are_equal(const ros_interface__srv__UpdateConfigure_Response * lhs, const ros_interface__srv__UpdateConfigure_Response * rhs);

/// Copy a srv/UpdateConfigure message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Response__copy(
  const ros_interface__srv__UpdateConfigure_Response * input,
  ros_interface__srv__UpdateConfigure_Response * output);

/// Initialize array of srv/UpdateConfigure messages.
/**
 * It allocates the memory for the number of elements and calls
 * ros_interface__srv__UpdateConfigure_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Response__Sequence__init(ros_interface__srv__UpdateConfigure_Response__Sequence * array, size_t size);

/// Finalize array of srv/UpdateConfigure messages.
/**
 * It calls
 * ros_interface__srv__UpdateConfigure_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Response__Sequence__fini(ros_interface__srv__UpdateConfigure_Response__Sequence * array);

/// Create array of srv/UpdateConfigure messages.
/**
 * It allocates the memory for the array and calls
 * ros_interface__srv__UpdateConfigure_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
ros_interface__srv__UpdateConfigure_Response__Sequence *
ros_interface__srv__UpdateConfigure_Response__Sequence__create(size_t size);

/// Destroy array of srv/UpdateConfigure messages.
/**
 * It calls
 * ros_interface__srv__UpdateConfigure_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
void
ros_interface__srv__UpdateConfigure_Response__Sequence__destroy(ros_interface__srv__UpdateConfigure_Response__Sequence * array);

/// Check for srv/UpdateConfigure message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Response__Sequence__are_equal(const ros_interface__srv__UpdateConfigure_Response__Sequence * lhs, const ros_interface__srv__UpdateConfigure_Response__Sequence * rhs);

/// Copy an array of srv/UpdateConfigure messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros_interface
bool
ros_interface__srv__UpdateConfigure_Response__Sequence__copy(
  const ros_interface__srv__UpdateConfigure_Response__Sequence * input,
  ros_interface__srv__UpdateConfigure_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__FUNCTIONS_H_
