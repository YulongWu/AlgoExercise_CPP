class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m < 0 or n < 0:
            return -1
        factorialBuf = [1]*(m+n+1)
        for i in range(1, m+n+1):
            factorialBuf[i] = i * factorialBuf[i-1]
        return factorialBuf[m+n] / (factorialBuf[m] * factorialBuf[n])
