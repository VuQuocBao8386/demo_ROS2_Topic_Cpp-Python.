from threading import Lock
import json
import os
from ament_index_python.packages import get_package_share_directory

class SystemState:
    def __init__(self):
        # Locks for thread safety
        self._config_lock = Lock()
        self._camera_lock = Lock()
        self._data_lock   = Lock()

        # Load default config at startup
        self._system_config = self._load_default_config()

        # Other system data
        self._system_camera = None
        self._system_data   = []

    # ---------------- Private helper ----------------
    def _load_default_config(self):
        package_share = get_package_share_directory("python_node")
        config_path = os.path.join(package_share, "config", "default_config.json")

        with open(config_path, 'r') as file:
            cfgJson = json.load(file)

        return {
            'mode':               cfgJson["mode"],
            'area':               cfgJson["area"],
            'threshold_1':        cfgJson["threshold_1"],
            'threshold_2':        cfgJson["threshold_2"],
            'scale':              cfgJson["scale"],
            'width_pixel':        cfgJson["width_pixel"],
            'height_pixel':       cfgJson["height_pixel"],
            'ratio_numerator':    cfgJson["ratio_numerator"],
            'ratio_denominator':  cfgJson["ratio_denominator"],
        }
    
    # ---------------- Config ----------------
    def set_systemConfig(self, key, value):
        with self._config_lock:
                self._system_config[key] = value

    # Get
    def get_systemConfig(self, key):
        with self._config_lock:
            return self._system_config.get(key)

    # Reset    
    def reset_systemConfig(self):
        with self._config_lock:
            self._system_config = self._load_default_config()

    # Print
    def print_new_systemConfig(self):
        with self._config_lock:
            print("=== New Config ===")
            for key, value in self._system_config.items():
                print(f"{key}: {value}")
            print("======================")



    # ---------------- Camera ----------------
    def set_systemCamera(self, img):
        with self._camera_lock:
            self._system_camera = img

    def get_systemCamera(self):
        with self._camera_lock:
            return self._system_camera


    # ---------------- Data ----------------
    def set_systemData(self, data):
        with self._data_lock:
            self._system_data = data

    def get_systemData(self):
        with self._data_lock:
            return self._system_data
        
    def print_new_systemData(self):
        pass
        

    

        


    
