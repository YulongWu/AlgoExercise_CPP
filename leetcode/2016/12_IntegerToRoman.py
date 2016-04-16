import sys
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        :runtime: 136ms
        """
        masks = [1000, 100, 10, 1]
        A = ['M', 'C', 'X', 'I']
        B = ['-', 'D', 'L', 'V']
        res = ''
        for i in range(4):
            if num >= masks[i]:
                t = num / masks[i] % 10
                if t == 4:
                    res += A[i] + B[i]
                    continue
                elif t == 9:
                    res += A[i] + A[i-1]
                    continue
                elif t >= 5:
                    res += B[i]
                    t -= 5
                res += t*A[i]
        return res
    def intToRoman2(self, num):
        """
        :a faster solution: 96ms
        """
        M = ["", "M", "MM", "MMM"];
        C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
        X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
        I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10]

if __name__ == '__main__':
    ins = Solution()
    print ins.intToRoman(int(sys.argv[1]))
    print ins.intToRoman2(int(sys.argv[1]))
