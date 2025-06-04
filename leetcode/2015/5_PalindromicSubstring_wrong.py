'''
Following method is a typical wrong solution worth to be noted.
This solution has 2 big issues:
1. It doesn't use memoization to reduce time complexity, results in O(2^n) exponential complexity.
2. When s[start] == s[end], it assumes the result sub string is within s[start + 1 : end -1], which is not guaranteed.
    This result in the solution not able to return correct result for inputs like "acabdaca".
'''
class Solution:
    def longestPalindrome(self, s: str) -> str:
        start, length = self.palindromeLength(s, 0, len(s) - 1)
        return s[start : start + length]

    def palindromeLength(self, s: str, start: int, end: int) -> (int, int):
        if start >= end:
            return start, 1
        if s[start] == s[end]:
            if start + 1 == end:
                return start, 2
            innerStart, innerLength = self.palindromeLength(s, start + 1, end - 1)
            if start + innerLength + 1 == end:
                return start, innerLength + 2
            else:
                return innerStart, innerLength
        else:
            innerStartRight, innerLengthRight = self.palindromeLength(s, start + 1, end)
            innerStartLeft, innerLengthLeft = self.palindromeLength(s, start, end - 1)
            return (
                (innerStartRight, innerLengthRight)
                if innerLengthRight > innerLengthLeft
                else (innerStartLeft, innerLengthLeft)
            )

if __name__ == '__main__':
    solution = Solution()
    print(solution.longestPalindrome("acabdaca"))