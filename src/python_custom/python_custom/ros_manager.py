import rclpy
from rclpy.node import Node
from ros_interface.srv import UpdateConfigure, ProcessRequest


class RosInterfaces(Node):
    def __init__(self, state, camera_handler, image_processor):
        super().__init__('ros_interface')

        self.state = state
        self.camera_event =  camera_handler
        self.engine_event = image_processor

        # Services
        self.svr_config_update = self.create_service(UpdateConfigure, "Update_Config", self.handle_update_config)
        self.svr_communicate_data = self.create_service(ProcessRequest, "Process_Communication", self.handle_communication_data)

        # Timers
        # self.create_timer(0.5, self.camera_timer_callback)
        # self.create_timer(1.0, self.processing_timer_callback)





#______________________________________ Configuration Update Service ______________________________________ Configuration Update Service ------------

    def handle_update_config(self, request, response):
        self.get_logger().info("______________Start Updating Successfully____________")

        if request.command == "shutdown":
            self.shutdown()
            response.success = True
            response.message = "Shutdown successfully"
            self.get_logger().info("___________Shutdown successfully_______________")

        elif request.command == "reset":
            self.state.set_systemConfig(command="reset")
            response.success = True
            response.message = "Configuration reset to default"
            self.get_logger().info("___________Reset successfully_______________")

        elif request.command == "update":
            if request.mode is not None:
                self.state.set_systemConfig("mode", request.mode, command="default")
            if request.area is not None:
                self.state.set_systemConfig("area", request.area, command="default")
            if request.threshold_1 is not None:
                self.state.set_systemConfig("threshold_1", request.threshold_1, command="default")
            if request.threshold_2 is not None:
                self.state.set_systemConfig("threshold_2", request.threshold_2, command="default")

            response.success = True
            response.message = "Configuration updated successfully"
            self.get_logger().info("___________Updated successfully_______________")
       
        else:
            response.success = False
            response.message = "Invalid request: No action taken"
            self.get_logger().info("[ERROR]: Request is invalid....!")

        return response
    


#______________________________________ Data Communication Service ______________________________________ Data Communication Service ------------

    def handle_communication_data(self, request, response):
        self.get_logger().info("______________Received Communication Request____________")

        try:
            if request.start_requestData is True:
                self.camera_event.set()
                self.engine_event.set()
                
                response.data = self.state.get_systemData()
                response.send_success = True
                self.get_logger().info("______________Send Data Successfully____________")
            else:
                response.send_success = False
                response.data = []
                self.get_logger().warn("______________Invalid start_communication command____________")
        except Exception as e:
            self.get_logger().error(f"[ERROR] Communication failed: {e}")
            response.send_success = False
            response.data = []

        return response

    #------------ Timer Callbacks ------------
    def camera_timer_callback(self):
        self.camera_handler.capture_frame()

    def processing_timer_callback(self):
        self.image_processor.process()

    #------------ Shutdown Logic ------------
    def shutdown(self):
        self.camera_event.release()
        self.destroy_node()
        rclpy.shutdown()
