import sys

def get_next(pattern):
    if not pattern or len(pattern) < 1:
        return None
    next_ = [0]*len(pattern)
    i, j = 0, 0
    while i < len(pattern) - 1:
        if j == 0 or pattern[i] == pattern[j]:
            if i != j and pattern[i] == pattern[j]:
                j += 1
            i += 1
            next_[i] = j
        else:
            j = next_[j]
    return next_

def KMP(s, p):
    if not s or not p or len(p) > len(s):
        return -1
    next_ = get_next(p)
    i, j = 0, 0
    while i < len(s) and j < len(p):
        if s[i] == p[j]:
            i += 1; j += 1
        elif j > 0:
            j = next_[j]
        else:
            i += 1
    if j == len(p):
        return i - j
    return -1

if __name__ == "__main__":
    s, p = "ababcabaabcab", "abaabc"
    next_ = get_next(p)
    print next_
    print KMP(s, p)
