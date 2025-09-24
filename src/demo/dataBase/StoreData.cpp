#include "StoreData.hpp"

//_______________________PROCESS_________________________//
void StoreData::add_Final_Data(const int& data) {
    final_data.push_back(data);
}

void StoreData::add_Wasting_Data(const int& data) {
    wasting_data.push_back(data);
}

void StoreData::add_Error_Data(const int& data) {
    error_data.push_back(data);
}

void StoreData::add_Python_Data(const int& data) {
    python_data.push_back(data);
}

//__________________________UTIL_______________________//
void StoreData::print_Data() const {
    std::cout << "Final data: ";
    for (const auto& a : final_data) {
        std::cout << a << ", ";
    }

    std::cout << "\nWasting data: ";
    for (const auto& b : wasting_data) {
        std::cout << b << ", ";
    }
    
    std::cout << "\nError data: ";
    for (const auto& c : error_data) {
        std::cout << c << ", ";
    }

    std::cout << "\nPython data: ";
    for (const auto& d : python_data) {
        std::cout << d << ", ";
    }
    
    std::cout << std::endl; // flush output
}

void StoreData::reset() {
    final_data.clear();
    wasting_data.clear();
    error_data.clear();
    python_data.clear();
}
