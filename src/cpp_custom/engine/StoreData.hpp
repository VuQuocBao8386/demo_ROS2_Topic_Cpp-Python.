#ifndef STOREDATA_HPP
#define STOREDATA_HPP

#include <iostream>
#include <vector>

class StoreData
{
private:
    std::vector<int> final_data {};
    std::vector<int> wasting_data {};

public:
    StoreData() = default;
    ~StoreData() = default;

    void add_FinalData(int data1);
    void add_Wasting_data(int data2);
    void print_Data() const;
    void reset();
};

#endif
