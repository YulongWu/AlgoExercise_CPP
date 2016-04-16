# this solution is my 1st seen solution on discussion board, which used DP and O(n^2) complexity
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dp = [True] + [False] * len(s)
        for cp in p:
            if cp != '*':
                for n in reversed(range(len(s))):
                    dp[n+1] = dp[n] and (cp == s[n] or cp == '?')
            else:
                for n in xrange(1, len(s) + 1):
                    dp[n] = dp[n-1] or dp[n]
            dp[0] = dp[0] and cp == "*"
        return dp[-1]
