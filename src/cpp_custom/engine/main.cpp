#include "Engine.hpp"
#include "Setup.hpp"
#include "StoreData.hpp"

#include <iostream>
#include <vector>

int main()
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
    
    // Pass them to Engine
    Engine engine;
    for (auto& obj : container) {
        engine.add_Object(obj);
    }

    std::vector<uint8_t> input = {20, 31, 5, 50, 56, 57, 52, 10, 5};

    for (const auto& check : input)
    {
        engine.process(check);
    }

    engine.print_results();  // ✅ Engine prints its stored results
}
