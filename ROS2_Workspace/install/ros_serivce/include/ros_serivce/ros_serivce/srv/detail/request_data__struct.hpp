// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_serivce:srv/RequestData.idl
// generated code does not contain a copyright notice

#ifndef ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__STRUCT_HPP_
#define ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_serivce__srv__RequestData_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros_serivce__srv__RequestData_Request __declspec(deprecated)
#endif

namespace ros_serivce
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestData_Request_
{
  using Type = RequestData_Request_<ContainerAllocator>;

  explicit RequestData_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ros_request_data = false;
    }
  }

  explicit RequestData_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ros_request_data = false;
    }
  }

  // field types and members
  using _ros_request_data_type =
    bool;
  _ros_request_data_type ros_request_data;

  // setters for named parameter idiom
  Type & set__ros_request_data(
    const bool & _arg)
  {
    this->ros_request_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_serivce::srv::RequestData_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_serivce::srv::RequestData_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_serivce::srv::RequestData_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_serivce::srv::RequestData_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_serivce__srv__RequestData_Request
    std::shared_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_serivce__srv__RequestData_Request
    std::shared_ptr<ros_serivce::srv::RequestData_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestData_Request_ & other) const
  {
    if (this->ros_request_data != other.ros_request_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestData_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestData_Request_

// alias to use template instance with default allocator
using RequestData_Request =
  ros_serivce::srv::RequestData_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_serivce


#ifndef _WIN32
# define DEPRECATED__ros_serivce__srv__RequestData_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros_serivce__srv__RequestData_Response __declspec(deprecated)
#endif

namespace ros_serivce
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestData_Response_
{
  using Type = RequestData_Response_<ContainerAllocator>;

  explicit RequestData_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_success = false;
    }
  }

  explicit RequestData_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    ros_serivce::srv::RequestData_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_serivce::srv::RequestData_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_serivce::srv::RequestData_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_serivce::srv::RequestData_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_serivce__srv__RequestData_Response
    std::shared_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_serivce__srv__RequestData_Response
    std::shared_ptr<ros_serivce::srv::RequestData_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestData_Response_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    if (this->send_success != other.send_success) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestData_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestData_Response_

// alias to use template instance with default allocator
using RequestData_Response =
  ros_serivce::srv::RequestData_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_serivce

namespace ros_serivce
{

namespace srv
{

struct RequestData
{
  using Request = ros_serivce::srv::RequestData_Request;
  using Response = ros_serivce::srv::RequestData_Response;
};

}  // namespace srv

}  // namespace ros_serivce

#endif  // ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__STRUCT_HPP_
