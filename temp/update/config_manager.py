class configManager:
    def __init__(self):
        self.area             = 400
        self.threshold_1      = 78 
        self.threshold_2      = 128
        self.mode             = "image" # or canny, sobel,...
        self.is_processing    = False
        self.shutdown_request = False
            


    def update_config(self, area=None, threshold_1=None, threshold_2=None, mode=None):
        if area is not None:
            self.area = area
        if threshold_1 is not None:    
            self.threshold_1 = threshold_1
        if threshold_2 is not None:    
            self.threshold_2 = threshold_2
        if mode is not None:
            self.mode = str(mode)

    def reset_config(self):
        self.area        = 400
        self.threshold_1 = 78 
        self.threshold_2 = 128
        self.mode        = "image"
    
     
    def set_processing_state(self, state):
        self.is_processing = state
    
    def request_shutdown(self):
        self.shutdown_requested = True
    