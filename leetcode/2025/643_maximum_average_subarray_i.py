'''
This problem is simple, not much worth to mention.
'''
class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        m = s = sum(nums[:k])
        i = k
        while i < len(nums):
            s -= nums[i - k]
            s += nums[i]
            m = max(s, m)
            i += 1
        return m / k