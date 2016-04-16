#!/usr/bin/py
# Head ends here
class Solution:
    caledstr = {}
    def stringReduction(self, a):
        if a in self.caledstr:
            return self.caledstr[a]
        min_len = len(a)
        for i in range(len(a)-1):
            if a[i] != a[i+1]:
                for c in 'abc':
                    if c != a[i] and c != a[i+1]:
                        cand_str = a[:i]+c+a[i+2:]
                        sub_len = self.stringReduction(cand_str)
                        if min_len > sub_len: min_len = sub_len
        self.caledstr[a] = min_len
        return min_len
# Tail starts here
if __name__ == '__main__':
    t = input()
    for i in range(0,t):
        a=raw_input()
        ins = Solution()
        print ins.stringReduction(a)
