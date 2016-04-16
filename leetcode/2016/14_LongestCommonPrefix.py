import sys
class Solution(object):
    '''
    runtime: 56ms only beats 24.12%
    '''
    def commonPrefix(self, str1, str2):
        i = 0
        for i, c in enumerate(str1):
            if i == len(str2) or c != str2[i]:
                break
        else:
            return str1
        return str1[0:i]
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
        elif len(strs) == 1:
            return strs[0]
        elif len(strs) == 2:
            return self.commonPrefix(strs[0], strs[1])
        else:
            return self.commonPrefix(self.longestCommonPrefix(strs[0:len(strs)/2]), self.longestCommonPrefix(strs[len(strs)/2:len(strs)]))
    def longestCommonPrefix2(self, strs):
        '''
        my another solution: 48ms
        '''
        res = ''
        isbreak = False
        i = 0
        while not isbreak and len(strs) > 0 and len(strs[0]) > i:
            c = strs[0][i]
            for s in strs:
                if len(s) <= i or c != s[i]:
                    isbreak = True
                    break
            else:
                i += 1
                res += c
        return res
    def longestCommonPrefix3(self, strs):
        '''
        a solution from https://leetcode.com/discuss/19303/simple-python-solution
        nice use of zip function
        '''
        if not strs:
            return ""
        for i, letter_group in enumerate(zip(*strs)):
            if len(set(letter_group)) > 1:
                return strs[0][:i]
        else:
            return min(strs)
    def longestCommonPrefix4(self, strs):
        '''
        my improved solution based on previous one
        Runtime: 72 ms
        '''
        if not strs:
            return ''
        def func(*t):
            for i in range(len(t)-1):
                if t[i] != t[i+1]:
                    return 0
            else:
                return 1
        def count1(l):
            for i, k in enumerate(l):
                if k == 0:
                    return i
        return strs[0][:count1(map(func, *strs))]

if __name__ == '__main__':
    ins = Solution()
    print ins.longestCommonPrefix(['abcde', 'abcee', 'abdde'])
    print ins.longestCommonPrefix2(['abcde', 'abcee', 'abdde'])
    print ins.longestCommonPrefix3(['abcde', 'abcee', 'abdde'])
    print ins.longestCommonPrefix4(['abcde', 'abcee', 'abdde'])
