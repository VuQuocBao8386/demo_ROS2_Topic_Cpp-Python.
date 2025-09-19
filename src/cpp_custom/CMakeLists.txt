cmake_minimum_required(VERSION 3.8)
project(cpp_custom)

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros_interface REQUIRED)


include_directories(include)

# Core system library (Engine, StateMachine, Setup, Database, UART)
add_library(core_system
    src/communication/ros_Service.cpp
    src/communication/serial_UART.cpp
    src/dataBase/StoreData.cpp
    src/enigne/Engine.cpp
    src/setup/Setup.cpp
    src/stateMachine/StateMachine.cpp
)

target_include_directories(core_system PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(core_system rclcpp std_msgs ros_interface)

# Executable (main entry point)
add_executable(main_node src/main.cpp)
target_link_libraries(main_node core_system)
ament_target_dependencies(main_node rclcpp std_msgs ros_interface)

install(TARGETS
  core_system
  main_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
