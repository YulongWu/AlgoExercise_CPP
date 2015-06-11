struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

ListNode *reverseList(ListNode *head) {
    if(!head)
        return head;
    ListNode *pPrev = NULL, *pCur = head, *pNext = NULL;
    while(pCur) {
        pNext = pCur->next;
        pCur -> next = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }
    return pPrev;
}

ListNode *reverseListRecursive(ListNode *head) {
    if(!head || !head -> next)
        return head;
    ListNode *pNext = head -> next, pCur = head;
    head = reverseListRecursive(pNext);
    pNext -> next = pCur;
    pCur -> next = NULL;
    return head;
}
