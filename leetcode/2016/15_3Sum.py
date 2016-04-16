import sys
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        if len(nums) < 3:
            return []
        nums.sort()
        for t in range(len(nums)-2):
            if nums[t] > 0: break
            if t > 0 and nums[t] == nums[t-1]: continue
            i, j = t+1, len(nums)-1
            while i < j:
                if nums[i] + nums[j] == -nums[t]:
                    res.append([nums[t], nums[i], nums[j]])
                    i += 1
                    j -= 1
                elif nums[i] + nums[j] > -nums[t]:
                    j -= 1
                else:
                    i += 1
                while i > t+1 and i < j and nums[i] == nums[i-1]: i += 1
                while j > i and nums[j] == nums[j+1]: j -= 1
        return res

if __name__ == '__main__':
    ins = Solution()
    print ins.threeSum([3,0,-2,-1,1,2])
