import sys
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        t, c = nums[0], 1
        for i in nums[1:]:
            if t == i:
                c += 1
            else:
                c -= 1
                if c == 0:
                    t = i; c = 1
        return t
    def majorityElement(self, nums):
        return sorted(nums)[len(nums)/2]

if __name__ == '__main__':
    ins = Solution()
    print ins.majorityElement([1,2,2,2,3,3])
