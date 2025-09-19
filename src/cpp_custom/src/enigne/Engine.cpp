#include "Engine.hpp"

// Add object
void Engine::add_Object(const std::shared_ptr<User::Demand_WoodBar>& obj)
{
    demanding_Object.push_back(obj);
}


//--------------------------PROCESS---------------------------
    
// Fitting
std::vector<uint8_t> Engine::fitting(uint8_t input_py)
{
    std::vector<uint8_t> output;
    int temp = static_cast<int>(input_py);

    for (const auto& obj : demanding_Object)
    {
        if (input_py >= obj->_get_length())
        {
            output.push_back(obj->_get_length());
            
            // Extra checking
            if (this->temporary_wasting_data != 0)
                {
                    Storage->add_Final_Data(this->temporary_wasting_data);
                    Storage->add_Wasting_data(this->temporary_wasting_data);
                    // refresh
                    this->temporary_wasting_data = 0;
                }
        
        }
        else
        {
            if (this->temporary_wasting_data != 0)
            {   
                temp = temp + this->temporary_wasting_data;

                // store data
                Storage->add_Final_Data(temp);
                Storage->add_Wasting_data(temp);
                
                // refresh temporary_wasting_data
                this->temporary_wasting_data = 0;

            }

        }
    }
    return output;
}

// Missing
std::vector<uint8_t> Engine::missing(const std::vector<uint8_t>& output_1)
{
    std::vector<uint8_t> output;

    for (const auto& obj : demanding_Object)
    {
        if (std::find(output_1.begin(), output_1.end(), obj->_get_length()) != output_1.end())
        {
            uint8_t surplus = obj->_get_quanity() - obj->_get_flag();
            if (surplus > 0)
            {
                output.push_back(obj->_get_length());
            }
        }
    }
    return output;
}

// Min waste
std::vector<uint8_t> Engine::min_waste(const std::vector<uint8_t>& output_2, uint8_t input_py)
{
    std::vector<uint8_t> output;
    uint8_t min_wasting = std::numeric_limits<uint8_t>::max();
    uint8_t current_length = 0;

    for (const auto& obj : demanding_Object)
    {
        if (std::find(output_2.begin(), output_2.end(), obj->_get_length()) != output_2.end())
        {
            uint16_t remainder = input_py % obj->_get_length();
            uint8_t divisible = input_py / obj->_get_length();
            uint8_t missing_demand = obj->_get_quanity() - obj->_get_flag();

            // adjust remainder if cutting more than needed
            if (divisible > missing_demand)
            {
                remainder += static_cast<uint8_t>(obj->_get_length()) * (divisible - missing_demand);
            }

            uint8_t waste = static_cast<uint8_t>(remainder);

            // Case 1: found a smaller waste
            if (waste < min_wasting)
            {
                min_wasting = waste;
                current_length = obj->_get_length();
                output.clear();

                int pieces = (divisible > missing_demand) ? missing_demand : divisible;
                output.insert(output.end(), pieces, obj->_get_length());

                // Save temporary wasting
                if (waste > 0)
                    this->temporary_wasting_data = waste;
            }
            // Case 2: equal waste → prefer larger length
            else if (waste == min_wasting && obj->_get_length() >= current_length)
            {
                current_length = obj->_get_length();
                output.clear();

                int pieces = (divisible > missing_demand) ? missing_demand : divisible;
                output.insert(output.end(), pieces, obj->_get_length());

                // Save temporary wasting
                if (waste > 0)
                    this->temporary_wasting_data = waste;
            }
        }
    }
    return output;
}

// Counting
void Engine::counting(const std::vector<uint8_t>& output_3)
{
    for (const auto& count_flag : demanding_Object)
    {
        for (auto len : output_3)
        {
            if (len == count_flag->_get_length())
            {
                count_flag->_set_flag();
            }
        }
    }
}

// Process
void Engine::process(uint8_t input_py)
{
    auto output1 = fitting(input_py);
    auto output2 = missing(output1);
    auto output3 = min_waste(output2, input_py);

    this->counting(output3);

    for (const auto& i : output3)
    {
        int j = static_cast<int>(i);
        Storage->add_Final_Data(j);
    }
}
