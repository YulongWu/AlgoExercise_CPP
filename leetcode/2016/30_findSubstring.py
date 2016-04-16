'''
this solution is correct, but time exceeded. because I missed a limit condition in question which will decrease the difficulty too much.
For the new solution, pls see 30_findSubstring2.py
'''
class BTreeNode(object):
    def __init__(self, data):
        self.childs = []
        self.data = data
    def insert(self, node):
        self.childs.append(node)
    def lookup(self, data):
        for child in self.childs:
            if child.data == data:
                return child
        else:
            return None
    def getNextLeaf(self, i):
        for child in self.childs:
            if isinstance(child.data, int) and child.data > i:
                return child
        else:
            return None

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        total_words_len = 0
        #build the tree
        root = BTreeNode('root')
        for i_word, word in enumerate(words):
            p = root
            for i, c in enumerate(word):
                if p.lookup(c) == None:
                    pre = p
                    p = BTreeNode(c)
                    pre.insert(p)
                else:
                    p = p.lookup(c)
            p.insert(BTreeNode(i_word))

            total_words_len += len(word)

        res = []
        i = 0
        while i < len(s):
            flags = [1]*len(words)
            if self._findSubstring(s[i:], root, flags):
                res.append(i)
                i += total_words_len
            else:
                i += 1
        return res
    def _findSubstring(self, s, root, flags):
        # print "Enter: s:{0}\tflags:{1}".format(s, flags)
        if len(flags) > 0:
            sum = 0
            for flag in flags:
                sum += flag
            if sum == 0:
                return True
        if not s or not root or len(s) == 0:
            return False
        i = 0
        p = root
        while i < len(s):
            # print "Traversed: " + s[0:i]
            if p.lookup(s[i]) == None:
                return False
            else:
                p = p.lookup(s[i])
                k = 0
                while flags[k] ==0:
                    k += 1
                q = p.getNextLeaf(k-1)
                while q and flags[q.data] == 0:
                    k = q.data
                    q = p.getNextLeaf(k)
                if q != None:
                    flags[q.data] = 0
                    if self._findSubstring(s[i+1:], root, flags):
                        return True
                    else:
                        flags[q.data] = 1
            i += 1
        else:
            return False

if __name__ == "__main__":
    ins = Solution()
    # print ins.findSubstring("aaaaaa", ["a", "a", "a", "a", "a"])
    print ins.findSubstring("barfoothefoobarman", ["foo", "bar"])
