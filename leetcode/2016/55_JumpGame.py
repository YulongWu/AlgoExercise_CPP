
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums or len(nums) == 0:
            return False
        flags = [False] * len(nums)
        flags[0] = True
        i, max = 0, 1 #performance error: don't use max to improve performance
        while(i <= max and i < len(nums)-1):
            if i + nums[i] > max:
                max = i + nums[i]
            i += 1
        return True if i==len(nums) else False

if __name__ == "__main__":
    ins = Solution()
    print ins.canJump([3,2,1,0,4])
