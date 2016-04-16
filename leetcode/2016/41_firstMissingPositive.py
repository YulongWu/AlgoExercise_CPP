class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in xrange(len(nums)):
            d = nums[i]
            while d <= 0 or d > n or nums[d-1] != d:
                nums[d-1], d = d, nums[d-1]
        for i in xrange(len(nums)):
            if nums[i] != i + 1:
                return i+1
        return len(nums)+1
