// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros_interface:srv/UpdateConfigure.idl
// generated code does not contain a copyright notice
#include "ros_interface/srv/detail/update_configure__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `command`
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
ros_interface__srv__UpdateConfigure_Request__init(ros_interface__srv__UpdateConfigure_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    ros_interface__srv__UpdateConfigure_Request__fini(msg);
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    ros_interface__srv__UpdateConfigure_Request__fini(msg);
    return false;
  }
  // area
  // threshold_1
  // threshold_2
  return true;
}

void
ros_interface__srv__UpdateConfigure_Request__fini(ros_interface__srv__UpdateConfigure_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // area
  // threshold_1
  // threshold_2
}

bool
ros_interface__srv__UpdateConfigure_Request__are_equal(const ros_interface__srv__UpdateConfigure_Request * lhs, const ros_interface__srv__UpdateConfigure_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // area
  if (lhs->area != rhs->area) {
    return false;
  }
  // threshold_1
  if (lhs->threshold_1 != rhs->threshold_1) {
    return false;
  }
  // threshold_2
  if (lhs->threshold_2 != rhs->threshold_2) {
    return false;
  }
  return true;
}

bool
ros_interface__srv__UpdateConfigure_Request__copy(
  const ros_interface__srv__UpdateConfigure_Request * input,
  ros_interface__srv__UpdateConfigure_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // area
  output->area = input->area;
  // threshold_1
  output->threshold_1 = input->threshold_1;
  // threshold_2
  output->threshold_2 = input->threshold_2;
  return true;
}

ros_interface__srv__UpdateConfigure_Request *
ros_interface__srv__UpdateConfigure_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_interface__srv__UpdateConfigure_Request * msg = (ros_interface__srv__UpdateConfigure_Request *)allocator.allocate(sizeof(ros_interface__srv__UpdateConfigure_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros_interface__srv__UpdateConfigure_Request));
  bool success = ros_interface__srv__UpdateConfigure_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros_interface__srv__UpdateConfigure_Request__destroy(ros_interface__srv__UpdateConfigure_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros_interface__srv__UpdateConfigure_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros_interface__srv__UpdateConfigure_Request__Sequence__init(ros_interface__srv__UpdateConfigure_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_interface__srv__UpdateConfigure_Request * data = NULL;

  if (size) {
    data = (ros_interface__srv__UpdateConfigure_Request *)allocator.zero_allocate(size, sizeof(ros_interface__srv__UpdateConfigure_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros_interface__srv__UpdateConfigure_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros_interface__srv__UpdateConfigure_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros_interface__srv__UpdateConfigure_Request__Sequence__fini(ros_interface__srv__UpdateConfigure_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros_interface__srv__UpdateConfigure_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros_interface__srv__UpdateConfigure_Request__Sequence *
ros_interface__srv__UpdateConfigure_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_interface__srv__UpdateConfigure_Request__Sequence * array = (ros_interface__srv__UpdateConfigure_Request__Sequence *)allocator.allocate(sizeof(ros_interface__srv__UpdateConfigure_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros_interface__srv__UpdateConfigure_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros_interface__srv__UpdateConfigure_Request__Sequence__destroy(ros_interface__srv__UpdateConfigure_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros_interface__srv__UpdateConfigure_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros_interface__srv__UpdateConfigure_Request__Sequence__are_equal(const ros_interface__srv__UpdateConfigure_Request__Sequence * lhs, const ros_interface__srv__UpdateConfigure_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros_interface__srv__UpdateConfigure_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros_interface__srv__UpdateConfigure_Request__Sequence__copy(
  const ros_interface__srv__UpdateConfigure_Request__Sequence * input,
  ros_interface__srv__UpdateConfigure_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros_interface__srv__UpdateConfigure_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros_interface__srv__UpdateConfigure_Request * data =
      (ros_interface__srv__UpdateConfigure_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros_interface__srv__UpdateConfigure_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros_interface__srv__UpdateConfigure_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros_interface__srv__UpdateConfigure_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
ros_interface__srv__UpdateConfigure_Response__init(ros_interface__srv__UpdateConfigure_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    ros_interface__srv__UpdateConfigure_Response__fini(msg);
    return false;
  }
  return true;
}

void
ros_interface__srv__UpdateConfigure_Response__fini(ros_interface__srv__UpdateConfigure_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
ros_interface__srv__UpdateConfigure_Response__are_equal(const ros_interface__srv__UpdateConfigure_Response * lhs, const ros_interface__srv__UpdateConfigure_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
ros_interface__srv__UpdateConfigure_Response__copy(
  const ros_interface__srv__UpdateConfigure_Response * input,
  ros_interface__srv__UpdateConfigure_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

ros_interface__srv__UpdateConfigure_Response *
ros_interface__srv__UpdateConfigure_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_interface__srv__UpdateConfigure_Response * msg = (ros_interface__srv__UpdateConfigure_Response *)allocator.allocate(sizeof(ros_interface__srv__UpdateConfigure_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros_interface__srv__UpdateConfigure_Response));
  bool success = ros_interface__srv__UpdateConfigure_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros_interface__srv__UpdateConfigure_Response__destroy(ros_interface__srv__UpdateConfigure_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros_interface__srv__UpdateConfigure_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros_interface__srv__UpdateConfigure_Response__Sequence__init(ros_interface__srv__UpdateConfigure_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_interface__srv__UpdateConfigure_Response * data = NULL;

  if (size) {
    data = (ros_interface__srv__UpdateConfigure_Response *)allocator.zero_allocate(size, sizeof(ros_interface__srv__UpdateConfigure_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros_interface__srv__UpdateConfigure_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros_interface__srv__UpdateConfigure_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros_interface__srv__UpdateConfigure_Response__Sequence__fini(ros_interface__srv__UpdateConfigure_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros_interface__srv__UpdateConfigure_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros_interface__srv__UpdateConfigure_Response__Sequence *
ros_interface__srv__UpdateConfigure_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_interface__srv__UpdateConfigure_Response__Sequence * array = (ros_interface__srv__UpdateConfigure_Response__Sequence *)allocator.allocate(sizeof(ros_interface__srv__UpdateConfigure_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros_interface__srv__UpdateConfigure_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros_interface__srv__UpdateConfigure_Response__Sequence__destroy(ros_interface__srv__UpdateConfigure_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros_interface__srv__UpdateConfigure_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros_interface__srv__UpdateConfigure_Response__Sequence__are_equal(const ros_interface__srv__UpdateConfigure_Response__Sequence * lhs, const ros_interface__srv__UpdateConfigure_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros_interface__srv__UpdateConfigure_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros_interface__srv__UpdateConfigure_Response__Sequence__copy(
  const ros_interface__srv__UpdateConfigure_Response__Sequence * input,
  ros_interface__srv__UpdateConfigure_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros_interface__srv__UpdateConfigure_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros_interface__srv__UpdateConfigure_Response * data =
      (ros_interface__srv__UpdateConfigure_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros_interface__srv__UpdateConfigure_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros_interface__srv__UpdateConfigure_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros_interface__srv__UpdateConfigure_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
