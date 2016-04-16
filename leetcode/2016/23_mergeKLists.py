import sys
from heapq import *

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        p = []
        dummy = pre = ListNode(0)
        for head in lists:
            if head: heappush(p, (head.val, head))
        while len(p) > 0:
            pre.next = heappop(p)[1]
            pre = pre.next
            if pre.next:
                heappush(p, (pre.next.val, pre.next))
        return dummy.next
