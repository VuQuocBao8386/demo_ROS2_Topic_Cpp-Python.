#include "StoreData.hpp"

void StoreData::add_FinalData(int data1)
{
    final_data.push_back(data1);
}

void StoreData::add_Wasting_data(int data2)
{
    wasting_data.push_back(data2);
}

void StoreData::print_Data() const
{
    std::cout << "Final data: ";
    for (const auto& a : final_data)
    {
        std::cout << a << ", ";
    }

    std::cout << "\nWasting data: ";
    for (const auto& b : wasting_data)
    {
        std::cout << b << ", ";
    }

    std::cout << std::endl; // flush output
}

void StoreData::reset()
{
    final_data.clear();
    wasting_data.clear();
}
