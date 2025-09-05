#include "Setup.hpp"

namespace User {

    // Shared helper for printing dimensions
    static void print_dimensions(const std::string& title,
                                  int length,
                                  int width,
                                  int quantity = -1,
                                  int flag = -1)
    {
        std::cout << "Print dimensions of \"" << title << "\"" << std::endl;
        std::cout << "Length:  " << length << std::endl;
        std::cout << "Width:   " << width  << std::endl;
        if (quantity >= 0) {
            std::cout << "Quantity: " << quantity << std::endl;
        }
        if (flag >= 0) {
            std::cout << "Flag checking quanity: " << flag << std::endl;
        }
        
        std::cout << std::endl;
    }

    //________________________INPUT WOOD_BAR _______________________
 
    uint8_t Input_WoodBar::get_length() const
    {
        return this->_length;
    }

    uint8_t Input_WoodBar::get_width() const
    {
        return this->_width;
    }
 
 
    void Input_WoodBar::__print_() const
    {
        print_dimensions("Original Wood Bar", this->_length, this->_width);
    }

    void Input_WoodBar::__clear_()
    {
        this->_length = 0;
        this->_width  = 0;
    }







    //________________________DEMAND WOOD BAR_______________________
   
    uint8_t Demand_WoodBar::_get_width() const
    {
        return this->_width_;
    }
    uint8_t Demand_WoodBar::_get_length() const
    {
        return this->_length_;
    }  

    uint8_t Demand_WoodBar::_get_quanity() const
    {
        return this->_quantity_;
    }

    uint8_t Demand_WoodBar::_get_flag() const
    {
        return this->_flag_;
    }

    uint8_t Demand_WoodBar::_set_flag() 
    {   
        return this->_flag_++;
    }



    void Demand_WoodBar::__print_() const
    {
        print_dimensions("Demanding Wood Bar",
                         int(this->_length_),
                         int(this->_width_),
                         int(this->_quantity_),
                         int(this->_flag_));
    }   

    void Demand_WoodBar::__clear_()
    {
        this->_length_   = 0;
        this->_width_    = 0;
        this->_quantity_ = 0;
        this->_flag_     = 0;
    }

} // namespace User
