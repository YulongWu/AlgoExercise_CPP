class Solution:
    '''
    My initial solution, which is barely accepted by leetcode with 3s+ execution time.
    '''
    def moveZeroes(self, nums: list[int]) -> None:
        i_z, i_nz = 0, 0
        while i_z < len(nums):
            while i_z < len(nums) and nums[i_z] != 0:
                i_z += 1
            i_nz = i_z + 1
            while i_nz < len(nums) and nums[i_nz] == 0:
                i_nz += 1
            if i_z < len(nums) and i_nz < len(nums):
                nums[i_z], nums[i_nz] = nums[i_nz], nums[i_z]
            i_z += 1

class Solution2:
    '''
    2nd solution I thought out, reduced the number of swaps.
    Worth to mention:
    1. I missed line 31 initially, which results in wrong answer for input [1].
    2. The Python slicing on Line 32 is easy to mis-use. I initially used nums[:-num_of_zeros], which means all the
    items except last num_of_zeros ones.
    '''
    def moveZeroes(self, nums: list[int]) -> None:
        num_of_zeros = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                num_of_zeros += 1
            elif num_of_zeros > 0:
                nums[i - num_of_zeros] = nums[i]
        if num_of_zeros > 0:
            nums[-num_of_zeros:] = [0] * num_of_zeros