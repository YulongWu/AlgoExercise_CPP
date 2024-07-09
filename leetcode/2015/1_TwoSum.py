class Solution:
    def twoSum(self, nums: List[int], target:int) -> List[int]:
        nums_set = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in nums_set:
                return nums_set[complement], i + 1
            else:
                nums_set[nums[i]] = i + 1

if __name__ == "__main__":
    ins = Solution()
    res = ins.twoSum([15, 2, 11, 7], 9)
    print("[{0}, {1}]".format(res[0], res[1]))
