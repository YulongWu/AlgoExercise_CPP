import sys
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums or len(nums) < 1:
            return None
        curSum = 0
        maxSum = nums[0]
        for i, num in enumerate(nums):
            if i == 0 or curSum <= 0:
                curSum = nums[i]
            else:
                curSum += nums[i]
            if maxSum < curSum:
                maxSum = curSum
        return maxSum
