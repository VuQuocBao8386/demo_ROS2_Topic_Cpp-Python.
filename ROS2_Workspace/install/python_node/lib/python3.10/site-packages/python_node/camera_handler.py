import cv2
import threading

class CameraHandler(threading.Thread):
    #____________________________________________Initialize_________________________________  
    def __init__(self, state, event: threading.Event, stop_event: threading.Event, cam_index=None, path=None):
        super().__init__()  # <-- important! call parent constructor
        self.state = state
        self.event = event
        self.stop_event = stop_event

        self.cap = None
        self.image = None
        self.command = None  # make sure command is defined


        if cam_index is not None and path is not None:
            raise ValueError("Only provide one input: either 'cam_index' or 'path', not both.")
        
        if cam_index is not None:
            self.cap = cv2.VideoCapture(cam_index)
            if not self.cap.isOpened():
                raise IOError(f"Failed to open camera with index {cam_index}.")
        
        elif path is not None:
            self.image = cv2.imread(path)
            if self.image is None:
                raise IOError(f"Failed to read image from path: {path}")
        
        else:
            raise ValueError("You must provide either a camera index or an image path.")
    
    #____________________________________________Process_________________________________  
    def process(self):
        if self.cap is not None:
            ret, frame = self.cap.read()
            if ret:
                self.state.set_systemCamera(frame)
                print("Success: Camera initialized successfully.")
            else:
                print("Warning: Failed to read frame from camera.")
        elif self.image is not None:  
            self.state.set_systemCamera(self.image.copy())
            print("Success: Image initialized successfully.")
            
        
        #self.release()  # cleanup before thread fully exits


    def release(self):
        """Release the camera if it's being used."""
        if self.cap is not None:
            self.cap.release()
            cv2.destroyAllWindows()


    #____________________________________________Thread_________________________________  
    def run(self):
        while not self.stop_event.is_set():  # check if we should stop
            self.event.wait()   # wait until triggered
            if self.stop_event.is_set():  
                break  # exit quickly if stopping
            
            try:
                if self.command == "process":
                    self.process()
                elif self.command == "release":
                    self.release()
                else:
                    print("[Camera] No valid command")
            finally:
                self.event.clear()


    def trigger(self, command):
        self.command = command
        self.event.set()