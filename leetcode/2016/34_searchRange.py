class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        b, e = 0, len(nums)-1
        while b <= e:
            m = (b+e)/2
            if nums[m] > target:
                e = m - 1
            elif nums[m] < target:
                b = m + 1
            else:
                return [getBound(nums, 0, m-1, 0), getBound(nums, m+1, len(nums)-1, 1)]
        return [-1, -1]
    def getBound(nums, low, high, mode):
        while low <= high:
            m = (low+high)/2
            if nums[m] == target:
                if mode == 0: high = m - 1
                else: low = m + 1
            else:
                if mode == 0: low = m + 1
                else: high = m - 1
        return high + 1 if mode == 0 else low - 1

if __name__ == "__main__":
    ins = Solution()
    print ins.searchRange([])
