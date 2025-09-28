// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_serivce:srv/UpdateConfig.idl
// generated code does not contain a copyright notice

#ifndef ROS_SERIVCE__SRV__DETAIL__UPDATE_CONFIG__BUILDER_HPP_
#define ROS_SERIVCE__SRV__DETAIL__UPDATE_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_serivce/srv/detail/update_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_serivce
{

namespace srv
{

namespace builder
{

class Init_UpdateConfig_Request_threshold_2
{
public:
  explicit Init_UpdateConfig_Request_threshold_2(::ros_serivce::srv::UpdateConfig_Request & msg)
  : msg_(msg)
  {}
  ::ros_serivce::srv::UpdateConfig_Request threshold_2(::ros_serivce::srv::UpdateConfig_Request::_threshold_2_type arg)
  {
    msg_.threshold_2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Request msg_;
};

class Init_UpdateConfig_Request_threshold_1
{
public:
  explicit Init_UpdateConfig_Request_threshold_1(::ros_serivce::srv::UpdateConfig_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfig_Request_threshold_2 threshold_1(::ros_serivce::srv::UpdateConfig_Request::_threshold_1_type arg)
  {
    msg_.threshold_1 = std::move(arg);
    return Init_UpdateConfig_Request_threshold_2(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Request msg_;
};

class Init_UpdateConfig_Request_area
{
public:
  explicit Init_UpdateConfig_Request_area(::ros_serivce::srv::UpdateConfig_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfig_Request_threshold_1 area(::ros_serivce::srv::UpdateConfig_Request::_area_type arg)
  {
    msg_.area = std::move(arg);
    return Init_UpdateConfig_Request_threshold_1(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Request msg_;
};

class Init_UpdateConfig_Request_mode
{
public:
  explicit Init_UpdateConfig_Request_mode(::ros_serivce::srv::UpdateConfig_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateConfig_Request_area mode(::ros_serivce::srv::UpdateConfig_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_UpdateConfig_Request_area(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Request msg_;
};

class Init_UpdateConfig_Request_command
{
public:
  Init_UpdateConfig_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConfig_Request_mode command(::ros_serivce::srv::UpdateConfig_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_UpdateConfig_Request_mode(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_serivce::srv::UpdateConfig_Request>()
{
  return ros_serivce::srv::builder::Init_UpdateConfig_Request_command();
}

}  // namespace ros_serivce


namespace ros_serivce
{

namespace srv
{

namespace builder
{

class Init_UpdateConfig_Response_message
{
public:
  explicit Init_UpdateConfig_Response_message(::ros_serivce::srv::UpdateConfig_Response & msg)
  : msg_(msg)
  {}
  ::ros_serivce::srv::UpdateConfig_Response message(::ros_serivce::srv::UpdateConfig_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Response msg_;
};

class Init_UpdateConfig_Response_success
{
public:
  Init_UpdateConfig_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConfig_Response_message success(::ros_serivce::srv::UpdateConfig_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UpdateConfig_Response_message(msg_);
  }

private:
  ::ros_serivce::srv::UpdateConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_serivce::srv::UpdateConfig_Response>()
{
  return ros_serivce::srv::builder::Init_UpdateConfig_Response_success();
}

}  // namespace ros_serivce

#endif  // ROS_SERIVCE__SRV__DETAIL__UPDATE_CONFIG__BUILDER_HPP_
