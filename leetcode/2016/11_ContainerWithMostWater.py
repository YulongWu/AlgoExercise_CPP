class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        lowbound, upbound = 0, len(height) - 1
        maxarea = 0
        while (lowbound < upbound):
            curarea = min(height[lowbound], height[upbound]) * (upbound - lowbound)
            if maxarea < curarea: maxarea = curarea
            i, j = lowbound, upbound
            if height[lowbound] <= height[upbound]:
                while i < j and height[i] <= height[lowbound]:
                    i += 1
            if height[lowbound] >= height[upbound]:
                while j > i and height[j] <= height[upbound]:
                    j -= 1
            lowbound, upbound = i, j
        return maxarea
if __name__ == '__main__':
    ins = Solution()
    print ins.maxArea([5,4,8,5])
