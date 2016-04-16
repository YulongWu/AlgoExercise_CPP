import sys
class Solution(object):
    def threeSum(self, nums, target, prev):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # print "calling: nums={0}, target={1}".format(nums, target)
        res = []
        if len(nums) < 3:
            return []
        # nums.sort()
        if target < sum(nums[:3]) or target > sum(nums[len(nums)-3:]): return []
        for t in range(len(nums)-2):
            if t == 0 and nums[t] == prev: continue
            if t > 0 and nums[t] == nums[t-1]: continue
            i, j = t+1, len(nums)-1
            while i < j:
                if nums[i] + nums[j] + nums[t] == target:
                    res.append([nums[t], nums[i], nums[j]])
                    i += 1
                    j -= 1
                elif nums[i] + nums[j] + nums[t] > target:
                    j -= 1
                else:
                    i += 1
                while i > t+1 and i < j and nums[i] == nums[i-1]: i += 1
                while j > i and j < len(nums)-1 and nums[j] == nums[j+1]: j -= 1
        # print 'return result: {0}'.format(res)
        return res
    '''
    time exceeded
    '''
    def fourSum(self, nums, target):
        '''
        '''
        res = []
        if len(nums) < 4:
            return []
        nums.sort()
        if target < sum(nums[:4]) or target > sum(nums[len(nums)-4:]): return []
        prev_t = 0
        for t in range(len(nums)-3):
            if t > 0 and nums[t] == prev_t: continue
            a = nums[t]
            l = self.threeSum(nums[t+1:], target - a, a)
            if len(l) > 0:
                for li in l:
                    li = [a] + li
                    res.append(li)
            prev_t = nums[t]
        return res

if __name__ == "__main__":
    ins = Solution()
    print ins.fourSum([-499,-449,-410,-386,-384,-357,-332,-321,-304,-290,-248,-243,-240,-220,-216,-207,-199,-197,-183,-172,-169,-164,-149,-143,-111,-108,-84,-57,-51,-49,-48,-7,-4,10,17,66,111,149,170,174,176,188,198,205,216,257,311,313,327,330,334,335,358,375,375,380,392,422,442,461,466,487], 3288)
