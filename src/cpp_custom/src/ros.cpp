#include "rclcpp/rclcpp.hpp"
#include "ros_interface/srv/update_configure.hpp"
#include "ros_interface/srv/process_request.hpp"

#include <memory>
#include <chrono>
#include <vector>
#include <iostream>
#include <string>

using UpdateConfigure = ros_interface::srv::UpdateConfigure;
using ProcessRequest = ros_interface::srv::ProcessRequest;

class ClientNode : public rclcpp::Node
{
public:
    ClientNode() : Node("client_node")
    {
        // Use the same service names as Python node
        update_client_ = this->create_client<UpdateConfigure>("Update_Config");
        process_client_ = this->create_client<ProcessRequest>("Process_Communication");

        // Wait for services
        while (!update_client_->wait_for_service(std::chrono::seconds(1)) ||
               !process_client_->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_INFO(this->get_logger(), "Waiting for services...");
        }
    }

// ______________________UPDATE Configuration__________________________
    
    void send_update_config(const std::string& command, const std::string& mode, 
                            int64_t area, int32_t threshold_1, int32_t threshold_2)
    {
        auto request = std::make_shared<UpdateConfigure::Request>();

        if (command == "shutdown")
        {
            request->command = "shutdown";
            request->update = false;
            request->mode = "";  // Set empty mode for shutdown
            request->area = 0;
            request->threshold_1 = 0;
            request->threshold_2 = 0;
            RCLCPP_INFO(this->get_logger(), "Shutting down configuration request...");
        }
        else if (command == "reset")
        {
            request->command = "reset";
            RCLCPP_INFO(this->get_logger(), "Sending reset configuration request...");
        }
        else
        {
            request->command = command;
            request->update = true;
            request->mode = mode;
            request->area = area;
            request->threshold_1 = threshold_1;
            request->threshold_2 = threshold_2;
            RCLCPP_INFO(this->get_logger(), "Sending update configuration request...");
        }
        
        auto future = update_client_->async_send_request(request);

        // Wait until response is received or timeout
        auto result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, std::chrono::seconds(5));

        if (result == rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            if (response)
            {
                RCLCPP_INFO(this->get_logger(), "Response: success=%s, message=%s",
                            response->success ? "true" : "false",
                            response->message.c_str());
            }
            else
            {
                RCLCPP_ERROR(this->get_logger(), "Response was null!");
            }
        }
        else if (result == rclcpp::FutureReturnCode::TIMEOUT)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call timed out!");
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed!");
        }
    }

// Overloaded version for shutdown and reset commands without parameters
    void send_update_config(const std::string& command)
    {
        if (command == "shutdown")
        {
            send_update_config("shutdown", "", 0, 0, 0);
        }
        else if (command == "reset")
        {
            send_update_config("reset", "", 0, 0, 0);
        }
        else
        {
            RCLCPP_WARN(this->get_logger(), "Unknown command: %s", command.c_str());
        }
    }

// ______________________PROCESS Control__________________________
    
    void send_process_request(const std::string& command)
    {
        auto request = std::make_shared<ProcessRequest::Request>();
        request->start_communication = command;

        auto future = process_client_->async_send_request(request);
        RCLCPP_INFO(this->get_logger(), "Sent process request: %s", command.c_str());

        // Wait for response
        auto result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, std::chrono::seconds(5));

        if (result == rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            
            if (response->send_success)
            {
                RCLCPP_INFO(this->get_logger(), "Request succeeded");
                
                // Print data if available
                if (!response->data.empty())
                {
                    std::cout << "Data received: ";
                    for (size_t i = 0; i < response->data.size(); ++i) {
                        std::cout << response->data[i];
                        if (i < response->data.size() - 1) {
                            std::cout << ", ";
                        }
                    }
                    std::cout << std::endl;
                    RCLCPP_INFO(this->get_logger(), "Received %zu data elements", response->data.size());
                }
                else
                {
                    RCLCPP_INFO(this->get_logger(), "No data received");
                }
            }
            else
            {
                RCLCPP_WARN(this->get_logger(), "Request failed");
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed or timed out!");
        }
    }

private:
    rclcpp::Client<UpdateConfigure>::SharedPtr update_client_;
    rclcpp::Client<ProcessRequest>::SharedPtr process_client_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ClientNode>();
    int choice;
    bool running = true;
    
    while (running)
    {
        std::cout << "\n=== Menu ===" << std::endl;
        std::cout << "1: Update configuration" << std::endl;
        std::cout << "2: Shut down" << std::endl;
        std::cout << "3: Reset" << std::endl;
        std::cout << "4: Request data" << std::endl;
        std::cout << "5: Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: // Update config
            {
                std::string mode;
                int64_t area;
                int32_t threshold_1, threshold_2;
                
                std::cout << "Enter mode: ";
                std::cin >> mode;
                std::cout << "Enter area: ";
                std::cin >> area;
                std::cout << "Enter threshold 1: ";
                std::cin >> threshold_1;
                std::cout << "Enter threshold 2: ";
                std::cin >> threshold_2;
                
                node->send_update_config("update", mode, area, threshold_1, threshold_2);
            }
            break;
        
        case 2: // shutdown
            node->send_update_config("shutdown");
            break;
        
        case 3: // Reset
            node->send_update_config("reset");
            break;
        
        case 4: // Request data
            node->send_process_request("start");
            break;
        
        case 5: // Exit
            running = false;
            std::cout << "Exiting..." << std::endl;
            break;

        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            // Clear invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    
    rclcpp::shutdown();
    return 0;
}