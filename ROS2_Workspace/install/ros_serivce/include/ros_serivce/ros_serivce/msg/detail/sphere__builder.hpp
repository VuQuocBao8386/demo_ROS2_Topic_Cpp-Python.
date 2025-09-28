// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_serivce:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef ROS_SERIVCE__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define ROS_SERIVCE__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_serivce/msg/detail/sphere__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_serivce
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::ros_serivce::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::ros_serivce::msg::Sphere radius(::ros_serivce::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_serivce::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::ros_serivce::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::ros_serivce::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_serivce::msg::Sphere>()
{
  return ros_serivce::msg::builder::Init_Sphere_center();
}

}  // namespace ros_serivce

#endif  // ROS_SERIVCE__MSG__DETAIL__SPHERE__BUILDER_HPP_
