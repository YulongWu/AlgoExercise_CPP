class Solution(object):
    def _func(self, cands, tar, cur_l, cur_i, res):
        # print "cur_l:{0}\ncur_v:{1}\tcur_i:{2}".format(cur_l, cur_v, cur_i)
        if tar <= 0:
            if tar == 0:
                res.append(cur_l)
            return -1
        else:
            for i in range(cur_i, len(cands)):
                v = cands[i]
                if self._func(cands, tar-v, cur_l+[v], i, res) == -1:
                    break
            return 0

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        res = []
        self._func(candidates, target, [], 0, res)
        return res

if __name__ == "__main__":
    ins = Solution()
    cand = [11,10,5,7,8,12,3]
    tar = 29
    cand = [20,21,43,47,49,38,40,31,46,35,37,23,25,30,39,22,41,27,42,26,24,45,48,44,33,32]
    tar = 69
    cand = [20,39,38,47,23,21,40,44,29,46,33,22,24,35,49,48,32,25,43,30,34,26,36,45,41,27]
    tar = 73
    print ins.combinationSum(cand, tar)
