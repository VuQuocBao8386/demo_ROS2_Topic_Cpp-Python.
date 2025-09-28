#include "Engine.hpp"

std::vector<uint8_t> Engine::fitting(uint8_t input_py)
{
    std::vector<uint8_t> output;

    for (size_t i = 0; i < db_.demandSize(); ++i) {
        auto demand = db_.get_DemandSegment(i);
        if (!demand) continue;

        // Only consider if demand length fits
        if (input_py >= demand->_get_length()) {
            output.push_back(demand->_get_length());
        }
    }


    // If nothing fits, it's an error
    if (output.empty() && this->temporary_wasting_data == 0) {
        db_.add_Perfect_Segment(static_cast<int>(input_py));
        db_.add_Error_Segment(static_cast<int>(input_py));
    }
    else if (this->temporary_wasting_data > 0)
    {
        db_.add_Wasting_Segment(static_cast<int>(temporary_wasting_data));
        temporary_wasting_data += input_py;
        db_.add_Perfect_Segment(static_cast<int>(temporary_wasting_data));
        db_.add_Error_Segment(static_cast<int>(input_py));

        //refresh
        temporary_wasting_data = 0;
    }
    

    return output;
}

std::vector<uint8_t> Engine::missing(const std::vector<uint8_t>& output_1, uint8_t input_py)
{
    std::vector<uint8_t> output;

    for (size_t i = 0; i < db_.demandSize(); ++i) {
        auto demand = db_.get_DemandSegment(i);
        if (!demand) continue;

        if (std::find(output_1.begin(), output_1.end(),
                      demand->_get_length()) != output_1.end()) {
            int surplus = demand->_get_quanity() - demand->_get_flag();
            if (surplus > 0) {
                output.push_back(demand->_get_length());
            }
        }
    }
    
    if (output.empty()) {
        db_.add_Perfect_Segment(static_cast<int>(input_py));
        db_.add_Wasting_Segment(static_cast<int>(input_py));
    }
    return output;
}

std::vector<uint8_t> Engine::min_waste(const std::vector<uint8_t>& output_2,
                                       uint8_t input_py,
                                       std::queue<uint8_t>& simulation)
{
    std::vector<uint8_t> output;
    int min_wasting = std::numeric_limits<int>::max();
    int best_length = 0;

    for (size_t i = 0; i < db_.demandSize(); ++i) {
        auto demand = db_.get_DemandSegment(i);
        if (!demand) continue;

        if (std::find(output_2.begin(), output_2.end(),
                      demand->_get_length()) != output_2.end()) {
            int remainder = static_cast<int>(input_py) % demand->_get_length();
            int divisible = static_cast<int>(input_py) / demand->_get_length();
            int missing_demand = demand->_get_quanity() - demand->_get_flag();

            // Adjust remainder if cutting more than needed
            if (divisible > missing_demand) {
                remainder += demand->_get_length() * (divisible - missing_demand);
                divisible = missing_demand;
            }

            int waste = remainder;

            // Found better solution
            if (waste < min_wasting ||
                (waste == min_wasting && demand->_get_length() > best_length)) {
                min_wasting = waste;
                best_length = demand->_get_length();

                output.clear();
                if (divisible > 0) {
                    output.insert(output.end(), divisible, demand->_get_length());
                }
            }
        }
    }

    // Handle remainder (waste)
    if (min_wasting > 0 && min_wasting != std::numeric_limits<int>::max()) {
        // Try cutting remainder again later
        if (extra_process(min_wasting))
        {
            simulation.push(static_cast<uint8_t>(min_wasting));
            this->temporary_wasting_data = 0;
        }
        else
        {
            this->temporary_wasting_data = min_wasting;
        }        
    }

    return output;
}

void Engine::counting(const std::vector<uint8_t>& output_3)
{
    for (size_t i = 0; i < db_.demandSize(); ++i) {
        auto demand = db_.get_DemandSegment(i);
        if (!demand) continue;

        for (auto len : output_3) {
            if (len == demand->_get_length()) {
                demand->_set_flag();
            }
        }
    }
}

void Engine::process(uint8_t input_py)
{
    std::queue<uint8_t> simulation;
    simulation.push(input_py);

    while (!simulation.empty()) {
        uint8_t current = simulation.front();
        simulation.pop();

        // Step 1: fitting
        auto output1 = fitting(current);
        if (output1.empty()) continue;

        // Step 2: check missing
        auto output2 = missing(output1, current);
        if (output2.empty()) continue;

        // Step 3: minimize waste
        auto output3 = min_waste(output2, current, simulation);
        if (output3.empty()) continue;

        // Step 4: counting & record results
        counting(output3);

        for (const auto& segment : output3) {
            db_.add_Perfect_Segment(static_cast<int>(segment));
        }
    }
}


bool Engine::extra_process(uint8_t input_py)
{
    for (size_t i = 0; i < db_.demandSize(); ++i) {
        auto demand = db_.get_DemandSegment(i);
        if (!demand) continue;

        // Only consider if demand length fits
        if (input_py >= demand->_get_length()) {
            int surplus = demand->_get_quanity() - demand->_get_flag();
            if (surplus > 0) {
                return true;
            }
        }
    }
    return false;

}
