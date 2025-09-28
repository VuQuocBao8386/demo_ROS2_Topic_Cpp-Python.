// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_serivce:srv/RequestData.idl
// generated code does not contain a copyright notice

#ifndef ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__BUILDER_HPP_
#define ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_serivce/srv/detail/request_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_serivce
{

namespace srv
{

namespace builder
{

class Init_RequestData_Request_ros_request_data
{
public:
  Init_RequestData_Request_ros_request_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_serivce::srv::RequestData_Request ros_request_data(::ros_serivce::srv::RequestData_Request::_ros_request_data_type arg)
  {
    msg_.ros_request_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_serivce::srv::RequestData_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_serivce::srv::RequestData_Request>()
{
  return ros_serivce::srv::builder::Init_RequestData_Request_ros_request_data();
}

}  // namespace ros_serivce


namespace ros_serivce
{

namespace srv
{

namespace builder
{

class Init_RequestData_Response_send_success
{
public:
  explicit Init_RequestData_Response_send_success(::ros_serivce::srv::RequestData_Response & msg)
  : msg_(msg)
  {}
  ::ros_serivce::srv::RequestData_Response send_success(::ros_serivce::srv::RequestData_Response::_send_success_type arg)
  {
    msg_.send_success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_serivce::srv::RequestData_Response msg_;
};

class Init_RequestData_Response_data
{
public:
  Init_RequestData_Response_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestData_Response_send_success data(::ros_serivce::srv::RequestData_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_RequestData_Response_send_success(msg_);
  }

private:
  ::ros_serivce::srv::RequestData_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_serivce::srv::RequestData_Response>()
{
  return ros_serivce::srv::builder::Init_RequestData_Response_data();
}

}  // namespace ros_serivce

#endif  // ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__BUILDER_HPP_
