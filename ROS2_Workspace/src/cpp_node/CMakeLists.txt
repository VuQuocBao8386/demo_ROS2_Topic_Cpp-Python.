cmake_minimum_required(VERSION 3.8)
project(cpp_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ros_serivce REQUIRED)   # your custom srv package

# Collect all .cpp files
file(GLOB_RECURSE SOURCES
  src/main.cpp
  src/demo/communication/*.cpp
  src/demo/database/*.cpp
  src/demo/engine/*.cpp
  src/demo/setup/*.cpp
  src/demo/statemachine/*.cpp
)

# Create executable (must be before target_include_directories!)
add_executable(request ${SOURCES})

# Include directories (so you can #include "demo/database/DataBase.hpp")
target_include_directories(request PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>
)

# Link dependencies
ament_target_dependencies(request
  rclcpp
  ros_serivce
)

# Install binary
install(TARGETS request
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
