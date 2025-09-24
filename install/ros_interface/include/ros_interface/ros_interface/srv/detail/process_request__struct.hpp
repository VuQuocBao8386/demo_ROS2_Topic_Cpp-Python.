// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_interface:srv/ProcessRequest.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__STRUCT_HPP_
#define ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_interface__srv__ProcessRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros_interface__srv__ProcessRequest_Request __declspec(deprecated)
#endif

namespace ros_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProcessRequest_Request_
{
  using Type = ProcessRequest_Request_<ContainerAllocator>;

  explicit ProcessRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_requestdata = false;
    }
  }

  explicit ProcessRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_requestdata = false;
    }
  }

  // field types and members
  using _start_requestdata_type =
    bool;
  _start_requestdata_type start_requestdata;

  // setters for named parameter idiom
  Type & set__start_requestdata(
    const bool & _arg)
  {
    this->start_requestdata = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interface::srv::ProcessRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interface::srv::ProcessRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::ProcessRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::ProcessRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interface__srv__ProcessRequest_Request
    std::shared_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interface__srv__ProcessRequest_Request
    std::shared_ptr<ros_interface::srv::ProcessRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessRequest_Request_ & other) const
  {
    if (this->start_requestdata != other.start_requestdata) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessRequest_Request_

// alias to use template instance with default allocator
using ProcessRequest_Request =
  ros_interface::srv::ProcessRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interface


#ifndef _WIN32
# define DEPRECATED__ros_interface__srv__ProcessRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros_interface__srv__ProcessRequest_Response __declspec(deprecated)
#endif

namespace ros_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProcessRequest_Response_
{
  using Type = ProcessRequest_Response_<ContainerAllocator>;

  explicit ProcessRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_success = false;
    }
  }

  explicit ProcessRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_success = false;
    }
  }

  // field types and members
  using _data_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _data_type data;
  using _send_success_type =
    bool;
  _send_success_type send_success;

  // setters for named parameter idiom
  Type & set__data(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__send_success(
    const bool & _arg)
  {
    this->send_success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_interface::srv::ProcessRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_interface::srv::ProcessRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::ProcessRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_interface::srv::ProcessRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_interface__srv__ProcessRequest_Response
    std::shared_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_interface__srv__ProcessRequest_Response
    std::shared_ptr<ros_interface::srv::ProcessRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessRequest_Response_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    if (this->send_success != other.send_success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessRequest_Response_

// alias to use template instance with default allocator
using ProcessRequest_Response =
  ros_interface::srv::ProcessRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_interface

namespace ros_interface
{

namespace srv
{

struct ProcessRequest
{
  using Request = ros_interface::srv::ProcessRequest_Request;
  using Response = ros_interface::srv::ProcessRequest_Response;
};

}  // namespace srv

}  // namespace ros_interface

#endif  // ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__STRUCT_HPP_
