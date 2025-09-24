#ifndef SETUP_HPP
#define SETUP_HPP

#include <iostream>

namespace User {

// This class is dimension of original wood bar (input to divide)
// Example: original wood bar is 8x20 (needs to be cut)
class Input_WoodBar
{
private:
    uint8_t     _length = 0;
    uint8_t     _width = 0;
    std::string userName;

public:
    //_________Initialize____________
    Input_WoodBar() = default;

    Input_WoodBar(const std::string& name, uint8_t l, uint8_t w) 
                :userName(name), _length(l), _width(w) {}

    ~Input_WoodBar() = default;

    // __________END_______________

    void setup(const std::string& name, uint8_t _length, uint8_t _width)
    {
        this->userName  = name;
        this->_length   = _length;
        this->_width    = _width;
    }

    uint8_t get_length() const;
    uint8_t get_width() const;


};



// This is used to initialize "Desired Dividing Segment Wood"
//  -> How many segments to divide
//  -> Length and width of each segment
class Demand_WoodBar
{
private:
    uint8_t _length_   = 0;
    uint8_t _width_    = 0;
    uint8_t _quantity_ = 0;
    uint8_t _flag_     = 0;

public:
    //_________Initialize____________
    Demand_WoodBar() = default;
    
    Demand_WoodBar(uint8_t l, uint8_t w, uint8_t q)
        : _length_(l), _width_(w), _quantity_(q) {}

    ~Demand_WoodBar() = default;
    // __________END_______________




    void setup(uint8_t& _length_, uint8_t& _width_ , uint8_t& _quantity_)
    {
        this->_length_   = _length_;
        this->_width_    = _width_;
        this->_quantity_ = _quantity_;
        this->_flag_     = 0;
    }

    void _set_flag()
    {
        this->_flag_++;

    }

    uint8_t _get_length() const; 
    uint8_t _get_width() const; 
    uint8_t _get_quanity() const;
    uint8_t _get_flag() const;

    void __print_() const;
};

} // namespace User

#endif
