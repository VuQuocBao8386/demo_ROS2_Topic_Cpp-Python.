import rclpy
from rclpy.node import Node
from threading import Lock
from ros_interface.srv import UpdateConfigure, ProcessRequest

class RosInterfaces(Node):
    def __init__(self, system_state, config_manager, camera_handler, image_processor):
        super().__init__('ros_interface')

        self.state = system_state
        self.config_manager = config_manager
        self.camera_handler = camera_handler
        self.image_processor = image_processor

        # Services
        self.svr_config_update = self.create_service(UpdateConfigure, "Update_Config", self.handle_update_config)
        self.svr_communicate_data = self.create_service(ProcessRequest, "Process_Communication", self.handle_communication_data)

        # Timers
        self.create_timer(0.5, self.camera_timer_callback)
        self.create_timer(1.0, self.processing_timer_callback)

    #------------ Configuration Update Service ------------
    def handle_update_config(self, request, response):
        self.get_logger().info("______________Start Updating Successfully____________")

        if request.command == "shutdown":
            self.shutdown()
            response.success = True
            response.message = "Shutdown successfully"
            self.get_logger().info("___________Shutdown successfully_______________")

        elif request.command == "reset":
            self.config_manager.reset_config(mode='default', area=400, thr1=78, thr2=128)
            response.success = True
            response.message = "Configuration reset to default"
            self.get_logger().info("___________Reset successfully_______________")

        elif getattr(request, "update", False):
            config_updates = {}
            if hasattr(request, "mode"):
                config_updates["mode"] = request.mode
            if hasattr(request, "area"):
                config_updates["area"] = request.area
            if hasattr(request, "threshold_1"):
                config_updates["threshold_1"] = request.threshold_1
            if hasattr(request, "threshold_2"):
                config_updates["threshold_2"] = request.threshold_2

            self.config_manager.update_config(**config_updates)
            response.success = True
            response.message = "Configuration updated successfully"
            self.get_logger().info("___________Updated successfully_______________")
        else:
            response.success = False
            response.message = "Invalid request: No action taken"
            self.get_logger().info("[ERROR]: Request is invalid....!")

        return response

    #------------ Data Communication Service ------------
    def handle_communication_data(self, request, response):
        self.get_logger().info("______________Received Communication Request____________")

        try:
            if request.start_communication == "start":
                
                processed_data = self.image_processor.process()
                with self.state._data_lock:
                    self.state.process_data
                    self.state.process_data = processed_data
                    response.data = processed_data.copy()
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
        self.camera_handler.release()
        self.destroy_node()
        rclpy.shutdown()
