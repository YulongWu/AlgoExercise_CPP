'''
Worthnoting points:
1. Diff btw str.split() and str.split(' '), see line 7.
2. str.reverse() is changes s in-place, so no return value and cannot be chained. See line 9.
3. The signature of str.join() is easy to be mis-used, the delimiter is used in the beginning and iteratble as parameter.
'''
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip().split() # caution: split(' ') will keep empties without trimming extra spaces.
        s.reverse()
        return ' '.join(s)

import re
class Solution2:
    def reverseWords(self, s: str) -> str:
        s = re.sub(r'\s+', ' ', s.strip()).split()
        s.reverse()
        return ' '.join(s)