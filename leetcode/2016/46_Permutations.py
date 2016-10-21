class Solution(object):
    res = []
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
    def _permute(self, nums, i):
        if i == 0:
            self.res = []
        if len(nums) - 1 == i:
            self.res.append(list(nums))
        self._permute(nums, i+1)
        for j in xrange(i+1, len(nums)):
            nums[i], nums[j] = nums[j], nums[i]
            self._permute(nums, i+1)
            nums[i], nums[j] = nums[j], nums[i]
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self._permute(nums, 0)
        return self.res
