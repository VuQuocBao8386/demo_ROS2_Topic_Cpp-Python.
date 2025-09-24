#include "Statemachine.hpp"



//__________________________________ROS2_______________________________//
void MachineController::rosIdle()
{
    while (!ros_->check_services());
}

void MachineController::rosSetup()
{

}

//__________________________________MCU_______________________________//
void MachineController::runMCU()
{
    while (!serial_UART_->checking_Serial())    
}



//__________________________________ENGINE_______________________________
bool MachineController::setupSystem()
{
    // _________Initialize_______________
    int number = 0; 
    std::cout << "How many dimensions you wanna divide:  ";

    while (true)
    {
        try
        {
            std::cin >> number;
        
            if (number < 1) 
            {
                throw std::runtime_error("Invalid number <= 0");
            }
            break; // ✅ valid
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "Type number again : \n";
        }
    }
    
    std::vector<std::shared_ptr<User::Demand_WoodBar>> container;   
    container.reserve(number); // reserve memory

    // Adding arguments to objects
    for (int i = 0; i < number; i++)
    {
        int l, w, q;
        std::cout << "\n--- Dimension " << (i + 1) << " ---\n";
        std::cout << "Length: ";   std::cin >> l;
        std::cout << "Width:  ";   std::cin >> w;
        std::cout << "Quantity: "; std::cin >> q;
        container.emplace_back(std::make_shared<User::Demand_WoodBar>(
            static_cast<uint8_t>(l),
            static_cast<uint8_t>(w),
            static_cast<uint8_t>(q)));
    }
    
    
    
}

