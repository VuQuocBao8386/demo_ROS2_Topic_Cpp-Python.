import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/anhbaodz/Documents/ROS2_Workspace/install/python_node'
