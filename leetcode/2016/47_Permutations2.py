import sys
class Solution(object):
    res = []
    def _permuteUnique(self, nums, i):
        if i == 0:
            self.res = []
        if i == len(nums)-1:
            self.res.append(list(nums))
        else:
            self._permuteUnique(nums, i+1)
            occupy = set()
            for j in xrange(i+1, len(nums)):
                if nums[i] != nums[j] and nums[j] not in occupy:
                    occupy.add(nums[j])
                    nums[i], nums[j] = nums[j], nums[i]
                    self._permuteUnique(nums, i+1)
                    nums[i], nums[j] = nums[j], nums[i]

    def permuteUnique_recursive(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self._permuteUnique(nums, 0)
        return len(self.res)

    def update_occupy(bitoccupy, i, v):
        if i not in bitoccupy:
            bitoccupy[i] = set(v)
        else:
            bitoccupy[i].add(v)

    def permuteUnique(self, nums):
        res = []
        stack = [(0, nums)]
        while len(stack) > 0:
            i, ns = stack.pop()
            if i < len(nums):
                stack.append((i+1, list(ns)))
                for j in xrange(i+1, len(ns)):
                    if ns[i] != ns[j]:
                        ns[i], ns[j] = ns[j], ns[i]
                        stack.append((i+1, list(ns)))
                        ns[i], ns[j] = ns[j], ns[i]
            else:
                res.append(ns)
        return len(res)
        # return res

# other posted answers
def permuteUnique(nums):
    ans = [[]]
    for n in nums:
        #print >> sys.stderr, "1. n={0}".format(n)
        #print >> sys.stderr, "2. ans={0}".format(ans)
        new_ans = []
        for l in ans:
            #print >> sys.stderr, "3. l={0}".format(l)
            for i in xrange(len(l)+1):
                t = l[:i]+[n]+l[i:]
                #print >> sys.stderr, "4. add to new_ans={0}".format(t)
                new_ans.append(t)
                if i<len(l) and l[i]==n:
                    #print >> sys.stderr, "4.5. break for l={1}, l[i]={0}".format(l[i], l)
                    break              #handles duplication
        #print >> sys.stderr, "5. new_ans={0}".format(new_ans)
        ans = new_ans
    #print >> sys.stderr, "6. ans={0}".format(ans)
    return len(ans)
    # return ans

if __name__ == '__main__':
    ins = Solution()
    print permuteUnique([2, 2, 3])
    print ins.permuteUnique([2, 2, 3])
    print permuteUnique([3,3,0,0,2,3,2])
    print ins.permuteUnique_recursive([3,3,0,0,2,3,2])
    print permuteUnique([1,1,2,2])
    print ins.permuteUnique_recursive([1,1,2,2])
