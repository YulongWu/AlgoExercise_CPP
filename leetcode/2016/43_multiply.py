class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        res = [0]*(len(num1)+len(num2))
        pos = len(res)-1
        for n1 in reversed(num1):
            temp_pos = pos
            for n2 in reversed(num2):
                r = int(n1) * int(n2)
                res[temp_pos] += r
                res[temp_pos-1] += res[temp_pos] / 10
                res[temp_pos] %= 10
                temp_pos -= 1
            pos -= 1
        i = 0
        while i < len(res)-1 and res[i] == 0:
            i += 1
        return ''.join(map(str, res[i:]))

if __name__ == "__main__":
    ins = Solution()
    s1="9916221379759361611351233372784697220579564491782019354602972"
    s2="342784353038641"
    print ins.multiply(s1, s2)
