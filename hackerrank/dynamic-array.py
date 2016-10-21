# Enter your code here. Read input from STDIN. Print output to STDOUT

# Runtime Complexity: O(n), for n is the number of queries
# Spatial Complexity: O(n), for n is length of seqList
import sys
class Solution(object):

    def __init__(self, n, q):
        '''
        :type n: int
        :type q: int
        :rtype: None
        '''
        self.check_input(n, q)
        self.N = n
        self.Q = q
        self.lastAns = 0
        self.seqlist = [[] for i in range(n)]

    def locate_seq(self, x):
        '''
        :type x: int
        :rtype: int
        locate the index in sequence by x
        '''
        return (x ^ self.lastAns) % self.N

    def check_input(self, x, y):
        '''
        :type x: int
        :type y: int
        :rtype: None
        '''
        if (x < 0 or y < 0):
            raise Exception("illegal input: x={0}, y={1}".format(x, y))

    def query1(self, x, y):
        '''
        :type x: int
        :type y: int
        :rtype: None
        '''
        self.check_input(x, y)
        i = self.locate_seq(x)
        self.seqlist[i].append(y)

    def query2(self, x, y):
        '''
        :type x: int
        :type y: int
        :rtype: None
        '''
        self.check_input(x, y)
        i = self.locate_seq(x)
        j = y % len(self.seqlist[i])
        self.lastAns = self.seqlist[i][j]
        print self.lastAns

    def process_query(self, mode, x, y):
        '''
        :type mode: int
        :type x: int
        :type y: int
        :rtype: None
        '''
        if (mode == 1):
            self.query1(x, y)
        elif (mode == 2):
            self.query2(x, y)
        else:
            raise Exception("Illegal parameter: mode={0}".format(mode))

if __name__ == "__main__":
    line = sys.stdin.readline()
    n, q = line.split()
    ins = Solution(int(n), int(q))
    for line in sys.stdin:
        mode, x, y = line.split()
        ins.process_query(int(mode), int(x), int(y))
