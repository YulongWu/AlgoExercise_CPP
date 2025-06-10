'''
Points worth to mention from this question:
1. Python does not support C style for loop. See commented line 30.
2. I mistakenly reduced the length of pattern to 1 when len(str1) is odd, which is wrong in following case. See commented
lines 24 - 27.
str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX"
str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
'''
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if (len(str1) == len(str2)):
            if (str1 == str2):
                return str1
            else:
                return ''
        else:
            if (len(str1) > len(str2)):
                str1, str2 = str2, str1
            s, l = 0, len(str1)
            while (l > 0):
                if (len(str1) % l == 0 and len(str2) % l == 0):
                    pattern = str1[s : s + l]
                    if (Solution.can_divide(pattern, str1) and Solution.can_divide(pattern, str2)):
                        return pattern
                l = l // 2 if l == len(str1) else l - 1
                # if (l == len(str1)):
                #     l = l // 2 if l % 2 == 0 else 1
                # else:
                #     l -= 1
            return ''

    @staticmethod
    def can_divide(divider: str, divident: str) -> bool:
        # for (i=0; i + len(divider) < len(divident); i += len(divider)):
        for i in range(0, len(divident) - len(divider) + 1, len(divider)):
            if (divider != divident[i: i + len(divider)]):
                return False
        return True
