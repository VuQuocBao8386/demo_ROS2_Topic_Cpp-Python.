import rclpy
from rclpy.node import Node
from ros_serivce.srv import UpdateConfig, RequestData


class RosInterfaces(Node):
    def __init__(self, state, camera_handler, image_processor):
        super().__init__('ros_interface')

        self.state = state
        self.camera_handler = camera_handler   # ✅ the thread instance
        self.image_processor = image_processor
        # Services
        self.svr_config_update = self.create_service(UpdateConfig, "UpdateConfig", self.handle_update_config)
        self.svr_communicate_data = self.create_service(RequestData, "RequestData", self.handle_communication_data)

        # Timers
        # self.create_timer(0.5, self.camera_timer_callback)
        # self.create_timer(1.0, self.processing_timer_callback)





#______________________________________ Configuration Update Service ______________________________________ Configuration Update Service ------------

    def handle_update_config(self, request, response):
        self.get_logger().info("______________Start Updating Successfully____________")
        
        if request.command == "shutdown":
            self.shutdown()
            response.success = True
            response.message = "[ROS2 SHUTDOWN:] Shutdown successfully"

        elif request.command == "reset":
            self.state.reset_systemConfig()
            response.success = True
            response.message = "[ROS2 RESET:] Configuration reset to default"
            self.get_logger().info("___________Reset successfully_______________")
           
            # Print new config
            self.state.print_new_systemConfig()

        elif request.command == "update":
            if request.mode is not None:
                self.state.set_systemConfig("mode", request.mode)
            if request.area != 0:   # ✅ use != instead of `is not`
                self.state.set_systemConfig("area", request.area)
            if request.threshold_1 != 0:  # ✅
                self.state.set_systemConfig("threshold_1", request.threshold_1)
            if request.threshold_2 != 0:  # ✅
                self.state.set_systemConfig("threshold_2", request.threshold_2)
                    
            response.success = True
            response.message = "[ROS2 UPDATE:] Configuration updated successfully"
            self.get_logger().info("___________Updated successfully_______________")
            
            # Print new config
            self.state.print_new_systemConfig()
            
        else:
            response.success = False
            response.message = "Invalid request: No action taken"
            self.get_logger().info("[ERROR]: Request is invalid....!")

        return response
    


#______________________________________ Data Communication Service ______________________________________ Data Communication Service ------------

    def handle_communication_data(self, request, response):
        try:
            if request.ros_request_data:
                self.camera_handler.trigger("process")
                self.image_processor.event.set()  # ✅ Fixed: use image_processor instead of engine_handler

                response.data = self.state.get_systemData()
                response.send_success = True
            else:
                response.send_success = False
                response.data = []
        except Exception as e:
            self.get_logger().error(f"[ERROR] Communication failed: {e}")
            response.send_success = False
            response.data = []
        return response


    #------------ Timer Callbacks ------------
    # def camera_timer_callback(self):
    #     self.camera_handler.capture_frame()

    # def processing_timer_callback(self):
    #     self.image_processor.process()



    #------------ Shutdown Logic ------------
    def shutdown(self):
        self.get_logger().info("[ROS2] Shutdown requested...")
        self.camera_handler.trigger("release")
        self.destroy_node()
        rclpy.shutdown()