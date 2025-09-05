import rclpy
from rclpy.executors import MultiThreadedExecutor
from python_custom.system_state import SystemState
from python_custom.config_manager import ConfigManager
from python_custom.camera_handler import CameraHandler
from python_custom.image_processor import ImageProcessor
from python_custom.ros_manager import RosInterfaces



path =  "/home/anhbaodz/Documents/ros2_wood/image/a.jpg"



def main(args=None):
    rclpy.init(args=args)
    state = SystemState()
    config_manager = ConfigManager(state)
    camera_handler = CameraHandler(state, path=path)
    image_processor = ImageProcessor(state)
    ros_interface = RosInterfaces(state, config_manager, camera_handler, image_processor)

    executor = MultiThreadedExecutor()
    executor.add_node(ros_interface)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        print("Shutting down...")
    finally:
        ros_interface.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()