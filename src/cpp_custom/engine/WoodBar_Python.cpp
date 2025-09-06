#include "WoodBar_Python.hpp"

void WoodBar_Python::setData(const std::vector<int> input)
{
    for (const auto& p : input)
    {
        this->segment_list.push_back(p);
    }
    
}


std::vector<int>  WoodBar_Python::getData() const {
    return this->segment_list;
}
