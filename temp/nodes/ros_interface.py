import rclpy
from rclpy.node import Node
from ros_interface.srv import UpdateConfigure, ProcessRequest


class ProcessingNode(Node):

    def __init__(self, config_manager, process_engine):
        super().__init__('processing_image_node')

        self.config = config_manager
        self.engine = process_engine 


        self.config_data = "default"
        self.create_service(UpdateConfigure, 'Update_Config', self.update_callback)
        self.create_service(ProcessRequest, 'Process_Request', self.process_callback)


    # for update 
    def update_callback(self, request, response):
        """Handle configuration update from C++"""

        try:
            if request.reset.lower() == "reset":
                self.config.reset_config()
                response.success = True
                response.message = "Configuration reset successful !"
                self.get_logger().info("Configuration has been reset.")
           
            elif request.update:
                self.config.update_config(
                    area             = request.area,
                    threshold_1      = request.threshold_1,
                    threshold_2      = request.threshold_2,
                    mode             = request.mode
                )
                response.success = True
                response.message = "Configuration updated"
                self.get_logger().info("Configuration updated with new values.")
                print(f"[DEBUG] Configuration updated with new values: {self.config_data}")


            else:
                response.success = False
                response.message = "Invalid request"

        except Exception as e:
            response.success = False
            response.message = f"Error: {str(e)}"

        return response



    # for process - FIXED THIS FUNCTION
    def process_callback(self, request, response):
      self.get_logger().info(f"Request received: start={request.start_communication}, done={request.done}")

      try:
          if request.start_communication == "start":
              if request.signal:
                  success = self.engine.start_processing()
                  response.data = []
                  response.send_success = "true" if success else "false"
                  response.message = "Processing started" if success else "Already processing"
                  self.get_logger().info("______________Start .....process______________")

              elif request.done:
                  # Return final data (once engine is done)
                  response.data = self.engine.final_data if self.engine.final_data else []
                  response.send_success = "true"
                  response.message = "Processing result returned"
                  self.get_logger().info("______________Done .....process______________")

          elif request.start_communication == "stop":
              self.engine.stop_processing()
              response.data = []
              response.send_success = "true"
              response.message = "Processing stopped"

          elif request.start_communication == "shutdown":
              self.config.request_shutdown()
              response.data = []
              response.send_success = "true"
              response.message = "Shutdown requested"

          else:
              response.data = []
              response.send_success = "false"
              response.message = "Unknown command"

      except Exception as e:
          response.data = []
          response.send_success = "false"
          response.message = f"Error: {str(e)}"

      return response



