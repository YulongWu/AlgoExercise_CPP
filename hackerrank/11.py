#import sys
#import os


# Complete the function below.

def availableXY(maxX, maxY, x, y):
    if x < 0 or y < 0 or x > maxX-1 or y > maxY-1:
        return False
    else:
        return True

def move_apply(grid, x, y, d, queue, w, l):
    if availableXY(w, l, x, y) and grid[x][y] == -1:
        grid[x][y] = d + 1
        queue.append((x, y, d + 1))

def  getLockerDistanceGrid( cityLength,  cityWidth,  lockerXCoordinates,  lockerYCoordinates):
    # check input availability
    if cityLength < 1 or cityWidth < 1 or not lockerXCoordinates or not lockerYCoordinates or len(lockerXCoordinates) < 1 or len(lockerYCoordinates) < 1:
        return None

    # init grid
    grid = [[-1]*cityLength for i in range(cityWidth)]

    # init queue for BFS
    queue = []

    # init location of lockers
    if len(lockerXCoordinates) != len(lockerYCoordinates):
        return None
    for x,y in zip(lockerXCoordinates, lockerYCoordinates):
        grid[y-1][x-1] = 0
        queue.append((y-1, x-1, 0))

    # count
    moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    # while i < len(queue):
    for item in queue:
        # item = queue[i]
        for move in moves:
            ix, iy = item[0] + move[0], item[1] + move[1]
            move_apply(grid, ix, iy, item[2], queue, cityWidth, cityLength)

#         # check up step
        # if availableXY(cityWidth, cityLength, item[0]-1, item[1]):
            # if grid[item[0]-1][item[1]] == -1:
                # grid[item[0]-1][item[1]] = item[2]+1
                # queue.append([item[0]-1, item[1], item[2]+1])

        # # check down step
        # if availableXY(cityWidth, cityLength, item[0]+1, item[1]):
            # if grid[item[0]+1][item[1]] == -1:
                # grid[item[0]+1][item[1]] = item[2]+1
                # queue.append([item[0]+1, item[1], item[2]+1])

        # # check left step
        # if availableXY(cityWidth, cityLength, item[0], item[1]-1):
            # if grid[item[0]][item[1]-1] == -1:
                # grid[item[0]][item[1]-1] = item[2]+1
                # queue.append([item[0], item[1]-1, item[2]+1])

        # # check right step
        # if availableXY(cityWidth, cityLength, item[0], item[1]+1):
            # if grid[item[0]][item[1]+1] == -1:
                # grid[item[0]][item[1]+1] = item[2]+1
                # queue.append([item[0], item[1]+1, item[2]+1])

        # i += 1

    print grid
    return grid

if __name__ == "__main__":
    getLockerDistanceGrid(3,5,[1],[1])
    getLockerDistanceGrid(5,7,[2,4],[3,7])
