import sys
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        free_cnt = [9]*81
        left = 0
        occupy = [[(False, -1)]*9 for x in range(81)]
        for i in range(len(board)):
            board[i] = list(board[i]) #since string is inchangable, convert them to list
        for r, row in enumerate(board):
            for c, char in enumerate(row):
                if char == '.':
                    left += 1
                else:
                    i = int(char)
                    # for t in range(9):
                        # occupy[r*9+c][t] = (True, -1)
                    free_cnt[r*9+c] = 0
                    self.update4Writing(r*9+c, i, board, occupy, free_cnt)
        # print "free_cnt: {0}".format(free_cnt)
        # print "initialize complete."
        steps = []
        serial, retry = 0, 0
        while left > 0:
            # print "free_cnt: {0}".format(free_cnt)
            if serial != -1:
                serial = self.getMinIndex(free_cnt, board)
            # print "left: {0} going to to insert serial: {1}".format(left, serial)
            if serial == -1:
                # print ["".join(i) for i in board]
                # exit(1)
                serial, t, retry = steps.pop()
                # print "going to pop serial: {0}, t:{1}".format(serial, t)
                self.update4Removing(serial, t, board, occupy, free_cnt)
                # if serial == 11:
                    # print "occupy: {0}".format(occupy)
                    # exit(1)
                retry += 1
                left += 1
            else:
                # print "occupy[serial]: {0}".format(occupy[serial])
                # print "retry: {0}".format(retry)
                # if serial == 11:
                    # print "occupy: {0}".format(occupy)
                t = self.getFreeNumber(occupy[serial], retry)
                # print "t={0}".format(t)
                if t == -1:
                    serial = -1
                    retry = 0
                    continue
                steps.append((serial, t, retry))
                retry = 0
                self.update4Writing(serial, t, board, occupy, free_cnt)
                left -= 1
        for i in range(len(board)): # convert board back
            board[i] = "".join(board[i])

    def update4Writing(self, serial, t, board, occupy, free_cnt):
        r, c = serial / 9, serial % 9
        board[r][c] = str(t)
        t = t-1
        occupy[serial][t] = (True, serial)
        # print "occupy: {0}".format(occupy)
        free_cnt[serial] -= 1
        for i in range(9):
            # print "r={1}, i={2}, occupy[r*9+i]: {0}".format(occupy[r*9+i][t], r, i)
            if not occupy[r*9+i][t][0]:
                free_cnt[r*9+i] -= 1
                # print "mark1: free_cnt: {0}".format(free_cnt)
                occupy[r*9+i][t] = (True, serial)
            if not occupy[i*9+c][t][0]:
                free_cnt[i*9+c] -= 1
                occupy[i*9+c][t] = (True, serial)
        for ir in [r/3*3 + i for i in range(3)]:
            for ic in [c/3*3 + i for i in range(3)]:
                if not occupy[ir*9+ic][t][0]:
                    free_cnt[ir*9+ic] -= 1
                    occupy[ir*9+ic][t] = (True, serial)

    def update4Removing(self, serial, t, board, occupy, free_cnt):
        r, c = serial / 9, serial % 9
        board[r][c] = '.'
        t = t-1
        occupy[serial][t] = (False, -1)
        free_cnt[serial] += 1
        for i in range(9):
            isoccupy, occ_serial = occupy[r*9+i][t]
            # if not isoccupy:
                # raise Exception("logic error")
            if occ_serial == serial:
                free_cnt[r*9+i] += 1
                occupy[r*9+i][t] = (False, -1)
            isoccupy, occ_serial = occupy[i*9+c][t]
            # if not isoccupy:
                # raise Exception("logic error")
            if occ_serial == serial:
                free_cnt[i*9+c] += 1
                occupy[i*9+c][t] = (False, -1)
        for ir in [r/3*3 + i for i in range(3)]:
            for ic in [c/3*3 + i for i in range(3)]:
                isoccupy, occ_serial = occupy[ir*9+ic][t]
                # if not isoccupy:
                    # raise Exception("logic error")
                if occ_serial == serial:
                    free_cnt[ir*9+ic] += 1
                    occupy[ir*9+ic][t] = (False, -1)

    def getFreeNumber(self, occupyItem, retry):
        count = 0
        for i, d in enumerate(occupyItem):
            if not d[0]:
                count += 1
                if count > retry:
                    return i + 1
        return -1

    def getMinIndex(self, free, board):
        min = sys.maxint
        min_i = 0
        for i, d in enumerate(free):
            if board[i/9][i%9] != '.':
                continue
            if d >= 0 and d < min:
                min = d
                min_i = i
        if min == 0: return -1
        return min_i

if __name__ == "__main__":
    board = ["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
    ins = Solution()
    ins.solveSudoku(board)
    print board
    print
