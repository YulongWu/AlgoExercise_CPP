# following solution is my own solution for the first time. In fact, there's no need to store the whole board. So for SolutionNew, I implemented a solution referencing online solution, see below for detail
from collections import deque
class Solution(object):
    def check_available(self, n, board, i, j):
        board[i][j] = '.'
        for t in range(n):
            if board[i][t] == 'Q' or board[t][j] == 'Q':
                board[i][j] = 'Q'
                return False
        # check diagonal
        d4 = [(-1,-1), (1, -1), (-1, 1), (1, 1)]
        for d in d4:
            t = 1
            ii, jj = i + t * d[0], j + t * d[1]
            while ii >= 0 and ii < n and jj >= 0 and jj < n:
                if board[ii][jj] == 'Q':
                    board[i][j] = 'Q'
                    return False
                t += 1
                ii, jj = i + t * d[0], j + t * d[1]
        board[i][j] = 'Q'
        return True

    def _solveNQueens(self, n, board, res, i):
        if i == n:
            chessCopy = [list(i) for i in board]
            res.append(chessCopy)
            return
        for j in range(n):
            if j > 0:
                board[i][j-1] = '.'
            board[i][j] = 'Q'
            if self.check_available(n, board, i, j):
                self._solveNQueens(n, board, res, i+1)
        board[i][j] = '.'

    def solveNQueens_recursive(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        board = [['.']*n for i in range(n)]
        res = []
        self._solveNQueens(n, board, res, 0)
        return [[''.join(i) for i in j] for j in res]

    def solveNQueens_nonRecursive(self, n):
        board = [['.']*n for i in range(n)]
        res = []
        stack = deque()

        board[0][0] = 'Q'
        stack.append((0, 0))
        isback = False
        while len(stack) > 0:
            if isback:
                i, j = stack.pop()
                board[i][j] = '.'
                ni, nj = i, j+1
            else:
                i, j = stack[len(stack)-1]
                if i == n-1:
                    res.append([''.join(i) for i in board])
                    isback = True
                    continue
                ni, nj = i+1, 0
            while nj < n:
                board[ni][nj] = 'Q'
                if self.check_available(n, board, ni, nj):
                    stack.append((ni, nj))
                    isback = False
                    break
                board[ni][nj] = '.'
                nj += 1
            else:
                isback = True
        return res

    def solveNQueens(self, n):
        return self.solveNQueens_nonRecursive(n)

    def dump(self, res):
        for m in res:
            print '--------------------'
            for line in m:
                print line

# a new solution referencing by online: https://leetcode.com/discuss/92404/11-line-python-solution-easy-to-understand
class SolutionNew(object):
    boards = []
    mask = None
    def dumpBoard(self, board):
        res = []
        n = len(board)
        print "board: " + str(board)
        for c in board:
            if c == '.':
                res.append('.'*n)
            else:
                res.append('.'*c + 'Q' + '.'*(n-c-1))
        return res

    def _solveNQueens(self, board, row, boards):
        if row == len(board):
            boards.append(list(board))
        else:
            for col in self.mask - set(board):
                if all(row - i != abs(y - col) for i, y in enumerate(board[:row])):
                    board[row] = col
                    self._solveNQueens(board, row + 1, boards)
                    board[row] = '.'

    def solveNQueens(self, n):
        board = ['.']*n
        self.mask = {i for i in xrange(n)}
        boards = []
        self._solveNQueens(board, 0, boards)
        res = [self.dumpBoard(i) for i in boards]
        print res
        return res

# my imporved solution based on the above solution, which referenced this Java solution: https://leetcode.com/discuss/69603/easiest-java-solution-1ms-98-22%25
class SolutionNew2(object):
    def solveNQueens(self, n):
        flagCols = [False]*n
        flagDiagnal1 = [False]*n
        flagDiagnal2 = [False]*n
        res

if __name__ == '__main__':
    ins = Solution()
    res = ins.solveNQueens(6)
    ins.dump(res)
    insNew = SolutionNew()
    res = insNew.solveNQueens(2)
    ins.dump(res)
