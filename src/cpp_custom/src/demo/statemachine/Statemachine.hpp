#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#pragma once
#include "communication/ros_Service.hpp"
#include "communication/serial_UART.hpp"
#include "setup/Setup.hpp"
#include "enigne/Engine.hpp"
#include "dataBase/StoreData.hpp"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>
#include <vector>

class MachineController {
public:
    enum class State { IDLE, READY, RUNNING, ERROR, SHUTDOWN };

    MachineController(std::shared_ptr<Ros_Cpp> rosnode,
                      std::shared_ptr<serial_UART> serialuarts,
                      std::shared_ptr<StoreData> storedata,
                      std::shared_ptr<User::Input_WoodBar> inputWoodBar,
                      std::shared_ptr<User::Demand_WoodBar> demandWoodBar,
                      std::shared_ptr<Engine> engine)
        : ros_(rosnode),
          serial_UART_(serialuarts),
          store_data_(storedata),
          input_WoodBar_(inputWoodBar),
          demand_WoodBar_(demandWoodBar),
          engine_(engine),
          stop_flag(false) {}

    ~MachineController() { stop(); joinThreads(); }

    // 🚀 Start all subsystems
    void start() {
        threads.emplace_back(&MachineController::runMCU, this);
        threads.emplace_back(&MachineController::runROS2, this);
        threads.emplace_back(&MachineController::runEngine, this);
    }

    // Set state and wake only the relevant thread
    void setState(State new_state) {
        {
            std::lock_guard<std::mutex> lock(state_mutex);
            current_state = new_state;
        }

        switch (new_state) {
            case State::READY:
            case State::RUNNING:
                cv_mcu.notify_one();
                cv_ros.notify_one();
                cv_engine.notify_one();
                break;

            case State::ERROR:
                cv_mcu.notify_one();
                cv_ros.notify_one();
                cv_engine.notify_one();
                break;

            case State::SHUTDOWN:
                cv_mcu.notify_one();
                cv_ros.notify_one();
                cv_engine.notify_one();
                break;
            
            default
                break;
        }
    }

    void stop() {
        stop_flag = true;
        cv_mcu.notify_all();
        cv_ros.notify_all();
        cv_engine.notify_all();
    }

private:
// communicate
    std::shared_ptr<Ros_Cpp> ros_;
    std::shared_ptr<serial_UART> serial_UART_;
// Setup
    std::shared_ptr<User::Input_WoodBar> input_WoodBar_;
    std::shared_ptr<User::Demand_WoodBar> demand_WoodBar_;
// Engine
    std::shared_ptr<Engine> engine_;

// Manage thread
    std::atomic<State> current_state { State::IDLE };
    std::atomic<bool> stop_flag;

    std::vector<std::thread> threads;

    std::mutex state_mutex;
    std::mutex mcu_mutex, ros_mutex, engine_mutex;
    std::condition_variable cv_mcu, cv_ros, cv_engine;


    //___________________ SETUP SYSTEM _________________
    bool setupSystem()


    // __________________ THREAD LOOPS __________________
    void runMCU() {
        std::unique_lock<std::mutex> lock(mcu_mutex);
        while (!stop_flag) {
            cv_mcu.wait(lock, [&] { return stop_flag || current_state != State::IDLE; });
            if (stop_flag) break;

            switch (current_state.load()) {
                case State::IDLE:     rosIdle(); break;
                case State::RUNNING:  mcuLoop(); break;
                case State::ERROR:    mcuError(); break;
                case State::SHUTDOWN: mcuShutdown(); break;
                default: break;
            }
        }
    }

    void runROS2() {
        std::unique_lock<std::mutex> lock(ros_mutex);
        while (!stop_flag) {
            cv_ros.wait(lock, [&] { return stop_flag || current_state != State::IDLE; });
            if (stop_flag) break;

            switch (current_state.load()) {
                case State::IDLE:     rosIdle(); break;
                case State::READY:    rosSetup(); break;
                case State::RUNNING:  rosLoop(); break;
                case State::ERROR:    rosError(); break;
                case State::SHUTDOWN: rosShutdown(); break;
                default: break;
            }
        }
    }

    void runEngine() {
        std::unique_lock<std::mutex> lock(engine_mutex);
        while (!stop_flag) {
            cv_engine.wait(lock, [&] { return stop_flag || current_state == State::RUNNING; });
            if (stop_flag) break;

            switch (current_state.load()) {
                case State::RUNNING:  engineLoop(); break;
                case State::ERROR:    engineError(); break;
                case State::SHUTDOWN: engineShutdown(); break;
                default: break;
            }
        }
    }

    // __________________ BEHAVIORS __________________
    void rosIdle();
    void rosSetup()    { log("ROS2 setup."); }
    void rosLoop()     { ros_->spin_some(); store_data_->pushROS("ros-event"); }
    void rosError()    { log("ROS2 error."); }
    void rosShutdown() { log("ROS2 shutdown."); }

    void mcuSetup()    { log("MCU setup."); }
    void mcuLoop()     { auto d = serial_UART_->readData(); store_data_->pushMCU(d); }
    void mcuError()    { log("MCU error."); }
    void mcuShutdown() { log("MCU shutdown."); }

    void engineLoop()  { auto r = engine_->runOnce(); store_data_->pushEngine(r); }
    void engineError() { log("Engine error."); }
    void engineShutdown() { log("Engine shutdown."); }

    // __________________ HELPERS __________________
    void joinThreads() {
        for (auto &t : threads) if (t.joinable()) t.join();
    }

    void log(const std::string &msg) {
        std::cout << msg << std::endl;
    }
};

#endif
