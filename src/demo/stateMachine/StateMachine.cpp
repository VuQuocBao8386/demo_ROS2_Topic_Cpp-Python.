#include "Statemachine.hpp"



//__________________________________MCU_______________________________//

void MachineController::mcuIdle()   
{ 
    while (!serial_UART_->checking_Serial())
    {
        log("MCU: waiting for serial connection..."); 
    }  
}

void MachineController::mcuSetup()    { log("MCU: configuring hardware..."); }
void MachineController::mcuLoop()     { log("MCU: reading sensors + sending data..."); }

void MachineController::mcuError()    
{ 
    log("MCU: stopping actuators due to ERROR."); 
}
void MachineController::mcuShutdown() { log("MCU: shutting down."); }



//__________________________________ROS2_______________________________//

void rosIdle()     
{ 
    while (!ros_->check_services())
    {
        log("ROS2: waiting for service connection..."); 
    }
    
}

void rosSetup()    { log("ROS2: loading parameters, registering services..."); }
void rosLoop()     { ros_->spin_some(); log("ROS2: processing services..."); }
void rosError()    { log("ROS2: reporting error state."); }
void rosShutdown() { log("ROS2: shutting down node."); }


//__________________________________ENGINE_______________________________//
void engineIdle()     { log("Engine: idle, no job."); }
void engineSetup()    { log("Engine: preloading woodbar demand..."); }
void engineLoop()     { engine_->runOnce(); log("Engine: processing optimization..."); }
void engineError()    { log("Engine: halted due to ERROR."); }
void engineShutdown() { log("Engine: cleanup."); }