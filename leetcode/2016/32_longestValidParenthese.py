class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        flags = [1]*len(s)
        ret, prev = 0, -1
        isopen = False
        for i, c in enumerate(s):
            if not isopen or c == '(':
                if prev > 0:
                    i = prev
                    prev = -1
                stack.append((c, i))
            else:
                p, j = stack.pop()
                if ret < i - j + 1:
                    ret = i - j + 1
                prev = j
                # for k in range(j, i+1):
                    # flags[k] = 0
                if len(stack) > 0:
                    c = stack[len(stack)-1][0]
            isopen = True if c == '(' else False
        return ret
