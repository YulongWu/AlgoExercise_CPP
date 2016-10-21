class Solution(object):
    def circleRecursive(self, matrix, res, si, sj, ei, ej):
        if sj >= ej or si >= ei:
            return
        for j in range(sj, ej):
            res.append(matrix[si][j])
        if si + 1< ei:
            for i in range(si+1, ei):
                res.append(matrix[i][j])
        else:
            return
        if j > sj:
            for j in range(j-1, sj-1, -1):
                res.append(matrix[i][j])
        else:
            return
        for i in range(i-1, si, -1):
            res.append(matrix[i][j])
        self.circleRecursive(matrix, res, si+1, sj+1, ei-1, ej-1)

    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res = []
        if matrix:
            self.circleRecursive(matrix, res, 0, 0, len(matrix), len(matrix[0]))
        return res
