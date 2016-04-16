class Solution(object):
    def getCubeNum(self, i, j):
        i = i/3
        j = j/3
        return i * 3 + j

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        index = {}
        for r, row in enumerate(board):
            for c, char in enumerate(row):
                if char == '.':
                    continue
                elif char in index:
                    index[char].append((r, c))
                else:
                    index[char] = [(r,c)]
        occupy = {}
        for i in range(1, 10):
            char = str(i)
            occupy[char] = [[0]*9, [0]*9, [0]*9]
        for key in index:
            for i, j in index[key][0]:
                if occupy[key][0][i] == 1 or \
                        occupy[key][1][j] == 1 or \
                        occupy[key][2][self.getCubeNum(i, j)] == 1:
                    return False
                else:
                   occupy[key][0][i] = 1
                   occupy[key][1][j] = 1
                   occupy[key][2][self.getCubeNum(i, j)] = 1
        return True
