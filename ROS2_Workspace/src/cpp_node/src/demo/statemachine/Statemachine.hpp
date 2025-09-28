#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#pragma once
#include "demo/communication/ros_Service.hpp"
#include "demo/communication/serial_UART.hpp"
#include "demo/database/DataBase.hpp"
#include "demo/engine/Engine.hpp"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>
#include <vector>
#include <limits>

// Create a copy value
template<typename T>

class MachineController {
public:
    enum class State { IDLE, SETUP, READY, RUNNING, ERROR, SHUTDOWN };

    // Constructor
    MachineController(std::shared_ptr<Ros_Cpp> roscpp,
                      std::shared_ptr<serial_UART> serialuart,
                      std::shared_ptr<DataBase> database,
                      std::shared_ptr<Engine> engine)
        : ros_(roscpp),
          serial_UART_(serialuart),
          data_Base_(database),
          engine_(engine),
          stop_flag(false),
          process_done(false)
    {}

    ~MachineController() { stop(); joinThreads(); }

    // Start threads
    void start() {
        threads.emplace_back(&MachineController::runROS2, this);
        threads.emplace_back(&MachineController::runMCU, this);
        threads.emplace_back(&MachineController::runEngine, this);
    }

    void setState(State new_state) {
        {
            std::lock_guard<std::mutex> lock(state_mutex);
            current_state = new_state;
        }

        switch (new_state) {
            case State::IDLE:
                    process_done = false;
                    cv_ros.notify_one();
                    cv_mcu.notify_one();
                    if (mcuIdle() && rosIdle()) {
                        setState(State::SETUP);
                        process_done =true;
                    }
                break;

            case State::SETUP:
                process_done = false;
                while (!process_done) {
                    int action = setup_User();

                    switch (action) {
                        case 1: // User information
                        case 2: // Wooden Segments Demanding
                        case 3: // Config Camera
                            log("Update successful ✅");
                            break;

                        case 4: // Confirm & continue
                                process_done = true;
                                setState(State::READY);
                            break;
                        case 0:
                        default:
                            process_done = true;
                            log("Invalid choice or exit...");
                            break;
                    }
                }
                break;

                
            case State::READY:
                log("[STATE] READY: Waiting for RUNNING...");
                cv_ros.notify_one();
                break;

            case State::RUNNING:
                log("[STATE] RUNNING: Processing... ")
                process_done = false;
                cv_ros.notify_one();
                cv_mcu.notify_one();
                cv_engine.notify_one();

            case State::ERROR:
            case State::SHUTDOWN:
                cv_mcu.notify_all();
                cv_ros.notify_all();
                cv_engine.notify_all();
                break;

            default: break;
        }
    }

    void stop() {
        stop_flag = true;
        cv_mcu.notify_all();
        cv_ros.notify_all();
        cv_engine.notify_all();
    }

private:
//_____________________Poiter_______________//
    std::shared_ptr<Ros_Cpp> ros_;
    std::shared_ptr<serial_UART> serial_UART_;
    std::shared_ptr<DataBase> data_Base_;
    std::shared_ptr<Engine> engine_;

//____________________State Variable________//
    std::atomic<State> current_state { State::IDLE };
    std::atomic<bool> stop_flag;
    std::atomic<bool> process_done;
    std::vector<std::thread> threads;

//___________________State Locking ________//
    std::mutex state_mutex;
    std::mutex mcu_mutex, ros_mutex, engine_mutex;
    std::condition_variable cv_mcu, cv_ros, cv_engine;

//___________________ Queue Variables Processing________________//
    // Queue Function
        void push(const T& value);
        T pop();
    // Locking Variables
        std::queue<T> q_queue;
        std::mutex m_queue;
        std::condition_variable cv_queue;
    // Queues for communication
        SafeQueue<std::string> cpp_to_python;
        SafeQueue<std::string> python_to_cpp;
    // Checking MCU is free (no object - no cutting)
        std::atomic<bool> mcu_object = false;
        std::atomic<bool> mcu_cutting = false;
    


    // ------------------- THREAD LOOPS -------------------
    void runROS2() {
        std::unique_lock<std::mutex> lock(ros_mutex);
        while (!stop_flag) {
            cv_ros.wait(lock, [&] {
                return stop_flag ||
                       current_state == State::IDLE    ||
                       current_state == State::READY   ||
                       current_state == State::RUNNING ||
                       current_state == State::ERROR   ||
                       current_state == State::SHUTDOWN;
            });

            if (stop_flag) break;

            switch (current_state.load()) {
                case State::IDLE:       rosIdle();    break;
                case State::READY:      rosReady();   break;
                case State::RUNNING:    rosRunning(); break;
                case State::ERROR:      rosError();   break;
                case State::SHUTDOWN:   rosShutdown();break;
                default: break;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    void runMCU() {
        std::unique_lock<std::mutex> lock(mcu_mutex);
        while (!stop_flag) {
            cv_mcu.wait(lock, [&] {
                return stop_flag ||
                       current_state == State::IDLE    ||
                       current_state == State::RUNNING ||
                       current_state == State::ERROR   ||
                       current_state == State::SHUTDOWN;
            });

            if (stop_flag) break;

            switch (current_state.load()) {
                case State::IDLE:     mcuIdle();     break;
                case State::RUNNING:  mcuRunning();  break;
                case State::ERROR:    mcuError();    break;
                case State::SHUTDOWN: mcuShutdown(); break;
                default: break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    void runEngine() {
        std::unique_lock<std::mutex> lock(engine_mutex);
        while (!stop_flag) {
            cv_engine.wait(lock, [&] { return stop_flag || current_state == State::RUNNING; });
            if (stop_flag) break;

            switch (current_state.load()) {
                case State::RUNNING:  engineRunning();  break;
                case State::ERROR:    engineError();    break;
                case State::SHUTDOWN: engineShutdown(); break;
                default: break;
            }
        }
    }

    // ------------------- BEHAVIORS -------------------
    bool rosIdle();
    bool rosReady();
    void rosRunning();
    void rosError();
    void rosShutdown();

    bool mcuIdle();
    void mcuRunning();
    void mcuError();
    void mcuShutdown();

    void engineRunning();
    void engineError();
    void engineShutdown();

    // ------------------- HELPERS -------------------
    void joinThreads() {
        for (auto &t : threads)
            if (t.joinable()) t.join();
    }

    void log(const std::string &msg) {
        std::cout << msg << std::endl;
    }

    int setup_User();
    void machine_running();
};

#endif
