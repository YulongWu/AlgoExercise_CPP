class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        b, e = 0, len(nums)-1
        while b <= e:
            m = (b+e)/2
            if nums[m] == target:
                return m
            elif nums[m] >= nums[b]:
                if target >= nums[b] and target < nums[m]:
                    e = m - 1
                else:
                    b = m + 1
            else:
                if target > nums[m] and target <= nums[e]:
                    b = m + 1
                else:
                    e = m - 1
        else:
            return -1
