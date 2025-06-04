'''
Finally, after half day of work, I finally get the Leetcode passed solution.
From my initial solution, following improvements have been made:
1. Introduced memorization.
2. Pruned the traversing branches by line 29: ```and Solution.memory[start][end] < end - start + 1```
'''
class Solution:
    memory = []
    palindromeStart, palindromeLength = 0,0

    def longestPalindrome(self, s: str) -> str:
        Solution.memory = [[0 for _ in range(len(s))] for _ in range(len(s))]
        Solution.palindromeStart, Solution.palindromeLength = 0,0
        self.palindromeRecursive(s, 0, len(s) - 1)
        return s[Solution.palindromeStart : Solution.palindromeStart + Solution.palindromeLength]

    def palindromeRecursive(self, s: str, start: int, end: int):
        if Solution.memory[start][end] != 0:
            return
        elif start == end:
            Solution.memory[start][end] = 1
        elif s[start] == s[end]:
            if start + 1 == end:
                Solution.memory[start][end] = 2
            else:
                self.palindromeRecursive(s, start + 1, end - 1)
                if Solution.memory[start + 1][end - 1] == end - start - 1:
                    Solution.memory[start][end] = end - start + 1
        if start < end and Solution.memory[start][end] < end - start + 1:
            self.palindromeRecursive(s, start + 1, end)
            self.palindromeRecursive(s, start, end - 1)
            innerMaxLength = max(Solution.memory[start + 1][end], Solution.memory[start][end - 1])
            Solution.memory[start][end] = max(innerMaxLength, Solution.memory[start][end])
        if (Solution.palindromeLength < Solution.memory[start][end]):
            Solution.palindromeStart, Solution.palindromeLength = start, Solution.memory[start][end]

if __name__ == '__main__':
    solution = Solution()
    # print(solution.longestPalindrome("aacabdkacaa"))
    # print(solution.longestPalindrome("acabdaca"))
    # print(solution.longestPalindrome("cbbd"))
    # print(solution.longestPalindrome("thelviymgkeddreyviespjsyqwmbmnlwzjhdokfzrczvreiagayofwvhecskjqlqzodtozvzozqyiwfsjyrinrmgfyhplybonzuvmxxyihmggwiuccplqjtgschmieoexvtewbsjqzkzapfxpzhgjtbmlchevohmxnbattphvobptnhmcoihcaimchurqpucxapojgszpopdvsfahwidiyxlpjfhdkcoewzvlmaebudtovnvcuadykhhmwfpilqfdvnseiitokcbuxmhwukrdxwvtgztczrwcsydqwosnktronibiplbljrcpinqorbhxrwjonnqeniebrksjkcmbvjnuwdedoenqmrcxayqbzmlpbubnfnkkqnuljtchaeijcmfpyuxkgfssoqliqmhowtbmcvzkqbanxhowjjejexxlihwwhilxxejejjwohxnabqkzvcmbtwohmqilqossfgkxuypfmcjieahctjlunqkknfnbubplmzbqyaxcrmqneodedwunjvbmckjskrbeineqnnojwrxhbroqnipcrjlblpibinortknsowqdyscwrzctzgtvwxdrkuwhmxubckotiiesnvdfqlipfwmhhkydaucvnvotdubeamlvzweockdhfjplxyidiwhafsvdpopzsgjopaxcupqruhcmiachiocmhntpbovhpttabnxmhovehclmbtjghzpxfpazkzqjsbwetvxeoeimhcsgtjqlpccuiwggmhiyxxmvuznobylphyfgmrniryjsfwiyqzozvzotdozqlqjkscehvwfoyagaiervzcrzfkodhjzwlnmbmwqysjpseivyerddekgmyivleht"))
    print(solution.longestPalindrome("babad"))
