// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_interface:srv/UpdateConfigure.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__BUILDER_HPP_
#define ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_interface/srv/detail/update_configure__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_interface
{

namespace srv
{

namespace builder
{

class Init_UpdateConfigure_Request_threshold_2
{
public:
  explicit Init_UpdateConfigure_Request_threshold_2(::ros_interface::srv::UpdateConfigure_Request & msg)
  : msg_(msg)
  {}
  ::ros_interface::srv::UpdateConfigure_Request threshold_2(::ros_interface::srv::UpdateConfigure_Request::_threshold_2_type arg)
  {
    msg_.threshold_2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Request msg_;
};

class Init_UpdateConfigure_Request_threshold_1
{
public:
  explicit Init_UpdateConfigure_Request_threshold_1(::ros_interface::srv::UpdateConfigure_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfigure_Request_threshold_2 threshold_1(::ros_interface::srv::UpdateConfigure_Request::_threshold_1_type arg)
  {
    msg_.threshold_1 = std::move(arg);
    return Init_UpdateConfigure_Request_threshold_2(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Request msg_;
};

class Init_UpdateConfigure_Request_area
{
public:
  explicit Init_UpdateConfigure_Request_area(::ros_interface::srv::UpdateConfigure_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfigure_Request_threshold_1 area(::ros_interface::srv::UpdateConfigure_Request::_area_type arg)
  {
    msg_.area = std::move(arg);
    return Init_UpdateConfigure_Request_threshold_1(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Request msg_;
};

class Init_UpdateConfigure_Request_mode
{
public:
  explicit Init_UpdateConfigure_Request_mode(::ros_interface::srv::UpdateConfigure_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfigure_Request_area mode(::ros_interface::srv::UpdateConfigure_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_UpdateConfigure_Request_area(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Request msg_;
};

class Init_UpdateConfigure_Request_command
{
public:
  explicit Init_UpdateConfigure_Request_command(::ros_interface::srv::UpdateConfigure_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfigure_Request_mode command(::ros_interface::srv::UpdateConfigure_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_UpdateConfigure_Request_mode(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Request msg_;
};

class Init_UpdateConfigure_Request_update
{
public:
  Init_UpdateConfigure_Request_update()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConfigure_Request_command update(::ros_interface::srv::UpdateConfigure_Request::_update_type arg)
  {
    msg_.update = std::move(arg);
    return Init_UpdateConfigure_Request_command(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interface::srv::UpdateConfigure_Request>()
{
  return ros_interface::srv::builder::Init_UpdateConfigure_Request_update();
}

}  // namespace ros_interface


namespace ros_interface
{

namespace srv
{

namespace builder
{

class Init_UpdateConfigure_Response_message
{
public:
  explicit Init_UpdateConfigure_Response_message(::ros_interface::srv::UpdateConfigure_Response & msg)
  : msg_(msg)
  {}
  ::ros_interface::srv::UpdateConfigure_Response message(::ros_interface::srv::UpdateConfigure_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Response msg_;
};

class Init_UpdateConfigure_Response_success
{
public:
  Init_UpdateConfigure_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConfigure_Response_message success(::ros_interface::srv::UpdateConfigure_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UpdateConfigure_Response_message(msg_);
  }

private:
  ::ros_interface::srv::UpdateConfigure_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_interface::srv::UpdateConfigure_Response>()
{
  return ros_interface::srv::builder::Init_UpdateConfigure_Response_success();
}

}  // namespace ros_interface

#endif  // ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__BUILDER_HPP_
