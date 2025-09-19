#ifndef ROS_HPP
#define ROS_HPP


#pragma once

#include "rclcpp/rclcpp.hpp"
#include "ros_interface/srv/update_configure.hpp"
#include "ros_interface/srv/process_request.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <chrono>
#include <vector>
#include <functional>
#include <atomic>

using UpdateConfigure = ros_interface::srv::UpdateConfigure;
using ProcessRequest = ros_interface::srv::ProcessRequest;

class Ros_Cpp : public rclcpp::Node
{
public:
    Ros_Cpp() : Node("client_node")
    {
        update_client_  = this->create_client<UpdateConfigure>("Update_Config");
        process_client_ = this->create_client<ProcessRequest>("Process_Communication");

        // Wait for services asynchronously to avoid blocking constructor
        service_check_timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            [this]() { this->check_services(); });
    }
    
    // Service availability flag
    std::atomic<bool> services_available{false};

    void send_update_config(const std::string& command, const std::string& mode = "", 
                            int64_t area = 0, int32_t threshold_1 = 0, int32_t threshold_2 = 0);

    void send_process_request(const std::string& command);


    // Check service availability
    bool check_services();

    // Setter and Getter
    void set_data(int data);
    const std::vector<int>& get_data() const;

private:
    // Service clients
    rclcpp::Client<UpdateConfigure>::SharedPtr update_client_;
    rclcpp::Client<ProcessRequest>::SharedPtr process_client_;
    
    // Timer for service availability checking
    rclcpp::TimerBase::SharedPtr service_check_timer_;
      
    void handle_update_response(rclcpp::Client<UpdateConfigure>::SharedFuture future);
    void handle_process_response(rclcpp::Client<ProcessRequest>::SharedFuture future);



    // Store Data
    std::vector<int> py_data_;
    mutable std::mutex data_mutex_; // For thread-safe data access

};

#endif