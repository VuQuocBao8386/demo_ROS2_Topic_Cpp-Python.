import cv2
import numpy as np

class CameraHandler:
    
    def __init__(self, state, cam_index=None, path=None):
        self.state = state
        self.cap = None
        self.image = None

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
    

    def capture_frame(self):
        if self.cap is not None:
            ret, frame = self.cap.read()
            if ret:
                with self.state._image_lock:
                    self.state.camera_frame = frame
            else:
                print("Warning: Failed to read frame from camera.")
        
        elif self.image is not None:
            with self.state._image_lock:
                self.state.camera_frame = self.image.copy()
                print("Success: Image initailize sucessful.")
    
    def release(self):
        """Release the camera if it's being used."""
        if self.cap is not None:
            self.cap.release()
