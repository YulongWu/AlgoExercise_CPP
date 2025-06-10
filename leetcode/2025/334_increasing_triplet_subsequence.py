'''
My initial solution. Which is correct but more complex than it needs. Only 2 additional variables needed instead of 3.
The tricky part of this solution is using either < or <=.
'''
class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:
        min1 = float('inf')
        min21, min22 = float('inf'), float('inf')
        for i, v in enumerate(nums):
            if v < min1:
                min1 = v
            elif v < min22 and v > min1:
                min21, min22 = min1, v
            elif v > min22 and i > 1:
                return True
        return False

class SolutionOfLeetcode:
    def increasingTriplet(self, nums: list[int]) -> bool:
        num1, num2 = float('inf'), float('inf')
        for v in nums:
            if v <= num1:
                num1 = v
            elif v <= num2:
                num2 = v
            else:
                return True
        return False