'''
Worth to mention:
1. Defining vowels as dict makes the code run a bit faster than str. See line 8.
2. Add a stop early condition also makes it a bit faster. See line 16-17.
'''
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        vowels_max = 0
        vowels_cur = 0
        for i in range(len(s)):
            if s[i] in vowels:
                vowels_cur += 1
            if i >= k and s[i - k] in vowels:
                vowels_cur -= 1
            if vowels_cur == k:
                return k
            vowels_max = max(vowels_cur, vowels_max)
        return vowels_max