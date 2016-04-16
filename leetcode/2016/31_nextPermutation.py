class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i+1]:
                min = nums[i+1]
                min_i = i+1
                for j in range(i+1, len(nums)):
                    if nums[j] > nums[i] and nums[j] < min:
                        min = nums[j]
                        min_i = j
                nums[i], nums[min_i] = nums[min_i], nums[i]
                nums[i+1:] = sorted(nums[i+1:])
                return
            else:
                i -= 1
        else:
            nums.sort()
