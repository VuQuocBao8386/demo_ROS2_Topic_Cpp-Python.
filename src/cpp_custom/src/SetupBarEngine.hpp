#ifndef SETUPBARENGINE_HPP
    #define SETUPBARENGINE_HPP

#include "Setup.hpp"
#include "WoodBar_Python.hpp" 
#include <vector>
#include <utility>  // for std::pair
#include <atomic>
#include <memory> // for Smart poiter
    

class SetupBarEngine
{
private:

    // from User
    std::vector<std::unique_ptr<WoodPiece>> cutting_Demand; 

    // from Python -(Opencv)
    std::vector<std::shared_ptr<WoodBar_Python>> cuttingList;

    // for engine
    std::vector<std::tuple<int, int, int>> _Demand = { {50, 3, 0}, {15, 3, 0}, {10, 3, 0} };
    std::vector<int> _List;

    std::atomic<bool> _running;



public:

    // Cutting Demand <User>
    void addPiece(std::unique_ptr<WoodPiece> piece){
        cutting_Demand.push_back(std::move(piece));
    }

    // Cutting List <from python>
    void addSegment(std::shared_ptr<WoodBar_Python> print_cuttingList){
        
        cuttingList.push_back(print_cuttingList);

    }
    void print_cuttingDemand(); // from User
    void print_cuttingList(); // from Python(Opencv)










//------------------------------- ENGINE MODULE ----------------------//
    std::vector<std::tuple<int,int,int>> fitting(int input_1);
        
    std::vector<std::tuple<int,int,int>> missing_leftover(
        const std::vector<std::tuple<int,int,int>>& _data2);

    std::vector<std::tuple<int,int,int>> not_odd( int input_3, 
                     const std::vector<std::tuple<int,int,int>>& _data3);

    std::vector<std::tuple<int,int,int>> priority(
                     const std::vector<std::tuple<int,int,int>>& _data4);
       
    std::vector<int> process(int input_5, 
                     const std::vector<std::tuple<int,int,int>>& _data5);
    
    std::vector<std::tuple<int,int,int>> Extra_Process(int input_6, 
                    const std::vector<std::tuple<int,int,int>>& _data6);
       
       
        


    void start();
    void reset();
    bool isDone() const;



    // Return list of point(X axis) for cutting machine to handle wood cutting
    void engine();
};

#endif


