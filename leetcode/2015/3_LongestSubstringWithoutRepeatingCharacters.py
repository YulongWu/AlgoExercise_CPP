def lengthOfLongestSubstring(s):
    map = [ -1 for i in range(256)]
    start, longest = 0, 0
    for i in range(len(s)):
#        start = start  > map[s[i]] + 1 ? start : map[s[i]] + 1
        start = start if start > map[ord(s[i])] + 1 else map[ord(s[i])] + 1  #this is ternary conditional operator in Python
        longest = max(longest, i - start + 1);
        map[ord(s[i])] = i #remember the function of ord
    return longest
if __name__ == "__main__":
    print lengthOfLongestSubstring("abcabcbb")
