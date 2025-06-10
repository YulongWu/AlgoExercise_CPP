'''
My 1st solution is O(n^2) complexity, and I cannot think out an O(n) solution without using division. :(
While, after I checked Leetcode official video, when the video hasn't reached the solution, I got the solution already.
'''
class Solution1:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        ret = [1] * len(nums)
        for i, num in enumerate(nums):
            for j in range(len(ret)):
                if j != i:
                    ret[j] *= num
        return ret

'''
This is my 2nd solution, it is correct. While the Leetcode official solution is more concise. 
Worth to note and learn the reverse() method on the line 51 in Leetcode official solution.
'''
class Solution2:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        prefix_products = [1] * len(nums)
        suffix_products = [1] * len(nums)
        self.build_products(prefix_products, nums, 1)
        self.build_products(suffix_products, nums, -1)

        ret = [1] * len(nums)
        for i in range(len(nums)):
            ret[i] = prefix_products[i] * suffix_products[i]
        return ret

    def build_products(self, products: list[int], nums: list[int], step: int):
        indexes = range(len(nums)) if step > 0 else range(len(nums) - 1, -1, -1)
        for i in indexes:
            if step > 0 and i == 0 or step < 0 and i == len(nums) - 1:
                products[i] = 1
            else:
                products[i] = products[i - step] * nums[i - step]

'''
Leetcode official solution.
'''
class SolutionOfLeetcode:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        length = len(nums)
        L, R, answer = [0] * length, [0] * length, [0] * length

        L[0] = 1
        for i in range(1, length):
            L[i] = nums[i - 1] * L[i - 1]

        R[length - 1] = 1
        for i in reversed(range(length - 1)):
            R[i] = nums[i + 1] * R[i + 1]

        for i in range(length):
            answer[i] = L[i] * R[i]

        return answer