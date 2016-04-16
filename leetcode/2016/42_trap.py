class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        hstack = [(0, 0)]
        pre_h, area = 0, 0
        for i, h in enumerate(height):
            if pre_h < h:
                t = 0
                while len(hstack) > 0 and pre_h < h:
                    t, left = hstack.pop()
                    minh = min(left, h)
                    area += (minh-pre_h) * (i - t - 1)
                    pre_h = left
                if pre_h > h:
                    hstack.append((t, pre_h))
            elif pre_h > h:
                hstack.append((i-1, pre_h))
            pre_h = h
        return area

if __name__ == "__main__":
    ins = Solution()
    h = [0,1,0,2,1,0,1,3,2,1,2,1]
    # h = [0,1,0,2]
    print ins.trap(h)
