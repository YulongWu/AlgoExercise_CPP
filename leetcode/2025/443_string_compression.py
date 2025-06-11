'''
My initial solution. It's correct, but line 16-19 is duplicated with line 23-26.
Leetcode's official solution is similar but has no duplication. They achieve it by compress in a nested loop.
While, worth to mention that my solution is actually faster than the official solution. I guess the main reason is that
nested loop still take more time even if the complexity is still O(n).
'''
class Solution:
    def compress(self, chars: list[str]) -> int:
        ch, n = '', 0
        ii = 0
        for i, v in enumerate(chars):
            if i == 0:
                ch, n = v, 1
            elif v == ch:
                n += 1
            else:
                chars[ii] = ch
                ii += 1
                if n > 1:
                    n_s = str(n)
                    chars[ii: ii+len(n_s)] = n_s
                    ii += len(n_s)
                ch, n = v, 1
        chars[ii] = ch
        ii += 1
        if n > 1:
            n_s = str(n)
            chars[ii: ii+len(n_s)] = n_s
            ii += len(n_s)
        return ii

class SolutionOfLeetcode:
    def compress(self, chars: list[str]) -> int:
        i, res = 0, 0
        while i < len(chars):
            group_length = 1
            chars[res] = chars[i]
            res += 1
            while (i + group_length < len(chars)
                   and chars[i] == chars[i + group_length]):
                group_length += 1
            if group_length > 1:
                s = str(group_length)
                chars[res : res + len(s)] = s
                res += len(s)
            i += group_length
        return res
