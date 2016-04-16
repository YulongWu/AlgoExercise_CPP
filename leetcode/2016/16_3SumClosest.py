import sys
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return []
        res = nums[0] + nums[1] + nums[2]
        nums.sort()
        for t in range(len(nums)-2):
            if t > 0 and nums[t] == nums[t-1]: continue
            i, j = t+1, len(nums)-1
            while i < j:
                sum = nums[i] + nums[j] + nums[t]
                if sum > target:
                    j -= 1
                elif sum < target:
                    i += 1
                else:
                   return target
                if abs(sum - target) < abs(res - target):
                    res = sum
        return res

if __name__ == '__main__':
    ins = Solution()
    print ins.threeSumClosest([-1,2,1,-4], 1)
