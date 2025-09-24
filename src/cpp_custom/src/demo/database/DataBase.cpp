#include "DataBase.hpp"

using namespace User; // Add this to avoid typing User:: everywhere

//___________________________User WoodBar_________________//
DataBase::WoodbarPtr DataBase::create_WoodBar(const std::string& name, uint8_t l, uint8_t w)
{
    std::lock_guard<std::mutex> lock(mtx);
    auto obj_W = std::make_shared<Input_WoodBar>(name, l, w);
    storage_WoodBar.push_back(obj_W);
    return obj_W; 
}

DataBase::WoodbarPtr DataBase::get_Woodbar(size_t index)
{
    std::lock_guard<std::mutex> lock(mtx);
    return (index < storage_WoodBar.size()) ? storage_WoodBar[index] : nullptr;
}

bool DataBase::remove_WoodBar(size_t index)
{
    std::lock_guard<std::mutex> lock(mtx);
    if (index < storage_WoodBar.size()) {
        storage_WoodBar.erase(storage_WoodBar.begin() + index);
        return true;
    }
    return false;
}

bool DataBase::update_WoodBar(size_t index, const std::string& name, uint8_t l, uint8_t w)
{
    std::lock_guard<std::mutex> lock(mtx);
    if (index < storage_WoodBar.size()) {
        storage_WoodBar[index]->setup(name, l, w);
        return true;
    }
    return false;
}

//___________________________User Demand___________________//
DataBase::DemandPtr DataBase::create_DemandSegment(uint8_t l, uint8_t w, uint8_t q)
{
    std::lock_guard<std::mutex> lock(mtx);
    auto obj_D = std::make_shared<Demand_WoodBar>(l, w, q);
    storage_Demand.push_back(obj_D);
    return obj_D; 
}

DataBase::DemandPtr DataBase::get_DemandSegment(size_t index)
{
    std::lock_guard<std::mutex> lock(mtx);
    return (index < storage_Demand.size()) ? storage_Demand[index] : nullptr;
}

bool DataBase::remove_DemandSegment(size_t index)
{
    std::lock_guard<std::mutex> lock(mtx);
    if (index < storage_Demand.size()) {
        storage_Demand.erase(storage_Demand.begin() + index);
        return true;
    }
    return false;
}

bool DataBase::update_DemandSegment(size_t index, uint8_t l, uint8_t w, uint8_t q)
{
    std::lock_guard<std::mutex> lock(mtx);
    if (index < storage_Demand.size()) {
        storage_Demand[index]->setup(l, w, q);
        return true;
    }
    return false;
}

//____________________________ Method _____________________//
void DataBase::add_Perfect_Segment(int data)
{
    std::lock_guard<std::mutex> lock(mtx);
    perfect_segment.push_back(data);
}

std::vector<int> DataBase::get_Perfect_Segment() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return perfect_segment;
}

void DataBase::add_Error_Segment(int data)
{
    std::lock_guard<std::mutex> lock(mtx);
    error_segment.push_back(data);
}

std::vector<int> DataBase::get_Error_Segment() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return error_segment;
}

void DataBase::add_Wasting_Segment(int data)
{
    std::lock_guard<std::mutex> lock(mtx);
    wasting_segment.push_back(data);
}

std::vector<int> DataBase::get_Wasting_Segment() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return wasting_segment;
}

void DataBase::set_Ros2_Config(int area_val, int thresh1, int thresh2)
{
    std::lock_guard<std::mutex> lock(mtx);
    area = area_val;
    threshold_1 = thresh1;
    threshold_2 = thresh2;
}

void DataBase::get_Ros2_Config(int& area_val, int& thresh1, int& thresh2) const
{
    std::lock_guard<std::mutex> lock(mtx);
    area_val = area;
    thresh1 = threshold_1;
    thresh2 = threshold_2;
}

void DataBase::printAll() const
{
    std::lock_guard<std::mutex> lock(mtx);
    
    std::cout << "_______________Perfect Segment: ";
    for (const auto& i : perfect_segment) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::cout << "_______________Error Segment: ";
    for (const auto& i : error_segment) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::cout << "_______________Wasting Segment: ";
    for (const auto& i : wasting_segment) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

void DataBase::clearAll()
{
    std::lock_guard<std::mutex> lock(mtx);
    perfect_segment.clear();
    error_segment.clear();
    wasting_segment.clear();
}