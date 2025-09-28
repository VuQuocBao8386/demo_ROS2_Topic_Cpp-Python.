// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_serivce:srv/RequestData.idl
// generated code does not contain a copyright notice

#ifndef ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__TRAITS_HPP_
#define ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_serivce/srv/detail/request_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_serivce
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestData_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: ros_request_data
  {
    out << "ros_request_data: ";
    rosidl_generator_traits::value_to_yaml(msg.ros_request_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestData_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ros_request_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ros_request_data: ";
    rosidl_generator_traits::value_to_yaml(msg.ros_request_data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestData_Request & msg, bool use_flow_style = false)
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

}  // namespace ros_serivce

namespace rosidl_generator_traits
{

[[deprecated("use ros_serivce::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_serivce::srv::RequestData_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_serivce::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_serivce::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_serivce::srv::RequestData_Request & msg)
{
  return ros_serivce::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_serivce::srv::RequestData_Request>()
{
  return "ros_serivce::srv::RequestData_Request";
}

template<>
inline const char * name<ros_serivce::srv::RequestData_Request>()
{
  return "ros_serivce/srv/RequestData_Request";
}

template<>
struct has_fixed_size<ros_serivce::srv::RequestData_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_serivce::srv::RequestData_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_serivce::srv::RequestData_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros_serivce
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestData_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: send_success
  {
    out << "send_success: ";
    rosidl_generator_traits::value_to_yaml(msg.send_success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestData_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: send_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "send_success: ";
    rosidl_generator_traits::value_to_yaml(msg.send_success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestData_Response & msg, bool use_flow_style = false)
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

}  // namespace ros_serivce

namespace rosidl_generator_traits
{

[[deprecated("use ros_serivce::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_serivce::srv::RequestData_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_serivce::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_serivce::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_serivce::srv::RequestData_Response & msg)
{
  return ros_serivce::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_serivce::srv::RequestData_Response>()
{
  return "ros_serivce::srv::RequestData_Response";
}

template<>
inline const char * name<ros_serivce::srv::RequestData_Response>()
{
  return "ros_serivce/srv/RequestData_Response";
}

template<>
struct has_fixed_size<ros_serivce::srv::RequestData_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_serivce::srv::RequestData_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_serivce::srv::RequestData_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_serivce::srv::RequestData>()
{
  return "ros_serivce::srv::RequestData";
}

template<>
inline const char * name<ros_serivce::srv::RequestData>()
{
  return "ros_serivce/srv/RequestData";
}

template<>
struct has_fixed_size<ros_serivce::srv::RequestData>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_serivce::srv::RequestData_Request>::value &&
    has_fixed_size<ros_serivce::srv::RequestData_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_serivce::srv::RequestData>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_serivce::srv::RequestData_Request>::value &&
    has_bounded_size<ros_serivce::srv::RequestData_Response>::value
  >
{
};

template<>
struct is_service<ros_serivce::srv::RequestData>
  : std::true_type
{
};

template<>
struct is_service_request<ros_serivce::srv::RequestData_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_serivce::srv::RequestData_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_SERIVCE__SRV__DETAIL__REQUEST_DATA__TRAITS_HPP_
