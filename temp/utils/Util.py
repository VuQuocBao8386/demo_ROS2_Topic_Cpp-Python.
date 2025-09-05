import cv2
import numpy as np
import math




def getContour(img, cThr= None, mode = None, minArea= None, filter = None):
    
    Gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    Blur = cv2.GaussianBlur(Gray, (5,5), 1)
    Canny = cv2.Canny(Blur, cThr[0], cThr[1])
    
    # morphology
    kernel = np.ones((5,5))
    Dilate = cv2.dilate(Canny, kernel, iterations= 3)
    Erode = cv2.erode(Dilate, kernel, iterations= 2)
    
    # using to check canny
    if mode == "canny": 
        cv2.imshow('Canny', Erode)

    # using contour to draw loop
    contour, _ = cv2.findContours(Erode, cv2.RETR_EXTERNAL, cv2. CHAIN_APPROX_SIMPLE)
    final_Contour = [] # use for storing final choosing contour

    for i in contour:
        area = cv2.contourArea(i) # calculate acreage
        if area > minArea:
            peri = cv2.arcLength(i, True) # calculate perimeter
            approx = cv2.approxPolyDP(i, 0.02*peri, True)
            
            # return (x, y, z, h) - the top-left corner and the width & height of the box
            bbox = cv2.boundingRect(approx)

            
            # More Optional filter 
            if filter > 0:
                if len(approx) ==  filter:
                    final_Contour.append([len(approx), area, approx, bbox, i])
            else:
                    final_Contour.append([len(approx), area, approx, bbox, i])
            
            # in our this case . we accept all shapes



    if mode == "error":
        # Sort contours by their x position (left to right)
        final_Contour = sorted(final_Contour, key=lambda cnt: cv2.boundingRect(cnt[2])[0])
  
        # Optional: draw sorted index
        for i, cnt in enumerate(final_Contour):
            x, y, w, h = cv2.boundingRect(cnt[2])
            cv2.drawContours(img, [cnt[2]], -1, (0, 0, 255), 3)
            cv2.putText(img, str(i), (x, y), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
    else:
        final_Contour = sorted(final_Contour, key= lambda x:x[1], reverse= True)



    if mode == "draw":
        for ct in final_Contour:
            cv2.drawContours(img, [ct[4]], -1, (0, 0, 255), 3)



    return img, final_Contour





def reOder(myPoints):
    my_PointsNew = np.zeros_like(myPoints)
    myPoints = myPoints.reshape((4, 2))

    add = myPoints.sum(1)
    my_PointsNew[0] = myPoints[np.argmin(add)]  # Top-left
    my_PointsNew[3] = myPoints[np.argmax(add)]  # Bottom-right

    diff = np.diff(myPoints, axis=1)
    my_PointsNew[1] = myPoints[np.argmin(diff)]  # Top-right
    my_PointsNew[2] = myPoints[np.argmax(diff)]  # Bottom-left

    return my_PointsNew




# this function use PERSPECTIVE TRANSFORM ----  extracting only specific space
# which we only wanna work at (inside the A4 paper)


def warpImg(img, points, w, h, pad):

    #print(points)
    points = reOder(points)

    # convert to float numberic to calculate value
    pts1 = np.float32(points) 
    # this is desired dimensions 
    pts2 = np.float32([[0,0], [w,0], [0,h], [w,h]])

    # Apply and transform correspondingg with A4 in the original image
    matrix = cv2.getPerspectiveTransform(pts1, pts2)
    imgWarp = cv2.warpPerspective(img, matrix, (w,h))
    
    # Optional customization of the frame
    imgWarp = imgWarp[pad:imgWarp.shape[0]-pad,pad:imgWarp.shape[1]-pad]

    return imgWarp




# calcute distance 
def distance(pt1, pt2, ratio):
    distance_px = math.hypot(pt2[0] - pt1[0], pt2[1]-pt1[1])
    distance_cm = round((ratio * distance_px))
    return distance_cm



def sort_error(myPoints):

    my_New_point = []

    for contour in myPoints:
        for point in contour:
            point[0][1] = 0  # Set Y to 0

        contour = contour.reshape(-1,2)
        add = contour.sum(1)
        Points_New1 = contour[np.argmin(add)]  # Top-left
        Points_New2 = contour[np.argmax(add)]  # Bottom-righ2

        sum = [Points_New1, Points_New2]

        my_New_point.append(sum)
    # Convert to plain Python list
    flattened = [[int(x), int(y)] for pair in my_New_point for [x, y] in pair]

    return flattened    


def distance_object(myPoints, ratio):
    result = []

    for i in range(len(myPoints) - 1):
        d = distance(myPoints[i], myPoints[i + 1], ratio)
        result.append(d)

    return result

        
    


  
    
