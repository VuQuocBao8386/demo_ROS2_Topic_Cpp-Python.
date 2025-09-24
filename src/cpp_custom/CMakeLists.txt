cmake_minimum_required(VERSION 3.8)
project(cpp_custom)

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros_interface REQUIRED)

# Include directories
include_directories(
  include
  src
)

# Executable (main entry point only)
add_executable(main_node src/main.cpp

)

ament_target_dependencies(main_node rclcpp std_msgs ros_interface)

# Install executable
install(TARGETS
  main_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
