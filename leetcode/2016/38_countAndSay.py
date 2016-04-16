class Solution(object):
    def _next(self, s):
        c = 1
        r = ''
        for i in xrange(len(s)):
            if i<len(s)-1 and s[i] == s[i+1]:
                c += 1
            else:
                r += str(c)+s[i]
                c = 1
        return r
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for i in xrange(n-1):
            s = self._next(s)
        return s
