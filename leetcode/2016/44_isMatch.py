# this solution is my original solution, without using DP, so it will result in time limit exceed
class Solution(object):
    def isMatch(self, s, p):
        note = {}
        return self._isMatch(s, p, 0, 0, note)
    def _isMatch(self, s, p, si, pi, note):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if (si, pi) in note:
            return note[(si, pi)]
        if si == len(s) and pi == len(p):
            note[(si, pi)] = True
        elif pi == len(p):
            note[(si, pi)] = False
        else:
            if p[pi] == '*':
                i = si
                res = False
                while not res and i <= len(s):
                    res |= self._isMatch(s, p, i, pi+1, note)
                    i += 1
                note[(si, pi)] = res
            elif p[pi] == '?':
                note[(si, pi)] = self._isMatch(s, p, si+1, pi+1, note)
            else:
                note[(si, pi)] = len(s)-si>0 and p[pi] == s[si] and self._isMatch(s, p, si+1, pi+1, note)
        return note[(si, pi)]
if __name__ == "__main__":
    ins = Solution()
    s = ''
    p = 'a'
    s = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab"
    p = "***bba**a*bbba**aab**b"
    s = "bbaaaabaaaaabbabbabbabbababaabababaabbabaaabbaababababbabaabbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa"
    p = "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a****"
    s = 'aa'
    p = 'aa'
    s = 'c'
    p = '*?*'
    s = "abbabbbbbabbbababbabbabbbbbbabbaaaaabbbabbbbbbbbababbbabaaaabbabbbbaabaaaabbbaabaaabaaaaaabbbbbaaaabbbbbbabaabbaabaabaaabbbababbbbaaababbbbaaaaabaabbbbaaaabbbbabbabbababaaabbaabbbaaaaabbaaababaabbbaaaa"
    p = "a*bb**ba***a**bb*bb**babab*ab*a*b**aaaa*a***ba**ba*ab**baab***aba*baa**aa**b*bbbbab***a*a*b*abaab*aba*ba"
    print ins.isMatch(s, p)
