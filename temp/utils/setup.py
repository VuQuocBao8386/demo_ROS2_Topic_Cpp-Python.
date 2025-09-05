import cv2

class Setup:
    def __init__(self, cam_index):
        # Load test image (optional)
        self.path = '/home/anhbaodz/Documents/ros2_wood/image/a.jpg'
        self.cap = cv2.VideoCapture(cam_index)

        # Scale values
        self.scale = 1
        self.wP = 800 * self.scale
        self.hP = 200 * self.scale
        self.ratio = 80 / 760   # calibration ratio

    def check_camera(self):
        """Check if camera works and grab one frame"""
        if not self.cap.isOpened():
            print("Camera not found !")
            return None
        
        ret, frame = self.cap.read()
        if not ret:
            print("Failed to grab frame")
            return None

        return frame
    
    def stop_capture(self):
        """Release camera"""
        if self.cap:
            self.cap.release()
            self.cap = None
