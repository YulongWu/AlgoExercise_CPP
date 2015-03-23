#include "stdafx.h"
#include "Structs.h"
class LinkedListCycle {
public:
	bool hasCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		if (!slow || !fast->next)
			return false;
		do{
			slow = slow->next;
			fast = fast->next->next;
		} while (slow != fast && fast->next);
		if (slow == fast)
			return true;
		return false;
	}
};