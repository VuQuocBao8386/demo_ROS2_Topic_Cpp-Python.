import rclpy
import threading

from python_node.system_state import SystemState
from python_node.camera_handler import CameraHandler
from python_node.image_processor import ImageProcessor
from python_node.ros_manager import RosInterfaces

path = "/home/anhbaodz/Documents/ros2_wood/image/a.jpg"


def main(args=None):
    rclpy.init(args=args)

    state = SystemState()
    camera_event = threading.Event()
    engine_event = threading.Event()
    stop_event   = threading.Event()

    # Start worker threads
    camera_thread = CameraHandler(state=state, event=camera_event, stop_event=stop_event, path=path)
    engine_thread = ImageProcessor(state=state, event=engine_event, stop_event=stop_event)
    camera_thread.start()
    engine_thread.start()

    # Pass the thread instances, not the events
    config_node = RosInterfaces(state, camera_thread, engine_thread)  # ✅ Change here

    try:
        rclpy.spin(config_node)
    except KeyboardInterrupt:
        pass
    except rclpy.executors.ExternalShutdownException:  # Handle ROS shutdown gracefully :cite[2]:cite[10]
        pass
    finally:
        stop_event.set()
        camera_thread.join(timeout=1.0)
        engine_thread.join(timeout=1.0)
        config_node.destroy_node()
        rclpy.shutdown()


        

if __name__ == '__main__':
    main()
