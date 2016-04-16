class Solution(object):
    def _func(self, cands, tar, cur_l, cur_i, res):
        # print "cur_l:{0}\ncur_v:{1}\tcur_i:{2}".format(cur_l, cur_v, cur_i)
        if cur_i >= len(cands) or tar <= 0:
            if tar == 0:
                res.add(tuple(cur_l))
        else:
            v = cands[cur_i]
            self._func(cands, tar, cur_l, cur_i+1, res)
            self._func(cands, tar - v, cur_l+[v], cur_i+1, res)
    def combinationSum2(self, candidates, target):
        candidates.sort()
        table = [None] + [set() for i in range(target)]
        for i in candidates:
            if i > target:
                break
            for j in range(target - i, 0, -1):
                table[i + j] |= {elt + (i,) for elt in table[j]}
            table[i].add((i,))
        return map(list, table[target])
    def combinationSum22(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        # seen = set()
        # set_add = seen.add
        # cands = [x for x in candidates if not (x in seen or set_add(x))]
        res = set()
        self._func(candidates, target, [], 0, res)
        res2 = []
        for r in res:
            res2.append(list(r))
        return list(res2)

if __name__ == "__main__":
    ins = Solution()
    cand = [10,1,2,7,6,1,5]
    tar = 8
    # cand = [22,21,18,18,23,14,26,14,34,8,33,29,32,14,6,32,34,22,25,14,25,31,9,7,20,31,34,32,18,34,8,27,13,21,10,31,22,24,10,13,27,8,7,16,10,30,5,9,17,26,11,8,22,7]
    # tar = 25
    print ins.combinationSum2(cand, tar)
