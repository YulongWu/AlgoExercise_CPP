import sys

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        pre = p = j = head
        for t in range(n-1):
            p = p.next
        while p.next:
            pre = j
            j = j.next
            p = p.next
        if pre == j:
            if pre == p:
                return None
            else:
                head = pre.next
                return head
        else:
            pre.next = j.next
            return head
    def removeNthFromEnd2(self, head, n):
        """
        an improved logic
        """
        p = j = head
        for _ in range(n):
            p = p.next
        if not p:
            return head.next
        while p.next:
            j = j.next
            p = p.next
        j.next = j.next.next
        return head
