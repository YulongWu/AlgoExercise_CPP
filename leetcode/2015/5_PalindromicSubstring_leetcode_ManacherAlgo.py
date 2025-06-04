'''
This is a solution with O(n) time complexity. (Wow) It's called Manacher's algorithm.

It's is briefly mentioned in [Leetcode](https://leetcode.com/problems/longest-palindromic-substring/solutions/3598120/longest-palindromic-substring/)
Then I searched [Wikipedia](https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm)
And following paragraph from Wikipedia has explained the core of this algorithm.
For example, consider the input string "abacaba". By the time it gets to the "c", Manacher's algorithm will have
identified the length of every palindrome centered on the letters before the "c". At the "c", it runs a loop to identify
the largest palindrome centered on the "c": "abacaba". With that knowledge, everything after the "c" looks like the
reflection of everything before the "c". The "a" after the "c" has the same longest palindrome as the "a" before the
"c". Similarly, the "b" after the "c" has a longest palindrome that is at least the length of the longest palindrome
centered on the "b" before the "c".
'''
class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_prime = "#" + "#".join(s) + "#"
        n = len(s_prime)
        palindrome_radii = [0] * n
        center = radius = 0

        for i in range(n):
            mirror = 2 * center - i

            if i < radius:
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror])

            while (
                    i + 1 + palindrome_radii[i] < n
                    and i - 1 - palindrome_radii[i] >= 0
                    and s_prime[i + 1 + palindrome_radii[i]]
                    == s_prime[i - 1 - palindrome_radii[i]]
            ):
                palindrome_radii[i] += 1

            if i + palindrome_radii[i] > radius:
                center = i
                radius = i + palindrome_radii[i]

        max_length = max(palindrome_radii)
        center_index = palindrome_radii.index(max_length)
        start_index = (center_index - max_length) // 2
        longest_palindrome = s[start_index : start_index + max_length]

        return longest_palindrome

if __name__ == '__main__':
    solution = Solution()
    # print(solution.longestPalindrome("aacabdkacaa"))
    # print(solution.longestPalindrome("acabdaca"))
    # print(solution.longestPalindrome("cbbd"))
    # print(solution.longestPalindrome("thelviymgkeddreyviespjsyqwmbmnlwzjhdokfzrczvreiagayofwvhecskjqlqzodtozvzozqyiwfsjyrinrmgfyhplybonzuvmxxyihmggwiuccplqjtgschmieoexvtewbsjqzkzapfxpzhgjtbmlchevohmxnbattphvobptnhmcoihcaimchurqpucxapojgszpopdvsfahwidiyxlpjfhdkcoewzvlmaebudtovnvcuadykhhmwfpilqfdvnseiitokcbuxmhwukrdxwvtgztczrwcsydqwosnktronibiplbljrcpinqorbhxrwjonnqeniebrksjkcmbvjnuwdedoenqmrcxayqbzmlpbubnfnkkqnuljtchaeijcmfpyuxkgfssoqliqmhowtbmcvzkqbanxhowjjejexxlihwwhilxxejejjwohxnabqkzvcmbtwohmqilqossfgkxuypfmcjieahctjlunqkknfnbubplmzbqyaxcrmqneodedwunjvbmckjskrbeineqnnojwrxhbroqnipcrjlblpibinortknsowqdyscwrzctzgtvwxdrkuwhmxubckotiiesnvdfqlipfwmhhkydaucvnvotdubeamlvzweockdhfjplxyidiwhafsvdpopzsgjopaxcupqruhcmiachiocmhntpbovhpttabnxmhovehclmbtjghzpxfpazkzqjsbwetvxeoeimhcsgtjqlpccuiwggmhiyxxmvuznobylphyfgmrniryjsfwiyqzozvzotdozqlqjkscehvwfoyagaiervzcrzfkodhjzwlnmbmwqysjpseivyerddekgmyivleht"))
    print(solution.longestPalindrome("babad"))