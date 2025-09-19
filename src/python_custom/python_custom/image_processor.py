from python_custom import Util
import cv2
import threading


class ImageProcessor(threading.Thread):
#__________________________________________Initialization______________________//
    def __init__(self, state, event: threading.Event):
        self.state = state
        self.event = event




#__________________________________________PROCESS______________________//
    def run(self):
        
        checking_image = self.state.get_systemCamera()
        if checking_image is None:
            print("[PROCESS] No frame available yet.")
            return []
        
        else:
        # Initial value for processing
            frame = checking_image

            mode  = self.state.get_systemConfig("mode")
            area  = self.state.get_systemConfig("area")
            thr1  = self.state.get_systemConfig("threshold_1")
            thr2  = self.state.get_systemConfig("threshold_2")

        
     
            scale       = self.state.get_systemConfig("scale")                # Scale factor(used later, likely for display or calculation)
            wP          = self.state.get_systemConfig("width_pixel") * scale  # Width in pixels (e.g., 210mm * scale = 630 pixels)
            hP          = self.state.get_systemConfig("height_pixel") * scale # Height in pixels (e.g., 297mm * scale = 891 pixels)
            numerator   = self.state.get_systemConfig("ratio_numerator")
            denominator = self.state.get_systemConfig("ratio_denominator")
            ratio       =  numerator/denominator                              # use for pixel measure 



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

        # close thread
        self.event.clear()
