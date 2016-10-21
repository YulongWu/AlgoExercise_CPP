import sys

def pow_(x, a):
    if x == 0:
        if a < 0:
            raise Exception("Illegal Exception")
        else:
            return 0
    if a == 0:
        return 1
    if a < 0:
        return 1.0 / pow_(x, -a)
    if x < 0 and a & 1 != 0:
        return -pow_(-x, a)
    x = abs(x)

    if a == 1:
        return x
    r = pow_(x, a/2) * pow_(x, a/2)
    if a & 1 != 0:
        r *= x
    return r

if __name__ == "__main__":
    assert pow_(0, 3) == 0
    assert pow_(-2, 3) == -8
    assert pow_(-2, 2) == 4
    assert pow_(2, -3) == 1./8
    assert pow_(2, 3) == 8
    assert pow_(-2, -2) == 1./4

    # assert pow_(0, -2)
