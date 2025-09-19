#include "ros_Service.hpp"

//__________________________________PUBLIC METHODS__________________________________//
void Ros_Cpp::send_update_config(const std::string &command,
                                 const std::string &mode,
                                 int64_t area,
                                 int32_t threshold_1,
                                 int32_t threshold_2)
{
    if (!services_available) {
        RCLCPP_WARN(this->get_logger(), "Services not available, cannot send update config");
        return;
    }

    auto request = std::make_shared<UpdateConfigure::Request>();

    if (command == "shutdown") {
        request->command = "shutdown";
        request->update = false;
        RCLCPP_INFO(this->get_logger(), "Shutting down configuration...");
    }
    else if (command == "reset") {
        request->command = "reset";
        request->update = false;
        RCLCPP_INFO(this->get_logger(), "Sending reset configuration...");
    }
    else {
        request->update = true;
        request->mode = mode;
        request->area = area;
        request->threshold_1 = threshold_1;
        request->threshold_2 = threshold_2;
        RCLCPP_INFO(this->get_logger(), "Sending update configuration...");
    }

    try {
        auto future = update_client_->async_send_request(request);
        handle_update_response(future);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Failed to send update config: %s", e.what());
    }
}

void Ros_Cpp::send_process_request(const std::string &command)
{
    if (!services_available) {
        RCLCPP_WARN(this->get_logger(), "Services not available, cannot send process request");
        return;
    }

    auto request = std::make_shared<ProcessRequest::Request>();
    request->start_communication = command;
    
    try {
        auto future = process_client_->async_send_request(request);
        RCLCPP_INFO(this->get_logger(), "Sent process request: %s", command.c_str());
        handle_process_response(future);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Failed to send process request: %s", e.what());
    }
}

//______________________________Getter and Setter_________________________________//
void Ros_Cpp::set_data(int data)
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    py_data_.push_back(data);
}

const std::vector<int>& Ros_Cpp::get_data() const
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    return py_data_;
}

//__________________________________PRIVATE METHODS__________________________________//

bool Ros_Cpp::check_services()
{
    bool update_available = update_client_->wait_for_service(std::chrono::seconds(0));
    bool process_available = process_client_->wait_for_service(std::chrono::seconds(0));
    
    bool all_available = update_available && process_available;
    
    if (all_available != services_available) {
        services_available = all_available;
        if (services_available) {
            RCLCPP_INFO(this->get_logger(), "All services are now available");
            service_check_timer_->cancel(); // Stop checking once services are available
            return true;
        } else {
            RCLCPP_WARN(this->get_logger(), "Services unavailable");
            return false;
        }
    }
}



void Ros_Cpp::handle_update_response(rclcpp::Client<UpdateConfigure>::SharedFuture future)
{
    try {
        auto result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, std::chrono::seconds(5));
        
        if (result == rclcpp::FutureReturnCode::SUCCESS) {
            auto response = future.get();

            if (response) {
                RCLCPP_INFO(this->get_logger(), "Response: success=%s, message=%s",
                            response->success ? "true" : "false",
                            response->message.c_str());
            } else {
                RCLCPP_ERROR(this->get_logger(), "Response was null!");
            }

        }
        else if (result == rclcpp::FutureReturnCode::TIMEOUT) {
            RCLCPP_ERROR(this->get_logger(), "Service call timed out!");
        }
        
        else {
            RCLCPP_ERROR(this->get_logger(), "Service call failed!");
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Exception in handle_update_response: %s", e.what());
    }
}




void Ros_Cpp::handle_process_response(rclcpp::Client<ProcessRequest>::SharedFuture future)
{
    try {
        auto result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, std::chrono::seconds(5));

        if (result == rclcpp::FutureReturnCode::SUCCESS) {
            auto response = future.get();

            if (response->send_success) {
                RCLCPP_INFO(this->get_logger(), "Process request succeeded");

                if (!response->data.empty()) {
                    std::cout << "Data received: ";
                    
                    // Clear and update data in thread-safe manner
                    {
                        std::lock_guard<std::mutex> lock(data_mutex_);
                        py_data_.clear();
                        py_data_.reserve(response->data.size());
                        
                        for (size_t i = 0; i < response->data.size(); ++i) {
                            std::cout << response->data[i];
                            py_data_.push_back(response->data[i]);
                            if (i < response->data.size() - 1) std::cout << ", ";
                        }
                    }
                    
                    std::cout << std::endl;
                    RCLCPP_INFO(this->get_logger(), "Received %zu data elements", response->data.size());
                } else {
                    RCLCPP_INFO(this->get_logger(), "No data received");
                }
            }
            else {
                RCLCPP_WARN(this->get_logger(), "Process request failed");
            }
        }
        else if (result == rclcpp::FutureReturnCode::TIMEOUT) {
            RCLCPP_ERROR(this->get_logger(), "Service call timed out!");
        }
        else {
            RCLCPP_ERROR(this->get_logger(), "Service call failed!");
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Exception in handle_process_response: %s", e.what());
    }
}