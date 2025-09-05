// 📌 Purpose: Store the segment list which is send from 
//              Python -> input data 

// Think of this as the material that need to process.

#ifndef WOODBARPYTHON_HPP
    #define WOODBARPYTHON_HPP

#include <vector>


class WoodBar_Python {
private:
    std::vector<int> segment_list;

public:
    // Receives a list from python
    WoodBar_Python() = default;
    void setData(const std::vector<int> input);
    
    // Return the stored vector
    std::vector<int> getData() const;
};

#endif // WOODBAR_HPP