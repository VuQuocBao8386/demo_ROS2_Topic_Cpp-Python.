#ifndef STOREDATA_HPP
#define STOREDATA_HPP

#include <iostream>
#include <vector>

class StoreData
{
private:
    std::vector<int> final_data {};
    std::vector<int> wasting_data {};
    std::vector<int> error_data {};
    std::vector<int> python_data {};

public:
    StoreData() = default;
    ~StoreData() = default;

    void add_Final_Data(const int& data);
    void add_Wasting_Data(const int& data);
    void add_Error_Data(const int& data);
    void add_Python_Data(const int& data);

    void print_Data() const;
    void reset();
};

#endif
