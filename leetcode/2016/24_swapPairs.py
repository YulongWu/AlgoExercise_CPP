import sys

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def swapPair(pre, head):
            if not head.next: return head
            if pre: pre.next = head.next
            temp = head.next.next
            head.next.next = head
            head.next = temp
            return head

        if head: res = head.next if head.next else head
        else: return None
        pre = swapPair(None, head)
        while pre.next:
            pre = swapPair(pre, pre.next)
        return res

if __name__ == '__main__':
    ins = Solution()
    n1, n2, n3, n4 = ListNode(1), ListNode(2), ListNode(3), ListNode(4)
    n1.next = n2; n2.next = n3; n3.next = n4; n4.next = None
    p = ins.swapPairs(n1)
    while p:
        print p.val
        p = p.next
