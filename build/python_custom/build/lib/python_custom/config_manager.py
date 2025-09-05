class ConfigManager:
    def __init__(self, system_state):
        self.state = system_state

    def update_config(self, **kwargs):
        with self.state._config_lock:
            for key, value in kwargs.items():
                if value is not None:
                    self.state.config[key] = value
        print("[ConfigManager] Configuration updated:", kwargs)


    def reset_config(self, mode, area, thr1, thr2):
        with self.state._config_lock:
            self.state.config.update({
                'mode':          'default',
                'area':          area,
                'threshold_1':   thr1,
                'thrshold_2':    thr2
         })
        print("[ConfigManager] Configuration update...!")


# Node : command use for : "reset",  "shutdown",....