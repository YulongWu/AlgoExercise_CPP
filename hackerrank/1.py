#import sys
#import os


# Complete the function below.

def  getLockerDistanceGrid( cityLength,  cityWidth,  lockerXCoordinates,  lockerYCoordinates):
    # check input availability
    if cityLength < 1 or cityWidth < 1 \
        or not lockerXCoordinates or not lockerYCoordinates \
       or len(lockerXCoordinates) < 1 or len(lockerYCoordinates) < 1:
        return None

    grid = [[-1]*cityLength for i in range(cityWidth)]

    queue = []


