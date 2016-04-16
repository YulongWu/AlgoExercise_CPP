import sys

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cb3 = '([{'
        ce3 = ')]}'
        stack = []
        for c in s:
            if cb3.find(c) != -1:
                stack.append(cb3.find(c))
            elif ce3.find(c) != -1:
                if len(stack) == 0 or ce3.find(c) != stack.pop():
                    return False
        if len(stack) > 0:
            return False
        return True

if __name__ == '__main__':
    ins = Solution()
    print ins.isValid('[')
