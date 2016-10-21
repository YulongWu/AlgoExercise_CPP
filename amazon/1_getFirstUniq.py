import sys

def getFirstUniq(l):
    if not l or len(l) < 1:
        return None
    dic = {}
    for item in l:
        if item not in dic:
            dic[item] = 1
        else:
            dic[item] += 1
    for item in l:
        if dic[item] == 1:
            return item
    return None

if __name__ == "__main__":
    assert getFirstUniq([1]) == 1
    assert getFirstUniq([1,2]) == 1
    assert getFirstUniq([1,2,1]) == 2
    assert getFirstUniq([1,2,1,2]) == None
