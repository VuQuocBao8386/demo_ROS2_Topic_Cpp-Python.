from threading import Lock
import json


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
        with open('../default_config.json', 'r') as file:
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
    def set_systemConfig(self, key, value, command=None):
        with self._config_lock:
            if command == "reset":
                self._system_config = self._load_default_config()
            else:
                self._system_config[key] = value

    def get_systemConfig(self, key):
        with self._config_lock:
            return self._system_config.get(key)


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


    
