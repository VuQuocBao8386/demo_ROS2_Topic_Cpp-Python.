#include "Statemachine.hpp"


//_________________________________________ IDLE ____________________________//
//___________ROS2________//
bool MachineController::rosIdle() 
{
    if (stop_flag) return false;

    if (ros_->Ros_Connect()) {
        log("[ROS] connected!");
        return true;
        // ✅ Now you can trigger real ROS requests here
        // ros_->send_update_config("some command");
    } else {
        log( "[ROS] waiting for services...");
        return false;
        // ❌ no need to sleep_for here, just return and let the thread loop handle pacing
    }
}

//___________MCU________//
bool MachineController::mcuIdle() {
       
    if (stop_flag) return false;
        
    if (serial_UART_->checking_Serial()) {
        log("[MCU] Connected !");
        return true;
    } else {
        log("[MCU] Waiting for connecting serial...");
        return false;
    }
    
}


//_________________________________________ SETUP ____________________________//
int MachineController::setup_User() {
    log("______________ Type your option: ______________");
    std::cout << "1. User Information.\n"
              << "2. Wooden Segment Demanding.\n"
              << "3. Config Camera.\n"
              << "4. Confirm & Continue.\n"
              << "0. Exit.\n" 
              << std::flush;   

    int choose_a;
    if (!(std::cin >> choose_a)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        log("Invalid input (non-numeric).");
        return 0;
    }

    switch (choose_a) {
        case 1: {
            std::string name;
            int _length, _width;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Length Wood: "; std::cin >> _length;
            std::cout << "Width Wood: "; std::cin >> _width;
            data_Base_->create_WoodBar(name, _length, _width);
            log("User information updated.");
            return 1;
        }

        case 2: {
            log("Create demand segments...");
            int number;
            std::cout << "How many segments? ";
            std::cin >> number;

            for (int i = 0; i < number; i++) {
                int l, w, q;
                std::cout << "\n--- Segment " << (i+1) << " ---\n";
                std::cout << "Length: ";   std::cin >> l;
                std::cout << "Width:  ";   std::cin >> w;
                std::cout << "Quantity: "; std::cin >> q;
                if (l > 0 && w > 0 && q > 0)
                    data_Base_->create_DemandSegment(l, w, q);
            }
            log("Demand segments updated.");
            return 2;
        }

        case 3: {
            std::string demand, mode;
            int area, t1, t2;
            std::cout << "Demand (reset/update): "; std::cin >> demand;
            if (demand == "reset") {
                mode = ""; area = 0; t1 = 0; t2 = 0;
            } else {
                std::cout << "Mode: "; std::cin >> mode;
                std::cout << "Area: "; std::cin >> area;
                std::cout << "Threshold 1: "; std::cin >> t1;
                std::cout << "Threshold 2: "; std::cin >> t2;
            }
            data_Base_->set_Ros2_Config(demand, mode, area, t1, t2);
            log("Camera configuration updated.");
            return 3;
        }

        case 4:
            return 4; // Confirm & Continue

        case 0:
            log("Exiting setup...");
            return 0;

        default:
            return 0;
    }
}


//_________________________________________ READY ____________________________//
//___________ROS2________//
bool MachineController::rosReady() {
    std::string demand = data_Base_->get_Ros2_Demand();
    ros_->Ros_Connect();

    if (demand == "update" || demand == "reset") {
        if (ros_->send_update_config(demand)) {
            log("[ROS] Update Configuration is Successful!");
            return true;
        } else {
            log("[ROS] Failed to send update");
        }
    } 
    else {
        log("[ROS] Invalid demand value: " + demand);
    }

    return false;
}


//_________________________________________ RUNNING ____________________________//
//___________Queue function________//
void MachineController::push(const T& value)
{
    {   
        std::lock_guard<std::mutex> lock(m_queue);
        this->q_queue.push(value);
    }
    cv_queue.notify_one();
}

T MachineController::pop()
{
    std::unique_lock<std::mutex> lock(m_queue);
    cv.wait(lock, [&]{ return !q_queue.empty(); });
    T value = q_queue.front();
    q_queue.pop();
    return value;
}

//___________ROS2________//
bool MachineController::rosRunning()    
{   
    auto data = cpp_to_python.pop() // Wait from c++
    std::string processed = data + "[processed]"; // initial informing bit
    
    // Action
    ros_Ros_Connect(); // Connect to Ros
    while (!ros_->send_request_data()); // Waitting for data comming
    python_to_cpp.push(processed)  // send back 
    return true;
}

//___________MCU________//
bool MachineController::mcuRunning() {
    std::string msg = serial_UART_->recieve_Serial();
    
    if (msg == "obj") {
        this->mcu_object = true;
        log("[MCU] Object detected");
    }
    else if (msg == "no_cutting") {
        this->mcu_cutting = false;
        log("[MCU] Cutting finished");
    }

    return true;
}

//___________ENGINE________//
bool MachineController::engineRunning() {
    if (this->mcu_object) {
        this->mcu_object = false; // reset

        // tell Python to process image
        cpp_to_python.push("capture");
        auto result = python_to_cpp.pop();  // wait

        auto py_data = data_Base_->get_data_py();
        for (auto i : py_data) {
            engine_->process(i);
        }
        engine_->print_results();

        // send processed data to MCU
        if (serial_UART_->transmit_Vector(data_Base_->get_Perfect_Segment())) {
            log("[C++] Sent data to MCU");
            this->mcu_cutting = true;
        }

        // now wait for MCU to confirm cutting done
        std::unique_lock<std::mutex> lock(m);
        cv_cutting.wait(lock, [&]{ return !mcu_cutting; });
        return true;
    }
    return false;
}








//_________________________________________ ERORR ____________________________//
    void MachineController::rosError()   {}
    void MachineController::mcuError()   {}
    void MachineController::engineShutdown(){} 

//_________________________________________ SHUTDOWN ____________________________//