import rclpy
import threading

from python_custom.system_state import SystemState
from python_custom.camera_handler import CameraHandler
from python_custom.image_processor import ImageProcessor
from python_custom.ros_manager import RosInterfaces



path =  "/home/anhbaodz/Documents/ros2_wood/image/a.jpg"



def main(args=None):
    rclpy.init(args=args)
    path = "/home/anhbaodz/Documents/ros2_wood/image/a.jpg"

    state = SystemState()
    camera_event = threading.Event()
    engine_event = threading.Event()

    # Start worker threads
    camera_thread = CameraHandler(state, camera_event, path)
    engine_thread = ImageProcessor(state, engine_event)
    camera_thread.start()
    engine_thread.start()
    

    config_node = RosInterfaces(state, camera_event, engine_event)

    try:
        rclpy.spin(config_node)  # wait for service requests
    
    except KeyboardInterrupt:
           pass
    finally:
        config_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
