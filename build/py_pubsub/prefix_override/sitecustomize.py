import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/anhbaodz/Documents/ros2_ws/install/py_pubsub'
