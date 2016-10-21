import sys

def binary_search(l, b, e, c):
    if not l or b > e:
        return -1
    low, high = b, e
    while low <= high:
        mid = low + (high - low)/2
        if l[mid] < c:
            low = mid + 1
        else:
            high = mid - 1
    if l[high] == c:
        return high
    return -1

if __name__ == "__main__":
    s = "23444567"
    print binary_search(s, 0, len(s)-1, '4')
