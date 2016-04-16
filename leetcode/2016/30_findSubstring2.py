class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words or len(s) == 0 or len(words) == 0:
            return []
        words_len = len(words[0])
        total_words_len = words_len * len(words)
        dic = {}
        for word in words:
            dic[word] = dic[word] + 1 if word in dic else 1

        res = []
        i = 0
        while i < len(s) - total_words_len + 1:
            if self._findSubstring(s[i:], dic.copy(), words_len):
                res.append(i)
            i += 1
        return res
    def _findSubstring(self, s, dic, l):
        i = 0
        while i< len(s):
            t = s[i:i+l]
            if t in dic:
                if dic[t] == 1:
                    dic.pop(t, None)
                    if len(dic) == 0:
                        return True
                else:
                    dic[t] -= 1
            else:
                return False
            i += l
        else:
            return False

if __name__ == "__main__":
    ins = Solution()
    # print ins.findSubstring("aaaaaa", ["a", "a", "a", "a", "a"])
    print ins.findSubstring("barfoothefoobarman", ["foo", "bar"])
