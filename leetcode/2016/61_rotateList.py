# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return head # error1: forgot this edge condition
        f = s = head
        i = 0
        while f.next:
            f = f.next
            i += 1
            if i < k and not f.next:
                f = head
                k %= i+1
                i = 0
            elif i > k:
                s = s.next
        if i >= k and s != f:
            f.next = head
            head = s.next
            s.next = None
        return head
