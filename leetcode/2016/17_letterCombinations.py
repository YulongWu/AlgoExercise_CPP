import sys
reload(sys)
sys.setdefaultencoding('u8')

import itertools as itt

class Solution(object):
    letterMap = [' ', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wyxz']
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        if digits: self._letterCombinations(digits, '', res)
        return res
    def _letterCombinations(self, digits, cur, res):
        if not digits:
            res.append(cur)
        else:
            for c in self.letterMap[int(digits[0])]:
                self._letterCombinations(digits[1:], cur+c, res)

    def letterCombinations2(self, digits):
        '''
        a nice solution from here: https://leetcode.com/discuss/78597/almost-2-line-python-solution
        '''
        g = map(lambda x: self.letterMap[int(x)], digits) # equals to [letterMap[int(x)] for x in digits]
        return [''.join(l) for l in itt.product(*g)]

if __name__ == '__main__':
    ins = Solution()
    print ins.letterCombinations('3')
