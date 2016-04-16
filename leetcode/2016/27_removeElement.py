class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if not nums:
            return 0
        p, q = 0, 0
        while q < len(nums):
            if nums[q] != val:
                nums[p] = nums[q]
                p += 1
            q += 1
        return p
