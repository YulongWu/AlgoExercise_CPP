'''
My initial simple solution using recursive calls.
'''
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s and not t or len(s) > len(t):
            return False
        if not s:
            return True
        if s[0] == t[0]:
            return True if len(s) == len(t) == 1 else self.isSubsequence(s[1:], t[1:])
        else:
            return self.isSubsequence(s, t[1:])

'''
My 2nd solution, which is non-recursive and running time dropped to 0 ms from 4 ms above.
'''
class Solution2:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        if not t:
            return False
        i_s, i_t = 0, 0
        while i_s < len(s) and i_t < len(t):
            if (s[i_s] == t[i_t]):
                i_s, i_t = i_s + 1, i_t + 1
            else:
                i_t += 1
            '''
            worth to note that above line 26-29 can be simplified to:
            if (s[i_s] == t[i_t]):
                i_s += 1
            i_t += 1
            '''
        return False if i_s < len(s) else True

'''
The leetcode official solutions have 2 more solutions, greedy search and DP. Both not as optimal as the Solution2. So, 
the 2 pointers is the best solution for this question.  
'''