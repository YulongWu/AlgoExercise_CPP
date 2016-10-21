import sys

def getLongestCompWord(l):
    if not l or len(l) < 1:
        return None
    s = set()
    for i in l:
        s.add(i)
    max = 0
    for t in l:
        cur = checkSplit(t, s, True)
        if max < cur:
            max = cur
        for i in range(len(t)-1):
            if t[:i+1] in s and t[i+1:] in s:
                if max < len(t):
                    max = len(t)
    return max

def checkSplit(t, s, f):
    if not t or len(t) < 0:
        return 0
    if not f and t in s:
        return len(t)
    max = 0
    for i in range(len(t)-1):
        m = checkSplit(t[i+1:], s, False)
        if t[:i+1] in s and m > 0:
            if max < len(t):
                max = len(t)
    return max

if __name__ == "__main__":
    assert getLongestCompWord(['a']) == 0
    assert getLongestCompWord(['a','b']) == 0
    assert getLongestCompWord(['a','b', 'ab']) == 2
    assert getLongestCompWord(['a','b', 'abc']) == 0
    assert getLongestCompWord(['a','b', 'ba']) == 2
    assert getLongestCompWord(['a','b', 'bd']) == 0
    assert getLongestCompWord(['a','b', 'c', 'abc', 'ab']) == 3
