'''
My initial solution, which has both time and space complexity as O(n). But the runtime distribution in leetcode is
implying that there is a faster solution.
'''
class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        ch_count = {}
        for i in nums:
            if i in ch_count:
                ch_count[i] += 1
            else:
                ch_count[i] = 1
        matches = 0
        for i in ch_count:
            while i <= k and k - i in ch_count and i in ch_count and ch_count[k - i] > 0 and ch_count[i] > 0:
                ch_count[i] -= 1
                ch_count[k - i] -= 1
                if ch_count[i] >= 0:
                    matches += 1
        return matches

'''
The faster solution I've thought out after the above. 
This solution has reduced runtime from 500+ ms to 400+ ms, although not much decrease, but the percentage I beat
increased from 29% to 89%, so good enough.
'''
class Solution2:
    def maxOperations(self, nums: list[int], k: int) -> int:
        ch_count = {}
        for i in nums:
            if i in ch_count:
                ch_count[i] += 1
            else:
                ch_count[i] = 1
        matches = 0
        for i in ch_count:
            if k - i not in ch_count or ch_count[i] <= 0 or ch_count[k - i] <= 0:
                continue
            new_matches = min(ch_count[i], ch_count[k - i])
            if i != k - i:
                matches += new_matches
                ch_count[i] -= new_matches
                ch_count[k - i] -= new_matches
            else:
                matches += new_matches // 2
                ch_count[i] = 0
        return matches

'''
Then, leetcode gives me another solution based on sort + two pointers, not optimized as above one, but still worth to 
be implemented. 
'''
class Solution3:
    def maxOperations(self, nums: list[int], k: int) -> int:
        nums.sort()
        left, right = 0, len(nums) - 1
        matches = 0
        while left < right:
            if nums[left] + nums[right] == k:
                matches += 1
                left += 1
                right -= 1
            elif nums[left] + nums[right] < k:
                left += 1
            else:
                right -= 1
        return matches