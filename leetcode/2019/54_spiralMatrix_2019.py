class Solution(object):
    def spiralOrderRecursive(self, matrix, offset, rowBoundry, colBoundry):
        spiralOrder = []
        if offset > rowBoundry or offset > colBoundry:
            return []
        row = col = offset

        # move rightward
        while col <= colBoundry:
            spiralOrder.append(matrix[row][col])
            col += 1
        col = colBoundry

        # move downward
        row += 1
        while row <= rowBoundry:
            spiralOrder.append(matrix[row][col])
            row += 1
        row = rowBoundry

        if offset < rowBoundry and offset < colBoundry: # which means we have moved rightwards and downwards at least once
            # move leftward
            col -= 1
            while col >= offset:
                spiralOrder.append(matrix[row][col])
                col -= 1
            col = offset

            # move upward
            if offset < colBoundry:
                row -= 1
                while row > offset:
                    spiralOrder.append(matrix[row][col])
                    row -= 1

        t = self.spiralOrderRecursive(matrix, offset + 1, rowBoundry - 1, colBoundry - 1)
        spiralOrder += t if t is not None else []
        return spiralOrder


    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        numRow = len(matrix)
        numCol = len(matrix[0])

        return self.spiralOrderRecursive(matrix, 0, numRow - 1, numCol - 1)

if __name__ == '__main__':
    ins = Solution()
    print ins.spiralOrder([[1,2,3],[4,5,6],[7,8,9]])
    print ins.spiralOrder([[1,2,3],[4,5,6]])
    print ins.spiralOrder([[1,2,3]])
    print ins.spiralOrder([[1],[2],[3]])
