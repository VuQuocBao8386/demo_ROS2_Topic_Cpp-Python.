#include "rclcpp/rclcpp.hpp"
#include "demo/communication/ros_Service.hpp"
#include "demo/communication/serial_UART.hpp"
#include "demo/database/DataBase.hpp"
#include "demo/engine/Engine.hpp"
#include "demo/statemachine/Statemachine.hpp"



int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto db     = std::make_shared<DataBase>();
    auto engine = std::make_shared<Engine>(*db);
    auto ros    = std::make_shared<Ros_Cpp>(db);
    auto serial = std::make_shared<serial_UART>("/dev/ttyUSB0", B115200);
    std::this_thread::sleep_for(std::chrono::seconds(2));  // sleep 2 seconds


    MachineController stateMachine(ros, serial, db, engine);
    
    stateMachine.start();
    stateMachine.setState(MachineController::State::IDLE);
    std::this_thread::sleep_for(std::chrono::seconds(10));

    stateMachine.setState(MachineController::State::READY);
    std::this_thread::sleep_for(std::chrono::seconds(10));
   
    stateMachine.setState(MachineController::State::RUNNING);

    // 🔥 Keep main alive until Ctrl+C
    while (rclcpp::ok()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    stateMachine.stop();
    rclcpp::shutdown();
    return 0;
}
