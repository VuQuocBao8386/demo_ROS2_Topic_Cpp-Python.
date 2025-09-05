#include "SetupBarEngine.hpp"


void SetupBarEngine::print_cuttingDemand() {
    for (const auto& p : cutting_Demand) {
        auto [l, q, c] = p->get_WoodPiece();
        std::cout << "Length: "     << static_cast<int>(l)
                  << "  Quantity: " << static_cast<int>(q)
                  << "  Flag: "     << static_cast<int>(c) << std::endl;
    }
    std::cout << "Total cutting demand: " << cutting_Demand.size() << std::endl;
}


void SetupBarEngine::print_cuttingList() {
    for (const auto& p : cuttingList) {
        // p is a shared_ptr, so use ->
        auto data = p->getData();

        for (const auto& num : data) {
            std::cout << num << " ";
        }
    }
    
    std::cout << std::endl;  // Newline after each list

    std::cout << this->cuttingList.size() << std::endl;

    
}




//----------------------  ENGINE MODULE -----------------------


void SetupBarEngine::start(){}




std::vector<std::tuple<int,int,int>> SetupBarEngine::fitting(int input_1){
    
    std::vector<std::tuple<int, int, int>> _output_1;


    for (const auto& i : this->_Demand)
    {
        if (std::get<0>(i) <= input_1)
         {   
            _output_1.push_back(i);
        }
        
    }
    return _output_1;   
}




std::vector<std::tuple<int,int,int>> SetupBarEngine::missing_leftover( 
    const std::vector<std::tuple<int,int,int>>& _data2)
{
    std::vector<std::tuple<int,int,int>> _output_3;  

    for (const auto& k : _data2)
    {
        int surplus = std::get<1>(k) - std::get<2>(k);
        if (surplus > 0)
        {
            _output_3.push_back(k);
            
        }
        else
        {
            continue;
        }
    }
  
    return _output_3;  
}





std::vector<std::tuple<int,int,int>> SetupBarEngine::not_odd(
    int input_3, 
    const std::vector<std::tuple<int,int,int>>& _data3)
{
    std::vector<std::tuple<int, int, int>> _output_2;
    uint8_t min_wasting_segment = 80;

    for (const auto& j : _data3)
    {
        int length = std::get<0>(j);
        int waste = input_3 % length;

        if (waste == 0)
        {
            // Perfect fit, keep it
            _output_2.push_back(j);
            
        }
        else if (waste <= min_wasting_segment)
        {
            // Better waste found
            min_wasting_segment = waste;
            
            if (waste < min_wasting_segment)
            {
                _output_2.clear(); // choose the best option            }
            
            }
            _output_2.push_back(j);
        }
    }

    return _output_2;
}





std::vector<std::tuple<int,int,int>> SetupBarEngine::priority(
    const std::vector<std::tuple<int,int,int>>& _data4)
{
    std::vector<std::tuple<int,int,int>> _output_4;
    
    // Start with lowest possible value
    int Compare_Priority = 0;

    for (const auto& f : _data4)
    {
        if (std::get<0>(f) > Compare_Priority)
        {
            Compare_Priority = std::get<0>(f);
            _output_4.clear();
            _output_4.push_back(f);
        }
    }

    return _output_4;
}




std::vector<int> SetupBarEngine::process(int input, const std::vector<std::tuple<int,int,int>>& _data5){

    // Store value to return
    std::vector<int> _output_5;

    // Varibale while processing when finish needed to reset
    auto my_tuple = _data5[0];

    
    uint8_t wasting_segment  = input % std::get<0>(my_tuple);
   
    uint8_t dividing= input / std::get<0>(my_tuple);

    uint8_t missing_segment = std::get<0>(my_tuple); 

    if (missing_segment <= dividing)
    {   
        for (int i = 0; i < missing_segment; i++)
        {
           _output_5.push_back(std::get<0>(my_tuple));
           input = input - std::get<0>(my_tuple);
        }
    }
    else if (missing_segment > dividing)
    {
        for (int i = 0; i < dividing; i++)
        {
            _output_5.push_back(std::get<0>(my_tuple));
            input = input - std::get<0>(my_tuple);

        }
    }
    else
    {
        throw std::runtime_error(" There're errors. Can not divided by zero !");
    }

    // auto new_k = k;  // make copy
    // std::get<2>(new_k) += 1;  // tăng giá trị phần tử thứ 3
    return _output_5;

}



std::vector<std::tuple<int,int,int>> SetupBarEngine::Extra_Process(
    int input_6, 
    const std::vector<std::tuple<int,int,int>>& _data6)
{
    std::vector<std::tuple<int,int,int>> _output_6;
    
    int min_condition = 80;  // initialize to large number
    
    for (const auto& vect : _data6)
    {
        int segment_length = std::get<0>(vect);
        int required = std::get<1>(vect);
        int existing = std::get<2>(vect);
        int requires = required - existing;

        // Skip if nothing is needed
        if (requires <= 0) continue;

        // How many can be divided
        int dividing = input_6 / segment_length;

        // Calculate the condition
        int condition = input_6 - (segment_length * requires);

        if (condition < 0) continue; // Cannot fulfill requirement

        if (condition < min_condition)
        {
            min_condition = condition;
            _output_6.clear();
            _output_6.push_back(vect);
        }
        else if (condition == min_condition)
        {
            _output_6.push_back(vect);  // include ties
        }
    }

    return _output_6;
}
