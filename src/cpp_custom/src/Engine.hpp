#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Setup.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <limits>


class Engine
{
private:
    std::vector<std::shared_ptr<User::Input_WoodBar>> original_WoodBar;
    std::vector<std::shared_ptr<User::Demand_WoodBar>> demanding_Object;
    std::vector<uint8_t> final_data;
    uint32_t wasting_data = 0;
public:
    // Initialize
    void add_Object(const std::shared_ptr<User::Demand_WoodBar>& obj);

    // Processing
    std::vector<uint8_t> fitting(uint8_t input_py);
    std::vector<uint8_t> missing(const std::vector<uint8_t>& output_1);
    std::vector<uint8_t> min_waste(const std::vector<uint8_t>& output_2, uint8_t input_py);
    void counting(const std::vector<uint8_t>& output_3);
    void process(uint8_t input_py);

    
    std::vector<uint8_t> _get_final_data() const;
    
    void update_wasting_data(uint8_t input_checking);
    uint32_t _get_wasting_data() const;

    void _Print_All_();
    void _Release__();
    void _Tracking_();
};



#endif
