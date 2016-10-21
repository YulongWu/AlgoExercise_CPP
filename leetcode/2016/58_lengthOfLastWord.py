class Solution(object):
    # my solution
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        curLength, lastLength = 0, 0
        for c in s:
            if c == ' ':
                if curLength > 0:
                    lastLength = curLength
                curLength = 0
            else:
                curLength += 1
        if curLength > 0:
            lastLength = curLength
        return lastLength
    # other's one line solution
    def lengthOfLastWord(self, s):
        return len(s.rstrip(' ').split(' ')[-1])
