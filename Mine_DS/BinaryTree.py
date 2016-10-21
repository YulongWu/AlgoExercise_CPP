import sys

class BTreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def preorder_traversal_recursive(root, res_list):
    if root:
        res_list.append(root.val)
        if root.left:   # Error1: forgot the indent
            Solution.preorder_traversal_recursive(root.left, res_list)
        if root.right:
            Solution.preorder_traversal_recursive(root.right, res_list)

def preorder_traversal_nonrecursive(root, res_list):
    stack = []
    p = root
    while p or len(stack) > 0:
        if p:
            res_list.append(p.val)
            stack.append(p)
            p = p.left
        else:
            p = stack.pop()
            p = p.right

# leetcode 98
def isValidBST(self, root):
    """
    :type root: TreeNode
    :rtype: bool
    """
    p = root
    stack = []
    prev = None
    while p or len(stack) > 0:
        if p:
            stack.append(p)
            p = p.left
        else:
            p = stack.pop()
            if prev == None or prev < p.val:
                prev = p.val
            else:
                return False
            p = p.right
    return True
