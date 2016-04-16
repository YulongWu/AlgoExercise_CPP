# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next or k < 2:
            return head
        k_head = p = in_tail = head
        iter_1st, out_tail = True, None
        while p:
            p_tail = p
            for i in range(k-1):
                p_tail = p_tail.next
                if not p_tail: p = p_tail; break
            else:
                p_guard = p_tail.next
                q = p.next
                while q != p_guard:
                    t = q.next
                    q.next = k_head
                    k_head = q
                    in_tail.next = t
                    q = t
                if iter_1st:
                    head = k_head
                    iter_1st = False
                if out_tail: out_tail.next = k_head
                out_tail = in_tail
                p = k_head = in_tail = p_guard
        return head
    def reverseKGroup2(self, head, k):
        '''
        a easier understanding code structure
        '''
        _head, _tail, iter_1st = head, None, True
        while _head:
            pre_tail = _tail
            _head, _tail = self.reverseK(_head, k)
            if pre_tail: pre_tail.next = _head
            if iter_1st:
                head = _head
                iter_1st = False
            _head = None if not _tail else _tail.next
        return head
    def reverseK(self, _head, k):
        _tail = _head
        k_head = _head
        for i in range(k-1):
            _tail = _tail.next
            if not _tail:
                return (_head, None)
        p_guard = _tail.next
        q = _head.next
        _tail = _head
        while q != p_guard:
            t = q.next
            q.next = _tail
            _tail = q
            _head.next = t
            q =t
        return (_tail, _head)
