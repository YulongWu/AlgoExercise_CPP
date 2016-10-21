import sys
import collections
class Solution(object):
    def groupAnagrams_ol1(self, strs):
        count = collections.Counter([tuple(sorted(s)) for s in strs])
        return filter(lambda x: count[tuple(sorted(x))]>1, strs)
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        runtime complexity: O(nklogk) for n is the number of strs, k is max length of str in strs
        spatial complexity: O(n)
        """
        anagramMap = {}
        c = 0
        res = []
        for s in strs:
            ss = ''.join(sorted(s))
            if ss not in anagramMap:
                anagramMap[ss] = c
                c += 1
                res.append([s])
            else:
                res[anagramMap[ss]].append(s)
        return [sorted(i) for i in res]

if __name__ == '__main__':
    ins = Solution()
    print ins.groupAnagrams_ol1(["eat", "tea", "tan", "ate", "nat", "bat"])
