class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        runtime: 44 ms (non-recursive)
        b: balance
        k: left parenthesises
        """
        res = [('', 0, n)]
        maxn = n
        while maxn > 0:
            maxn = 0
            l = len(res)
            for i in range(l):
                s, b, k = res[i]
                maxn = k if k > maxn else maxn
                if k > 0:
                    res[i] = (s+'(', b+1, k-1)
                    if b > 0:
                        res.append((s+')', b-1, k))
                elif b > 0:
                    res[i] = (s+')', b-1, k)
        return [s[0] for s in res]
    '''
    1st solution on https://leetcode.com/discuss/43122/4-7-lines-python
    runtime: 56 ms
    '''
    def generateParenthesis2(self, n):
        def generate(p, left, right, parens=[]):
            print "p={0}, left={1}, right={2}, parens={3}".format(p, left, right, parens)
            if left:         generate(p + '(', left-1, right)
            if right > left: generate(p + ')', left, right-1)
            if not right:    parens += p,
            return parens
        return generate('', n, n)
    '''
    2nd solution on https://leetcode.com/discuss/43122/4-7-lines-python
    runtime: 56 ms
    '''
    def generateParenthesis3(self, n):
        def generate(p, left, right):
            if right >= left >= 0:
                if not right:
                    yield p
                for q in generate(p + '(', left-1, right): yield q
                for q in generate(p + ')', left, right-1): yield q
        return list(generate('', n, n))
    '''
    3rd solution on https://leetcode.com/discuss/43122/4-7-lines-python
    runtime: 52 ms
    '''
    def generateParenthesis(self, n, open=0):
    if n > 0 <= open:
        return ['(' + p for p in self.generateParenthesis(n-1, open+1)] + \
               [')' + p for p in self.generateParenthesis(n, open-1)]
    return [')' * open] * (not n)
if __name__ == '__main__':
    ins = Solution()
    print ins.generateParenthesis(3)
    print ins.generateParenthesis2(3)
