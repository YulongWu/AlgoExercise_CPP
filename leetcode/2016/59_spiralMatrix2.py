class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        # if n == 0:
        #     return []   # improve 1: this is not necessary
        m = [[0]*n for i in range(n)]
        d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        i, j, c, b = 0, 0, -1, 0
        while c < n*n:
            # move right
            while j < n - b:
                c += 1
                m[i][j] = c
                j += 1
            j -= 1
            # move down
            i += 1
            while i < n - b:
                c += 1
                m[i][j] = c
                i += 1
            i -= 1
            # move left
            j -= 1
            while j >= b:
                c += 1
                m[i][j] = c
                j -= 1
            j += 1
            # move up
            i -= 1
            while i > b:
                c += 1
                m[i][j] = c
                i -= 1
            i += 1
            b += 1
            j += 1
    # other's more elegant answer
    # https://leetcode.com/discuss/46720/4-9-lines-python-solutions
    def generateMatrix(self, n):
        m = [[0]*n for _ in range(n)]
        i, j, di, dj = 0, 0, 0, 0, 1
        for k in xrange(n*n):
            m[i][j] = k + 1
            if m[(i+di)%n][(j+dj)%n]:
                di, dj = dj -di
            i += di
            j += dj
        return m
