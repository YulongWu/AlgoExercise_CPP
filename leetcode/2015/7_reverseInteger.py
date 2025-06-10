'''
The following points are worth noting:

1. Overflow check, or say illegal input check after the reverse. It's easy to remember the check before the conversion,
but hard to keep the check after the conversion in mind.

2. Several Python grammar sugars worth noting:
    * Exponentiation in Python is not ^, but **. ^ in Python means XOR.
    * Integer division in Python is //, not /. / is float division in Python 3.
'''
class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        # illegal input handling
        if self.is_overflow(x):
            return 0
        # negative handling
        if (x < 0):
            res = 0 - self.reverse_positive(0-x)
        else:
            res = self.reverse_positive(x)
        return 0 if self.is_overflow(res) else res

    def is_overflow(self, x: int) -> int:
        if (x < -2 ** 31 - 1 or x > 2 ** 31 - 1):
            return True

    def reverse_positive(self, x: int) -> int:
        r = 0
        while x > 0:
            r = r * 10 + x % 10
            x //= 10
        return r