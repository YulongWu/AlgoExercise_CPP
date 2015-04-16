# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        carry = 0
        head = node = ListNode(0)
        while l1 or l2 or carry:
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(carry + v1 + v2, 10)
            node.next = ListNode(val);
            node = node.next
        return head.next;

def build_listnode(list):
    prev = head = ListNode(0)
    for v in list:
        prev.next = ListNode(v)
        prev = prev.next
    return head.next
def print_list(list):
    node = list;
    while node:
        print "{0}, ".format(node.val),
        node = node.next
    print '\n'

if __name__ == "__main__":
    list = [2, 4, 3]
    l1 = build_listnode(list)
    list = [5,6,4, 1]
    l2 = build_listnode(list)
    ins = Solution()
    res = ins.addTwoNumbers(l1, l2)
    print_list(res)
