import sys
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        free_cnt = {(i, j):9 for i in xrange(9) for j in xrange(9)}
        left = 0
        occupy = {(i, j):[(False, -1)]*9 for i in xrange(9) for j in xrange(9)}
        for i in xrange(len(board)):
            board[i] = list(board[i]) #since string is inchangable, convert them to list
        for r, row in enumerate(board):
            for c, char in enumerate(row):
                if char == '.':
                    left += 1
                else:
                    i = int(char)
                    free_cnt[(r, c)] = 0
                    self.update4Writing((r, c), i, board, occupy, free_cnt)
        # initialize completed
        steps = []
        serial= (0, 0)
        while left > 0:
            retry = 0
            if serial[0] != -1:
                serial = self.getMinIndex(free_cnt, board)
            if serial[0] == -1:
                serial, t, retry = steps.pop()
                self.update4Removing(serial, t, board, occupy, free_cnt)
                retry += 1
                left += 1

            t = self.getValidNumber(occupy[serial], retry)

            if t == -1:
                serial = (-1, -1)
            else:
                steps.append((serial, t, retry))
                self.update4Writing(serial, t, board, occupy, free_cnt)
                left -= 1
        for i in range(len(board)): # convert board back
            board[i] = "".join(board[i])

    def update4Writing(self, serial, t, board, occupy, free_cnt):
        def _update(coord):
            if not occupy[coord][t][0]:
                free_cnt[coord] -= 1
                occupy[coord][t] = (True, serial)

        r, c = serial
        board[r][c] = str(t)
        t = t-1
        occupy[serial][t] = (True, serial)
        free_cnt[serial] -= 1
        for i in range(9):
            _update((r, i))
            _update((i, c))
        for ir in [r/3*3 + i for i in range(3)]:
            for ic in [c/3*3 + i for i in range(3)]:
                _update((ir, ic))

    def update4Removing(self, serial, t, board, occupy, free_cnt):
        def _update(coord):
            isoccupy, occ_serial = occupy[coord][t]
            if occ_serial == serial:
                free_cnt[coord] += 1
                occupy[coord][t] = (False, -1)

        r, c = serial
        board[r][c] = '.'
        t = t-1
        occupy[serial][t] = (False, -1)
        free_cnt[serial] += 1
        for i in range(9):
            _update((r, i))
            _update((i, c))
        for ir in [r/3*3 + i for i in range(3)]:
            for ic in [c/3*3 + i for i in range(3)]:
                _update((ir, ic))

    def getValidNumber(self, occupyItem, retry):
        count = 0
        for i, d in enumerate(occupyItem):
            if not d[0]:
                count += 1
                if count > retry:
                    return i + 1
        return -1

    def getMinIndex(self, free, board):
        min = sys.maxint
        min_coord = 0
        for coord, d in free.items():
            if board[coord[0]][coord[1]] != '.':
                continue
            if d >= 0 and d < min:
                min = d
                min_coord = coord
        if min == 0:
            return (-1, -1)
        return min_coord

if __name__ == "__main__":
    board = ["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
    ins = Solution()
    ins.solveSudoku(board)
    print board
    print
