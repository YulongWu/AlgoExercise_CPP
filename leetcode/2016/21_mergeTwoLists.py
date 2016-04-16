# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p1, p2 = l1, l2
        head = pre = ListNode(0)
        while p1 and p2:
            if p1.val <= p2.val:
                pre.next = p1
                # pre = p1
                p1 = p1.next
            else:
                pre.next = p2
                # pre = p2
                p2 = p2.next
            pre = pre.next # a more concise expression
        # if p1:
            # pre.next = p1
        # elif p2:
            # pre.next = p2
        pre.next = p1 or p2 # a more concise expression
        return head.next
    def mergeTwoLists2(self, l1, l2):
        '''
        recursively way
        '''
        if not l1 or not l2:
            return l1 or l2
        if l1.val <= l2.val:
            l1.next = self.mergeTwoLists2(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists2(l1, l2.next)
            return l2

if __name__ == '__main__':
    ins = Solution()
    print ins.mergeTwoLists2([], [])
