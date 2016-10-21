class Solution(object):
    def _genFactorial(self, factorial, n):
        for i in range(1, n+1):
            if i == 1:
                factorial[i] = 1
            else:
                factorial[i] = i * factorial[i-1]

    def get_i(self, mask, i):
        if i >= len(mask):
            raise "Error2!"
        return mask.pop(i)

    def _getPermutation(self, s, mask, factorial, n, k):
        if n == 0:
            return
        if n == 1:
            s += str(k)
            return
        if k > factorial[n]:
            raise "Error!"
        if k > factorial[n-1]:
            s += str(self.get_i(mask, k / factorial[n-1] + 1))
            s = self._getPermutation(s, mask, factorial, n-1, k - factorial[n-1])
        else:
            s = self._getPermutation(s, mask, factorial, n-1, k)
        return s

    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        mask = range(1, n+1)
        factorial = {}
        res = ''
        self._genFactorial(factorial, n)
        res = self._getPermutation(res, mask, factorial, n, k)
        return res
