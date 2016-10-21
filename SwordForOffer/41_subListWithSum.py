import sys

def getSubWithSum(l, s):
    if not l or len(l) < 1 or s < 0:
        raise Exception("Illegal Input")
    b, e = 0, 0
    rSubs = []
    sum = l[0]
    while e < len(l):
        if sum == s:
            rSubs.append((b, e))
        if sum < s:
            e += 1
            if e < len(l): sum += l[e]
        else:
            if b == e:
                b = e = e + 1
                if b < len(l): sum = l[b]
            else:
                sum -= l[b]
                b += 1

    return rSubs

if __name__ == "__main__":
    assert getSubWithSum([2], 1) == []
    assert getSubWithSum([2], 2) == [(0,0)]
    assert getSubWithSum([2], 3) == []
    assert getSubWithSum([2,5,7], 7) == [(0,1), (2,2)]
    assert getSubWithSum([9,10], 1) == []
