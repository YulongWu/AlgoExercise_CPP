import sys
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if divisor == 0 or dividend == sys.maxint and divisor == -1:
            return sys.maxint
        neg = (dividend>0) != (divisor>0)
        dividend, divisor = abs(dividend), abs(divisor)
        return divide_pos(dividend, divisor) if not neg else -divide_pos(dividend, divisor)
    def divide_pos(self, dividend, divisor):
        if dividend < divisor:
            return 0
        pre_multi, multi = 0, 1
        pre_divisor, orig_divisor = 0, divisor
        while dividend > divisor:
            pre_multi = multi
            pre_divisor = divisor
            divisor += divisor
            multi += multi
        return pre_multi + self.divide_pos(dividend - pre_divisor, orig_divisor)
