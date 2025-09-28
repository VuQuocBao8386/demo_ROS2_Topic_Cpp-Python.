#include "ros_Service.hpp"

// --- Update Config Request ---
bool Ros_Cpp::send_update_config(const std::string &command)
{
    if (!update_client_->wait_for_service(std::chrono::seconds(2))) {
        RCLCPP_WARN(this->get_logger(), "Update_Config service not available");
        return false;
    }

    auto request = std::make_shared<UpdateConfig::Request>();
    if (command == "shutdown" || command == "reset")
    {
         request->command = command;
    }
    else if(command == "update" && _dataBase_) {
        request->command = "update"; // set the command explicitly
        std::lock_guard<std::mutex> lock(data_mutex_);
        request->mode        = _dataBase_->get_Ros2_Mode();
        request->area        = _dataBase_->get_Ros2_Area();
        request->threshold_1 = _dataBase_->get_Ros2_Thresh1();
        request->threshold_2 = _dataBase_->get_Ros2_thresh2();
}

    else
    {
        RCLCPP_WARN(this->get_logger(), "[ROS2]____Wrong command_____");
        return false;

    }

    auto future = update_client_->async_send_request(request);
    auto result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);

    if (result == rclcpp::FutureReturnCode::SUCCESS) {
        auto response = future.get();
        RCLCPP_INFO(this->get_logger(), "Update response: success=%s, msg=%s",
                    response->success ? "true" : "false",
                    response->message.c_str());
        return response->success;
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to get update response");
        return false;
    }
}

// --- Process Request ---
bool Ros_Cpp::send_request_data()
{
    if (!request_client_->wait_for_service(std::chrono::seconds(2))) {
        RCLCPP_WARN(this->get_logger(), "Process_Communication service not available");
        return false;
    }

    auto request = std::make_shared<RequestData::Request>();
    request->ros_request_data = true;

    auto future = request_client_->async_send_request(request);
    auto result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);

    if (result == rclcpp::FutureReturnCode::SUCCESS) {
        auto response = future.get();
        if (response->send_success) {
            RCLCPP_INFO(this->get_logger(), "Process request succeeded");

            if (!response->data.empty()) {
                std::lock_guard<std::mutex> lock(data_mutex_);
                for (auto &d : response->data) {
                    
                    // Store data here to save into DATABASE directly
                    _dataBase_->add_data_py(d); 
                }
                RCLCPP_INFO(this->get_logger(), "Stored %zu data elements", response->data.size());
            }
            return true;
        } else {
            RCLCPP_WARN(this->get_logger(), "Process request failed");
            return false;
        }
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to get process response");
        return false;
    }
}
