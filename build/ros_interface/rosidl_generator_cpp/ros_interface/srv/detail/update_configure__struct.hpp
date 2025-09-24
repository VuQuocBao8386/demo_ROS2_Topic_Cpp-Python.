// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_interface:srv/UpdateConfigure.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__STRUCT_HPP_
#define ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_interface__srv__UpdateConfigure_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros_interface__srv__UpdateConfigure_Request __declspec(deprecated)
#endif

namespace ros_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UpdateConfigure_Request_
{
  using Type = UpdateConfigure_Request_<ContainerAllocator>;

  explicit UpdateConfigure_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->mode = "";
      this->area = 0ll;
      this->threshold_1 = 0l;
      this->threshold_2 = 0l;
    }
  }

  explicit UpdateConfigure_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc),
    mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->mode = "";
      this->area = 0ll;
      this->threshold_1 = 0l;
      this->threshold_2 = 0l;
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _area_type =
    int64_t;
  _area_type area;
  using _threshold_1_type =
    int32_t;
  _threshold_1_type threshold_1;
  using _threshold_2_type =
    int32_t;
  _threshold_2_type threshold_2;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__area(
    const int64_t & _arg)
  {
    this->area = _arg;
    return *this;
  }
  Type & set__threshold_1(
    const int32_t & _arg)
  {
    this->threshold_1 = _arg;
    return *this;
  }
  Type & set__threshold_2(
    const int32_t & _arg)
  {
    this->threshold_2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interface__srv__UpdateConfigure_Request
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interface__srv__UpdateConfigure_Request
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdateConfigure_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->area != other.area) {
      return false;
    }
    if (this->threshold_1 != other.threshold_1) {
      return false;
    }
    if (this->threshold_2 != other.threshold_2) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdateConfigure_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdateConfigure_Request_

// alias to use template instance with default allocator
using UpdateConfigure_Request =
  ros_interface::srv::UpdateConfigure_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interface


#ifndef _WIN32
# define DEPRECATED__ros_interface__srv__UpdateConfigure_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros_interface__srv__UpdateConfigure_Response __declspec(deprecated)
#endif

namespace ros_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UpdateConfigure_Response_
{
  using Type = UpdateConfigure_Response_<ContainerAllocator>;

  explicit UpdateConfigure_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit UpdateConfigure_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interface__srv__UpdateConfigure_Response
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interface__srv__UpdateConfigure_Response
    std::shared_ptr<ros_interface::srv::UpdateConfigure_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdateConfigure_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdateConfigure_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdateConfigure_Response_

// alias to use template instance with default allocator
using UpdateConfigure_Response =
  ros_interface::srv::UpdateConfigure_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interface

namespace ros_interface
{

namespace srv
{

struct UpdateConfigure
{
  using Request = ros_interface::srv::UpdateConfigure_Request;
  using Response = ros_interface::srv::UpdateConfigure_Response;
};

}  // namespace srv

}  // namespace ros_interface

#endif  // ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__STRUCT_HPP_
