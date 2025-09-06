#ifndef ENGINE_HPP
#define ENGINE_HPP

// Custom Module
#include "Setup.hpp"
#include "StoreData.hpp"

// Standard Library
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <limits>

class Engine
{
private:
    // Data for processing
    std::vector<std::shared_ptr<User::Input_WoodBar>> original_WoodBar;
    std::vector<std::shared_ptr<User::Demand_WoodBar>> demanding_Object;
    
    // Store data (owned by Engine)
    std::unique_ptr<StoreData> Storage = std::make_unique<StoreData>();

    int temporary_wasting_data = 0;

public:
    // Initialize
    void add_Object(const std::shared_ptr<User::Demand_WoodBar>& obj);

    // Processing
    std::vector<uint8_t> fitting(uint8_t input_py);
    std::vector<uint8_t> missing(const std::vector<uint8_t>& output_1);
    std::vector<uint8_t> min_waste(const std::vector<uint8_t>& output_2, uint8_t input_py);

    void counting(const std::vector<uint8_t>& output_3);
    void process(uint8_t input_py);

    // Utilities
    void print_results() const { Storage->print_Data(); }
    void reset_results() { Storage->reset(); }
};

#endif
