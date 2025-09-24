// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_interface:srv/UpdateConfigure.idl
// generated code does not contain a copyright notice

#ifndef ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__TRAITS_HPP_
#define ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_interface/srv/detail/update_configure__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const UpdateConfigure_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: area
  {
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
    out << ", ";
  }

  // member: threshold_1
  {
    out << "threshold_1: ";
    rosidl_generator_traits::value_to_yaml(msg.threshold_1, out);
    out << ", ";
  }

  // member: threshold_2
  {
    out << "threshold_2: ";
    rosidl_generator_traits::value_to_yaml(msg.threshold_2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UpdateConfigure_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: area
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
    out << "\n";
  }

  // member: threshold_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "threshold_1: ";
    rosidl_generator_traits::value_to_yaml(msg.threshold_1, out);
    out << "\n";
  }

  // member: threshold_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "threshold_2: ";
    rosidl_generator_traits::value_to_yaml(msg.threshold_2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UpdateConfigure_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_interface

namespace rosidl_generator_traits
{

[[deprecated("use ros_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_interface::srv::UpdateConfigure_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interface::srv::UpdateConfigure_Request & msg)
{
  return ros_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interface::srv::UpdateConfigure_Request>()
{
  return "ros_interface::srv::UpdateConfigure_Request";
}

template<>
inline const char * name<ros_interface::srv::UpdateConfigure_Request>()
{
  return "ros_interface/srv/UpdateConfigure_Request";
}

template<>
struct has_fixed_size<ros_interface::srv::UpdateConfigure_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_interface::srv::UpdateConfigure_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_interface::srv::UpdateConfigure_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const UpdateConfigure_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UpdateConfigure_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UpdateConfigure_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_interface

namespace rosidl_generator_traits
{

[[deprecated("use ros_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_interface::srv::UpdateConfigure_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_interface::srv::UpdateConfigure_Response & msg)
{
  return ros_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_interface::srv::UpdateConfigure_Response>()
{
  return "ros_interface::srv::UpdateConfigure_Response";
}

template<>
inline const char * name<ros_interface::srv::UpdateConfigure_Response>()
{
  return "ros_interface/srv/UpdateConfigure_Response";
}

template<>
struct has_fixed_size<ros_interface::srv::UpdateConfigure_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_interface::srv::UpdateConfigure_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_interface::srv::UpdateConfigure_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_interface::srv::UpdateConfigure>()
{
  return "ros_interface::srv::UpdateConfigure";
}

template<>
inline const char * name<ros_interface::srv::UpdateConfigure>()
{
  return "ros_interface/srv/UpdateConfigure";
}

template<>
struct has_fixed_size<ros_interface::srv::UpdateConfigure>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_interface::srv::UpdateConfigure_Request>::value &&
    has_fixed_size<ros_interface::srv::UpdateConfigure_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_interface::srv::UpdateConfigure>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_interface::srv::UpdateConfigure_Request>::value &&
    has_bounded_size<ros_interface::srv::UpdateConfigure_Response>::value
  >
{
};

template<>
struct is_service<ros_interface::srv::UpdateConfigure>
  : std::true_type
{
};

template<>
struct is_service_request<ros_interface::srv::UpdateConfigure_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_interface::srv::UpdateConfigure_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_INTERFACE__SRV__DETAIL__UPDATE_CONFIGURE__TRAITS_HPP_
