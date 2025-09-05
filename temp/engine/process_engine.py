import cv2
import threading

from python_custom.utils import Util

class ProcessEngine:
    def __init__(self, config_manager, setup):
        self.config = config_manager
        self.setup = setup
        self.processing_thread = None
        self.stop_event = threading.Event()

    def start_processing(self):
        """Start image processing loop"""
        if self.config.is_processing:
            return False
        
        self.stop_event.clear()
        self.config.set_processing_state(True)
        self.processing_thread = threading.Thread(target=self._processing_loop)
        self.processing_thread.start()
        return True
    
    def  stop_processing(self):
        """Stop image processing"""
        self.stop_event.set()
        self.config.set_processing_state(False)
        if self.processing_thread:
            self.processing_thread.join() # waiting for finish
    


    def _processing_loop(self):
        """Main processing loop"""
        self.final_data = None

        while not self.stop_event.is_set() and self.config.is_processing:

            # Grab live frame
            if not self.setup.cap.isOpened():
                print("Camera not available")
                break

            ret, frame = self.setup.cap.read()
            if not ret:
                continue

            # --- Processing pipeline ---
            image, contour = Util.getContour(frame, cThr=[67, 125],
                                             mode=None, minArea=50000, filter=4)

            if len(contour) > 0:
                biggest = contour[0][2]
                Util.reOder(biggest)
                image_error = Util.warpImg(image, biggest,
                                           self.setup.wP, self.setup.hP, pad=20)
                cv2.imshow("Warped", image_error)

                # Calculate width in cm
                height, width = image_error.shape[:2]
                h_p = [0, 0]
                w_p = [width, 0]
                a = Util.distance(h_p, w_p, ratio=self.setup.ratio)
                print("The distance is " + str(a) + " cm")

                # Error detection
                lol, contour_error = Util.getContour(image_error,
                                                     cThr=[78, 128],
                                                     mode=self.config.mode,
                                                     filter=0)
                cv2.imshow("Processed", lol)

                extracted_arr = [item[2] for item in contour_error]
                head_tail_arr = Util.sort_error(extracted_arr)
                head_tail_arr.insert(0, h_p)
                head_tail_arr.append(w_p)

                self.final_data = Util.distance_object(head_tail_arr,
                                                       self.setup.ratio)
                print(self.final_data)

                # If only one measurement is needed → break
                # break

            cv2.waitKey(1)


