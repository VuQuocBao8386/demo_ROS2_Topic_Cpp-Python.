#ifndef SETUP_HPP
#define SETUP_HPP

#include <iostream>

namespace User {

// This class is dimension of original wood bar (input to divide)
// Example: original wood bar is 8x20 (needs to be cut)
class Input_WoodBar
{
public:
    // Constructors
    Input_WoodBar() = default;
    Input_WoodBar(const std::string& name, uint8_t l, uint8_t w)
        : userName(name), _length(l), _width(w) {}

    ~Input_WoodBar() = default;

    // __________END_______________
   
    void setup(const std::string& name, uint8_t l, uint8_t w) {
        userName = name;
        _length  = l;
        _width   = w;
    }
    
    const std::string& getName() const { return userName; }
    uint8_t get_length() const;
    uint8_t get_width() const;

private:
    std::string userName;
    uint8_t     _length = 0;
    uint8_t     _width = 0;
};



// This is used to initialize "Desired Dividing Segment Wood"
//  -> How many segments to divide
//  -> Length and width of each segment
class Demand_WoodBar
{
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

private:
    uint8_t _length_   = 0;
    uint8_t _width_    = 0;
    uint8_t _quantity_ = 0;
    uint8_t _flag_     = 0;
};

} // namespace User

#endif
