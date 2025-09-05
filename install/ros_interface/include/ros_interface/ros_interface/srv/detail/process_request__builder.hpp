// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_interface:srv/ProcessRequest.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__BUILDER_HPP_
#define ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_interface/srv/detail/process_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_interface
{

namespace srv
{

namespace builder
{

class Init_ProcessRequest_Request_start_communication
{
public:
  Init_ProcessRequest_Request_start_communication()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_interface::srv::ProcessRequest_Request start_communication(::ros_interface::srv::ProcessRequest_Request::_start_communication_type arg)
  {
    msg_.start_communication = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interface::srv::ProcessRequest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interface::srv::ProcessRequest_Request>()
{
  return ros_interface::srv::builder::Init_ProcessRequest_Request_start_communication();
}

}  // namespace ros_interface


namespace ros_interface
{

namespace srv
{

namespace builder
{

class Init_ProcessRequest_Response_send_success
{
public:
  explicit Init_ProcessRequest_Response_send_success(::ros_interface::srv::ProcessRequest_Response & msg)
  : msg_(msg)
  {}
  ::ros_interface::srv::ProcessRequest_Response send_success(::ros_interface::srv::ProcessRequest_Response::_send_success_type arg)
  {
    msg_.send_success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interface::srv::ProcessRequest_Response msg_;
};

class Init_ProcessRequest_Response_data
{
public:
  Init_ProcessRequest_Response_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessRequest_Response_send_success data(::ros_interface::srv::ProcessRequest_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_ProcessRequest_Response_send_success(msg_);
  }

private:
  ::ros_interface::srv::ProcessRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interface::srv::ProcessRequest_Response>()
{
  return ros_interface::srv::builder::Init_ProcessRequest_Response_data();
}

}  // namespace ros_interface

#endif  // ROS_INTERFACE__SRV__DETAIL__PROCESS_REQUEST__BUILDER_HPP_
