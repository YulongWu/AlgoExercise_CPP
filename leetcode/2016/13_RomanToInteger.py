#coding: u8
import sys

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        D = [["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
        ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
        ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
        ["", "M", "MM", "MMM"]]
        t = 0
        res = 0
        while len(s) != 0:
            for l, i in [(4, 8), (3, 3), (3, 7), (2, 2), (2, 4), (2, 6), (2, 9), (1, 1), (1, 5)]:
                if len(s) < l:
                    continue
                if len(D[t]) > i and s[len(s)-l:len(s)] == D[t][i]:
                    res += 10**t * i
                    s = s[:len(s)-l]
                    break
            else:
                if t == 3:
                    raise Exception("Error input: illegal Roman")
            t += 1
        return res
    '''
    solution from https://leetcode.com/discuss/42217/my-straightforward-python-solution
    Learned: 一定要了解理解题的规律再想方法
    '''
    def romanToInt2(self, s):
        roman = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
        z = 0
        for i in range(0, len(s) - 1):
            if roman[s[i]] < roman[s[i+1]]:
                z -= roman[s[i]]
            else:
                z += roman[s[i]]
        return z + roman[s[-1]]

if __name__ == '__main__':
    ins = Solution()
    print ins.romanToInt('MCDXXXVII')

