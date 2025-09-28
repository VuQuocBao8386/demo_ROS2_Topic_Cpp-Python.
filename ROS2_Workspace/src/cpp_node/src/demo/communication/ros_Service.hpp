#ifndef ROS_HPP
#define ROS_HPP

#pragma once
#include "rclcpp/rclcpp.hpp"
#include "ros_serivce/srv/update_config.hpp"
#include "ros_serivce/srv/request_data.hpp"

#include "demo/database/DataBase.hpp"

#include <memory>
#include <string>
#include <chrono>
#include <mutex>
#include <atomic>

using UpdateConfig = ros_serivce::srv::UpdateConfig;
using RequestData  = ros_serivce::srv::RequestData;

class Ros_Cpp : public rclcpp::Node
{
public:
    Ros_Cpp(std::shared_ptr<DataBase> db)
        : Node("client_node"), _dataBase_(std::move(db)){}


    bool Ros_Connect()
    {
        update_client_  = this->create_client<UpdateConfig>("UpdateConfig");
        request_client_ = this->create_client<RequestData>("RequestData");

        auto wait_time = std::chrono::seconds(0);
        // while (!update_client_->wait_for_service(wait_time) && rclcpp::ok());
        // while (!request_client_->wait_for_service(wait_time) && rclcpp::ok());
    // Check if services are available immediately
        const bool update_ok = update_client_->wait_for_service(wait_time);
        const bool request_ok = request_client_->wait_for_service(wait_time);
        
        return update_ok && request_ok;
    }  
 

    // --- Service calls ---
    bool send_update_config(const std::string& command);
    bool send_request_data();
    
private:
    // Service clients
    rclcpp::Client<UpdateConfig>::SharedPtr update_client_;
    rclcpp::Client<RequestData>::SharedPtr request_client_;


    // Database
    std::shared_ptr<DataBase> _dataBase_;
    mutable std::mutex data_mutex_;


};

#endif
