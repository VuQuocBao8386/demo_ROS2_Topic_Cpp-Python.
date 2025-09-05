from threading import Lock

class SystemState():
    def __init__(self):
        self._config_lock = Lock()
        self._image_lock  = Lock()
        self._data_lock   = Lock()

        self.config = {
            'camera_enabled':     True,
            'processing_enabled': False,
            'mode':               'default',
            'area':                400,
            'threshold_1':         78,
            'threshold_2':         128
        }

        self.camera_frame         = None
        self.process_data         = []
        self.communication_active = False
    
    # # Data Configuration
    # def update_config(self, new_config: dict):
    #     with self._config_lock:
    #         self.config.update(new_config)

    # def get_config(self):
    #     with self._config_lock:
    #         return self.config.copy()

    # # Frame Camera
    # def set_frame(self, frame):
    #     with self._image_lock:
    #         self.camera_frame = frame

    # def get_frame(self):
    #     with self._image_lock:
    #         return self.camera_frame

    # # Data Processing 
    # def set_processed_data(self, data):
    #     with self._data_lock:
    #         self.processed_data = data

    # def get_processed_data(self):
    #     with self._data_lock:
    #         return self.processed_data.copy() 