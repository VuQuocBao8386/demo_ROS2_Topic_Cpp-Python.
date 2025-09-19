#include <memory>
#include <chrono>
#include <thread>


#include "src/stateMachine/Statemachine.hpp"

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    
    
    // 1. Create shared objects (dependencies)
    auto ros_node      = std::make_shared<Ros_Cpp>();
    auto serial_uart   = std::make_shared<serial_UART>("/dev/ttyUSB0", B115200);  // adjust port
    auto store_data    = std::make_shared<StoreData>();
    auto input_woodbar = std::make_shared<User::Input_WoodBar>();
    auto demand_woodbar= std::make_shared<User::Demand_WoodBar>();
    auto engine        = std::make_shared<Engine>();

    // 2. Create the MachineController
    MachineController controller(
        ros_node,
        serial_uart,
        store_data,
        input_woodbar,
        demand_woodbar,
        engine
    );

    // 3. Start threads
    controller.start();

    // 4. Simulate state transitions
    std::this_thread::sleep_for(std::chrono::seconds(2));
    controller.setState(MachineController::State::IDLE);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    controller.setState(MachineController::State::RUNNING);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    controller.setState(MachineController::State::SHUTDOWN);
    
    rclcpp::spin(node);
    rclcpp::shutdown();


    // 5. Stop and exit
    controller.stop();
    return 0;
}
