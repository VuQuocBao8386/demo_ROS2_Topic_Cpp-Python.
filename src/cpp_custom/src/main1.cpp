#include "database/DataBase.hpp"
#include "setup/Setup.hpp"
#include "engine/Engine.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
    // _________Initialize_______________
    DataBase dB;

    int number = 0; 
    std::cout << "How many demand segments you want to create: ";

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
            std::cout << "Type number again: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(10000, '\n'); // Ignore invalid input
        }
    }

    // Adding demand segments to database
    for (int i = 0; i < number; i++)
    {
        int l, w, q;
        std::cout << "\n--- Demand Segment " << (i + 1) << " ---\n";
        std::cout << "Length: ";   std::cin >> l;
        std::cout << "Width:  ";   std::cin >> w;
        std::cout << "Quantity: "; std::cin >> q;
        
        // Input validation
        if (l <= 0 || w <= 0 || q <= 0) {
            std::cout << "Invalid input! Values must be positive. Skipping this segment.\n";
            continue;
        }
        
        // Create demand segment in database
        dB.create_DemandSegment(static_cast<uint8_t>(l), 
                               static_cast<uint8_t>(w), 
                               static_cast<uint8_t>(q));
    }

    // Check if we have any valid demand segments
    if (dB.demandSize() == 0) {
        std::cout << "No valid demand segments created. Exiting.\n";
        return 1;
    }

    // Create engine with database reference
    Engine engine(dB);
    
    // Test input values (wood bar lengths to process)
    std::vector<uint8_t> input = {12, 6, 40, 20, 50, 60, 2, 90};

    std::cout << "\n=== Processing Wood Bars ===\n";
    for (const auto& woodBarLength : input)
    {
        std::cout << "Processing wood bar of length: " << static_cast<int>(woodBarLength) << std::endl;
        engine.process(woodBarLength);
    }

    std::cout << "\n=== Results ===\n";
    engine.print_results();  // ✅ Engine prints its stored results

    return 0;
}