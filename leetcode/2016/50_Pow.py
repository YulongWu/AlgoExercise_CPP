class Solution(object):
    def _myPow(self, x, n):
        if n == 1:
            return x
        t = self._myPow(x, n>>1)
        res = t * t
        if n & 1:
            res *= x
        return res
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1.0
        if x == 0.0:
            if n < 0:
                raise "Input Error!"
            else:
                return 0.0
        if x == 1.0:
            return x
        if x < 0:
            if n & 1: # n is odd
                return -self.myPow(abs(x), n)
            else:
                return self.myPow(abs(x), n)
        if n < 0:
            return 1.0 / self.myPow(x, abs(n))
        return self._myPow(x, n)
