#include "rclcpp/rclcpp.hpp"
#include "ros_interface/srv/update_configure.hpp"
#include "ros_interface/srv/process_request.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std::chrono_literals;

class RosInterfaceClient : public rclcpp::Node
{
public:
    RosInterfaceClient() : Node("ros_interface_client")
    {
        // Create service clients
        update_config_client_ = this->create_client<ros_interface::srv::UpdateConfigure>("Update_Config");
        process_client_ = this->create_client<ros_interface::srv::ProcessRequest>("Process_Communication");

        // Wait for servers
        while (!update_config_client_->wait_for_service(1s) && rclcpp::ok()) {
            RCLCPP_INFO(this->get_logger(), "Waiting for Update_Config service...");
        }
        while (!process_client_->wait_for_service(1s) && rclcpp::ok()) {
            RCLCPP_INFO(this->get_logger(), "Waiting for Process_Communication service...");
        }
    }

    void send_update_config(const std::string &command)
    {
        auto request = std::make_shared<ros_interface::srv::UpdateConfigure::Request>();
        request->command = command;

        if (command == "shutdown" || command == "reset")
        {
            // just send the command
        }
        else if (command == "update")
        {
            request->mode = "default";
            request->area = "500";          // area is a string in your Python code
            request->threshold_1 = 80;
            request->threshold_2 = 120;
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Wrong command ----!");
            return;
        }

        auto future = update_config_client_->async_send_request(request);

        // Wait for response
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "Update_Config response: success=%s, message=%s",
                        response->success ? "true" : "false",
                        response->message.c_str());
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service Update_Config");
        }
    }

    void request_process_data()
    {
        auto request = std::make_shared<ros_interface::srv::ProcessRequest::Request>();
        request->start_requestData = true;

        auto future = process_client_->async_send_request(request);

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            if (response->send_success) {
                RCLCPP_INFO(this->get_logger(), "Received data (%zu items):", response->data.size());
                for (auto &d : response->data) {
                    RCLCPP_INFO(this->get_logger(), "  - %s", d.c_str());
                }
            } else {
                RCLCPP_WARN(this->get_logger(), "Process_Communication failed to send data");
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service Process_Communication");
        }
    }


    

private:
    rclcpp::Client<ros_interface::srv::UpdateConfigure>::SharedPtr update_config_client_;
    rclcpp::Client<ros_interface::srv::ProcessRequest>::SharedPtr process_client_;
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RosInterfaceClient>();

    int choice;
    bool running = true;

    while (running && rclcpp::ok())
    {
        std::cout << "\nChoose your option: \n"
                  << "1. shutdown\n"
                  << "2. reset\n"
                  << "3. update\n"
                  << "4. request data\n"
                  << "5. exit\n"
                  << ">> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            node->send_update_config("shutdown");
            break;
        case 2:
            node->send_update_config("reset");
            break;
        case 3:
            node->send_update_config("update");
            break;
        case 4:
            node->request_process_data();
            break;
        case 5:
            running = false;
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }
    }

    rclcpp::shutdown();
    return 0;
}
