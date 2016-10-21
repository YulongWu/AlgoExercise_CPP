import sys
class Solution(object):
    def rotate_ol1(self, matrix):
        '''
        method from others: https://leetcode.com/discuss/38426/seven-short-solutions-1-to-7-lines
        '''
        matrix[:] = zip(*matrix[::-1])

    def rotate_ol2(self, m):
        '''
        method from others: https://leetcode.com/discuss/38426/seven-short-solutions-1-to-7-lines
        '''
        n = len(m)
        for i in range(n/2):
            for j in range(n-n/2):
                m[i][j], m[~j][i], m[~i][~j], m[j][~i] = m[~j][i], m[~i][~j], m[j][~i], m[i][j]

    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n/2): #traverse half of the diagonal
            for j in range(n-1-i*2): #traverse the edges of the square
                nodes = [(i, i+j), (i+j, n-1-i), (n-1-i, n-1-i-j), (n-1-i-j, i)]
                node = nodes[0]
                t = matrix[node[0]][node[1]]
                for ii in range(3, 0, -1):
                    print nodes
                    print ii
                    matrix[nodes[(ii+1)%4][0]][nodes[(ii+1)%4][1]] = \
                            matrix[nodes[ii%4][0]][nodes[ii%4][1]]
                matrix[nodes[1][0]][nodes[1][1]] = t

if __name__ == '__main__':
    m = [[1,2,3], [4,5,6], [7,8,9]]
    ins = Solution()
    ins.rotate(m)
    print m
    m = [[1,2,3], [4,5,6], [7,8,9]]
    ins.rotate_ol1(m)
    print m
    m = [[1,2,3], [4,5,6], [7,8,9]]
    ins.rotate_ol2(m)
    print m
