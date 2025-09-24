#ifndef STOREDATA_HPP
#define STOREDATA_HPP

#pragma once
#include "setup/Setup.hpp"

#include <string>
#include <vector>
#include <mutex>
#include <memory>
#include <iostream>

class DataBase {
public:
    // _________________________Set alias______________________//
    using WoodbarPtr = std::shared_ptr<User::Input_WoodBar>;
    using DemandPtr = std::shared_ptr<User::Demand_WoodBar>;

    //___________________________ User WoodBar_________________//
    // Configuration
    WoodbarPtr create_WoodBar(const std::string& name, uint8_t l, uint8_t w);
    WoodbarPtr get_Woodbar(size_t index);
    bool update_WoodBar(size_t index, const std::string& name, uint8_t l, uint8_t w);    
    bool remove_WoodBar(size_t index);
    size_t woodbarSize() const { return storage_WoodBar.size(); }

    //___________________________ User Demand ___________________________//
    DemandPtr create_DemandSegment(uint8_t l, uint8_t w, uint8_t q);
    DemandPtr get_DemandSegment(size_t index);
    bool update_DemandSegment(size_t index, uint8_t l, uint8_t w, uint8_t q);
    bool remove_DemandSegment(size_t index);
    size_t demandSize() const { return storage_Demand.size(); }

    //____________________________ Method _____________________//
    void add_Perfect_Segment(int data);
    std::vector<int> get_Perfect_Segment() const;
    
    void add_Error_Segment(int data);
    std::vector<int> get_Error_Segment() const;
    
    void add_Wasting_Segment(int data);
    std::vector<int> get_Wasting_Segment() const;

    void set_Ros2_Config(int area_val, int thresh1, int thresh2);
    void get_Ros2_Config(int& area_val, int& thresh1, int& thresh2) const;

    void printAll() const;
    void clearAll();

private:
    // Protect multi Access   
    mutable std::mutex mtx;    
    // user input
    std::vector<WoodbarPtr> storage_WoodBar;
    // user demand
    std::vector<DemandPtr> storage_Demand;

    // Final Data
    std::vector<int> perfect_segment;
    std::vector<int> error_segment;
    std::vector<int> wasting_segment;

    // Ros2 data
    int area{0};
    int threshold_1{0};
    int threshold_2{0};
};

#endif