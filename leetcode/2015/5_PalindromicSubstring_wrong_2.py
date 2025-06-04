'''
This solution is logically correct, while Leetcode returns me "Time Limit Exceeded" error on the following long input.
The reason is that I didn't prune the scope.
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
                if start + Solution.memory[start + 1][end - 1] + 1 == end:
                    Solution.memory[start][end] = Solution.memory[start + 1][end - 1] + 2
        if start < end:
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
    print(solution.longestPalindrome("thelviymgkeddreyviespjsyqwmbmnlwzjhdokfzrczvreiagayofwvhecskjqlqzodtozvzozqyiwfsjyrinrmgfyhplybonzuvmxxyihmggwiuccplqjtgschmieoexvtewbsjqzkzapfxpzhgjtbmlchevohmxnbattphvobptnhmcoihcaimchurqpucxapojgszpopdvsfahwidiyxlpjfhdkcoewzvlmaebudtovnvcuadykhhmwfpilqfdvnseiitokcbuxmhwukrdxwvtgztczrwcsydqwosnktronibiplbljrcpinqorbhxrwjonnqeniebrksjkcmbvjnuwdedoenqmrcxayqbzmlpbubnfnkkqnuljtchaeijcmfpyuxkgfssoqliqmhowtbmcvzkqbanxhowjjejexxlihwwhilxxejejjwohxnabqkzvcmbtwohmqilqossfgkxuypfmcjieahctjlunqkknfnbubplmzbqyaxcrmqneodedwunjvbmckjskrbeineqnnojwrxhbroqnipcrjlblpibinortknsowqdyscwrzctzgtvwxdrkuwhmxubckotiiesnvdfqlipfwmhhkydaucvnvotdubeamlvzweockdhfjplxyidiwhafsvdpopzsgjopaxcupqruhcmiachiocmhntpbovhpttabnxmhovehclmbtjghzpxfpazkzqjsbwetvxeoeimhcsgtjqlpccuiwggmhiyxxmvuznobylphyfgmrniryjsfwiyqzozvzotdozqlqjkscehvwfoyagaiervzcrzfkodhjzwlnmbmwqysjpseivyerddekgmyivleht"))
