#ifndef ENGINE_HPP
#define ENGINE_HPP

#pragma once
#include "database/DataBase.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <queue>   // for simulation queue

class Engine
{
private:
    DataBase& db_;
    int temporary_wasting_data = 0;

public:
    explicit Engine(DataBase& db) : db_(db) {}

    // Core processing stages
    std::vector<uint8_t> fitting(uint8_t input_py);
    std::vector<uint8_t> missing(const std::vector<uint8_t>& output_1, uint8_t input_py);
    std::vector<uint8_t> min_waste(const std::vector<uint8_t>& output_2, 
                                   uint8_t input_py, 
                                   std::queue<uint8_t>& simulation);
    void counting(const std::vector<uint8_t>& output_3);
    bool extra_process(uint8_t input_python);

    // Main loop
    void process(uint8_t input_py);

    // Utilities
    void print_results() const { db_.printAll(); }
    void reset_results() { 
        db_.clearAll(); 
        temporary_wasting_data = 0; 
    }
};

#endif // ENGINE_HPP
