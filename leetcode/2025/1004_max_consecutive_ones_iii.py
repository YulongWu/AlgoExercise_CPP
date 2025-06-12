'''
my initial solution, which has O(n) space complexity, while the official solution has O(1).
'''
from collections import deque
class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        k_indexes = deque()
        max_len, cur_len = 0, 0
        k_remain = k
        for i, n in enumerate(nums):
            if n > 0:
                cur_len += 1
            else:
                if k_remain > 0:
                    k_remain -= 1
                    k_indexes.append(i)
                    cur_len += 1
                else:
                    if k > 0:
                        prev_i = k_indexes.popleft()
                        k_indexes.append(i)
                        cur_len = i - prev_i
                    else:
                        cur_len = 0
            max_len = max(cur_len, max_len)
        return max_len

'''
The official solution is based on 2 pointers.
'''
class Solution2:
    def longestOnes(self, nums: list[int], k: int) -> int:
        left = 0
        cur, ans = 0, 0
        for right in range(len(nums)):
            if not nums[right]:
                cur += 1
                while cur > k:
                    if not nums[left]:
                        cur -= 1
                    left += 1
            ans = max(ans, right - left + 1)
        return ans