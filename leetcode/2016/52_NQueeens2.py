from collections import deque
class Solution(object):
    def check_available(self, n, chess, i, j):
        chess[i][j] = '.'
        for t in range(n):
            if chess[i][t] == 'Q' or chess[t][j] == 'Q':
                chess[i][j] = 'Q'
                return False
        # check diagonal
        d4 = [(-1,-1), (1, -1), (-1, 1), (1, 1)]
        for d in d4:
            t = 1
            ii, jj = i + t * d[0], j + t * d[1]
            while ii >= 0 and ii < n and jj >= 0 and jj < n:
                if chess[ii][jj] == 'Q':
                    chess[i][j] = 'Q'
                    return False
                t += 1
                ii, jj = i + t * d[0], j + t * d[1]
        chess[i][j] = 'Q'
        return True

    def _solveNQueens(self, n, chess, res, i):
        if i == n:
            chessCopy = [list(i) for i in chess]
            res.append(chessCopy)
            return
        for j in range(n):
            if j > 0:
                chess[i][j-1] = '.'
            chess[i][j] = 'Q'
            if self.check_available(n, chess, i, j):
                self._solveNQueens(n, chess, res, i+1)
        chess[i][j] = '.'

    def solveNQueens_recursive(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        chess = [['.']*n for i in range(n)]
        res = []
        self._solveNQueens(n, chess, res, 0)
        return [[''.join(i) for i in j] for j in res]

    def solveNQueens_nonRecursive(self, n):
        chess = [['.']*n for i in range(n)]
        res = []
        stack = deque()

        chess[0][0] = 'Q'
        stack.append((0, 0))
        isback = False
        while len(stack) > 0:
            if isback:
                i, j = stack.pop()
                chess[i][j] = '.'
                ni, nj = i, j+1
            else:
                i, j = stack[len(stack)-1]
                if i == n-1:
                    res.append([''.join(i) for i in chess])
                    isback = True
                    continue
                ni, nj = i+1, 0
            while nj < n:
                chess[ni][nj] = 'Q'
                if self.check_available(n, chess, ni, nj):
                    stack.append((ni, nj))
                    isback = False
                    break
                chess[ni][nj] = '.'
                nj += 1
            else:
                isback = True
  # following method is correct but not very efficient, above is an ongoing try for better one.
#             if isback:
                # i, j = stack.pop()
                # chess[i][j] = '.'
                # if j == n-1:
                    # continue # go up level
                # chess[i][j+1] = 'Q'
                # stack.append((i, j+1))
                # if self.check_available(n, chess, i, j+1):
                    # isback = False
            # else:
                # i, j = stack[len(stack)-1]
                # if i == n-1:
                    # res.append([''.join(i) for i in chess])
                    # isback = True
                # else:
                    # chess[i+1][0] = 'Q'
                    # stack.append((i+1, 0))
                    # if not self.check_available(n, chess, i+1, 0):
                        # isback = True
        return res

    def solveNQueens(self, n):
        return self.solveNQueens_nonRecursive(n)
    def totalNQueens(self, n):
        return len(self.solveNQueens_nonRecursive(n))

    def dump(self, res):
        for m in res:
            print '--------------------'
            for line in m:
                print line

if __name__ == '__main__':
    ins = Solution()
    res = ins.solveNQueens(6)
    print ins.totalNQueens(6)
    ins.dump(res)
