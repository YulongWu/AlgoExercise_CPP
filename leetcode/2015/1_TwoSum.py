class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        num_set = {}
        for i in range(len(num)):
            if target - num[i] in num_set:
                return num_set[target - num[i]], i + 1
            else:
                num_set[num[i]] = i + 1;
        return 0, 0
if __name__ == "__main__":
    ins = Solution();
    res = ins.twoSum([15,2,11,7], 9)
    print "[ {0:d}, {1:d} ]".format(res[0], res[1])
