class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map = [-1] * 256
        start, length, maxLength = 0, 0, 0
        for i in range(len(s)):
            if (map[ord(s[i])] != -1 and start <= map[ord(s[i])]):
                start = map[ord(s[i])] + 1
                length = i - start + 1
            elif (map[ord(s[i])] == -1):
                length += 1
            maxLength = max(length, maxLength)
            map[ord(s[i])] = i
        return maxLength
if __name__ == "__main__":
    ins = Solution()
    print(ins.lengthOfLongestSubstring("abcabcbb"))
