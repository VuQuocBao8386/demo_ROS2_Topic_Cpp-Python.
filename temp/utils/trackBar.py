import cv2


class track_bar:
    def __init__(self, window_name, value1=None, count1=None, value2=None, count2=None,
                 thres1_canny1=None, thres1_canny2=None, thres2_canny1=None, thres2_canny2=None):
        self.window_name = window_name

        # using for threshold
        self.value1 = value1
        self.count1 = count1
        self.value2 = value2
        self.count2 = count2

        # using for canny
        self.thres1_canny1 = thres1_canny1
        self.thres1_canny2 = thres1_canny2
        self.thres2_canny1 = thres2_canny1
        self.thres2_canny2 = thres2_canny2


    @classmethod
    def from_threshold(cls, window_name, value1, count1, value2, count2):
        cv2.namedWindow(window_name)
        cv2.createTrackbar('L_th', window_name, value1, count1, lambda x: None)
        cv2.createTrackbar('H_th', window_name, value2, count2, lambda x: None)
        return cls(window_name, value1, count1, value2, count2)

    @classmethod
    def from_thres_canny(cls, window_name, value1, count1, value2, count2,
                         thres1_canny1, thres1_canny2, thres2_canny1, thres2_canny2):
        cv2.namedWindow(window_name)
        cv2.createTrackbar('L_th', window_name, value1, count1, lambda x: None)
        cv2.createTrackbar('H_th', window_name, value2, count2, lambda x: None)
        cv2.createTrackbar('L_canny', window_name, thres1_canny1, thres1_canny2, lambda x: None)
        cv2.createTrackbar('H_canny', window_name, thres2_canny1, thres2_canny2, lambda x: None)
        return cls(window_name, value1, count1, value2, count2,
                   thres1_canny1, thres1_canny2, thres2_canny1, thres2_canny2)

    def get_thresh_Pos(self):
        l_th = cv2.getTrackbarPos('L_th', self.window_name)
        h_th = cv2.getTrackbarPos('H_th', self.window_name)
        return l_th, h_th

    def get_thresh_canny_Pos(self):
        l_th = cv2.getTrackbarPos('L_th', self.window_name)
        h_th = cv2.getTrackbarPos('H_th', self.window_name)
        l_canny = cv2.getTrackbarPos('L_canny', self.window_name)
        h_canny = cv2.getTrackbarPos('H_canny', self.window_name)
        return l_th, h_th, l_canny, h_canny
