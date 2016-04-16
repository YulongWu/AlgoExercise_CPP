class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        orig_len = len(nums)
        if not nums or orig_len < 2:
            return orig_len
        p, q = 0, 1
        while q < len(nums):
            if nums[q] != nums[q-1]:
                nums[p] = nums[q-1]
                p += 1
            q += 1
        nums[p] = nums[q-1]
        return p + 1
