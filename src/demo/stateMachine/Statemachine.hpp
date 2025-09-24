#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#pragma once
#include "communication/ros_Service.hpp"
#include "communication/serial_UART.hpp"
#include "setup/Setup.hpp"
#include "enigne/Engine.hpp"
#include "dataBase/StoreData.hpp"


#include <thread>


class MachineController {
public:
    MachineController(std::shared_ptr<Ros_Cpp> rosnode,
                      std::shared_ptr<serial_UART> serialuarts,
                      std::shared_ptr<StoreData> storedata,
                      std::shared_ptr<User::Input_WoodBar> inputWoodBar,
                      std::shared_ptr<User::Demand_WoodBar> demandWoodBar,
                      std::shared_ptr<Engine> engine)
        : ros_(rosnode),
          serial_UART_(serialuarts),
          input_WoodBar_(inputWoodBar),
          demand_WoodBar_(demandWoodBar),
          engine_(engine),
          store_data_(storedata),   
          current_state(State::IDLE),
          stop_flag(false) {}

    ~MachineController() {
        stop();
        joinThreads();
    }

    // 🚀 Start all subsystems
    void start() {
        threads.emplace_back(&MachineController::runMCU, this);
        threads.emplace_back(&MachineController::runROS2, this);
        threads.emplace_back(&MachineController::runEngine, this);
    }

    void setState(State new_state) {
        std::cout << ">>> Transition to " << stateToString(new_state) << std::endl;
        current_state.store(new_state);
    }

    void stop() { stop_flag = true; }

private:
    enum class State { IDLE, READY, RUNNING, ERROR, SHUTDOWN };

    std::shared_ptr<Ros_Cpp> ros_;
    std::shared_ptr<serial_UART> serial_UART_;
    std::shared_ptr<StoreData> store_data_;
    std::shared_ptr<User::Input_WoodBar> input_WoodBar_;
    std::shared_ptr<User::Demand_WoodBar> demand_WoodBar_;
    std::shared_ptr<Engine> engine_;

    std::atomic<State> current_state;
    std::atomic<bool> stop_flag;
    std::vector<std::thread> threads;
    std::mutex log_mutex;

    // __________________ THREAD LOOPS __________________
    void runMCU() {
        while (!stop_flag) {
            switch (current_state.load()) {
                case State::IDLE:     mcuIdle(); break;
                case State::READY:    mcuSetup(); break;
                case State::RUNNING:  mcuLoop(); break;
                case State::ERROR:    mcuError(); break;
                case State::SHUTDOWN: mcuShutdown(); break;
            }
        }
    }

    void runROS2() {
        while (!stop_flag) {
            switch (current_state.load()) {
                case State::IDLE:     rosIdle(); break;
                case State::READY:    rosSetup(); break;
                case State::RUNNING:  rosLoop(); break;
                case State::ERROR:    rosError(); break;
                case State::SHUTDOWN: rosShutdown(); break;
            }
        }
    }

    void runEngine() {
        while (!stop_flag) {
            switch (current_state.load()) {
                case State::IDLE:     engineIdle(); break;
                case State::READY:    engineSetup(); break;
                case State::RUNNING:  engineLoop(); break;
                case State::ERROR:    engineError(); break;
                case State::SHUTDOWN: engineShutdown(); break;
            }
            
        }
    }

    // __________________ BEHAVIORS __________________
    // MCU
    void mcuIdle()     { log("MCU: waiting for serial connection..."); }
    void mcuSetup()    { log("MCU: configuring hardware..."); }
    void mcuLoop()     { log("MCU: reading sensors + sending data..."); }
    void mcuError()    { log("MCU: stopping actuators due to ERROR."); }
    void mcuShutdown() { log("MCU: shutting down."); }

    // ROS2
    void rosIdle()     { log("ROS2: waiting for service connection..."); }
    void rosSetup()    { log("ROS2: loading parameters, registering services..."); }
    void rosLoop()     { ros_->spin_some(); log("ROS2: processing services..."); }
    void rosError()    { log("ROS2: reporting error state."); }
    void rosShutdown() { log("ROS2: shutting down node."); }

    // Engine
    void engineIdle()     { log("Engine: idle, no job."); }
    void engineSetup()    { log("Engine: preloading woodbar demand..."); }
    void engineLoop()     { engine_->runOnce(); log("Engine: processing optimization..."); }
    void engineError()    { log("Engine: halted due to ERROR."); }
    void engineShutdown() { log("Engine: cleanup."); }

    void joinThreads() {
        for (auto &t : threads) {
            if (t.joinable()) t.join();
        }
    }

    std::string stateToString(State s) {
        switch (s) {
            case State::IDLE: return "IDLE";
            case State::READY: return "READY";
            case State::RUNNING: return "RUNNING";
            case State::ERROR: return "ERROR";
            case State::SHUTDOWN: return "SHUTDOWN";
        }
        return "UNKNOWN";
    }

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(log_mutex);
        std::cout << msg << std::endl;
    }
};


#endif