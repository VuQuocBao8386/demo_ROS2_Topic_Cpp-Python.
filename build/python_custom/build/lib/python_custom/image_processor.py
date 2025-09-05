from python_custom import Util
import cv2


class ImageProcessor:
    def __init__(self, state):
        self.state = state

    def process(self):
        with self.state._image_lock:
            if self.state.camera_frame is None:
                print("[PROCESS] No frame available yet.")
                return []

        # Initial value for processing
            frame = self.state.camera_frame.copy()
            mode = self.state.config["mode"]
            area = self.state.config["area"]
            thr1 = self.state.config["threshold_1"]
            thr2 = self.state.config["threshold_2"]

        
        # Adjusting for suitable
            scale = 1 # Scale factor(used later, likely for display or calculation)
            wP = 800 * scale  # Width in pixels (e.g., 210mm * scale = 630 pixels)
            hP = 200 * scale  # Height in pixels (e.g., 297mm * scale = 891 pixels)
            ratio =  80/760# use for pixel measure 



        # Processing logic
        image, contours = Util.getContour(frame, cThr=[67, 125],
                                          mode=None, minArea=50000, filter=4)
        if len(contours) > 0:
            biggest = contours[0][2]
            Util.reOder(biggest)
            image_error = Util.warpImg(image, biggest, wP, hP, pad=20)

            if mode == "Warped_image":
                cv2.imshow("Warped_image", image_error)

            height, width = image_error.shape[:2]
            h_p = [0, 0]
            w_p = [width, 0]
            distance_cm = Util.distance(h_p, w_p, ratio=ratio)

            error_img, error_contours = Util.getContour(image_error,
                                                        cThr=[thr1, thr2],
                                                        mode=area, minArea=area, filter =0)
            cv2.imshow("image", error_img)

            extracted = [item[2] for item in error_contours]
            head_tail = Util.sort_error(extracted)
            head_tail.insert(0, h_p)
            head_tail.append(w_p)

            final_data = Util.distance_object(head_tail, ratio)
            return final_data

        return []
