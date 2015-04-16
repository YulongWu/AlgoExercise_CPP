#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0), *prev = head;
    int carry=0, v1, v2;
    while(l1 || l2 || carry) {
        v1 = v2 = 0;
        if(l1) {
            v1 = l1->val;
            l1 = l1->next;
        }
        if(l2) {
            v2 = l2->val;
            l2 = l2->next;
        }
        int sum = carry + v1 + v2;
        prev->next = new ListNode(sum % 10);
        carry = sum / 10;
        prev = prev->next;
    }
    return head->next;
}
/*
 * Following function is same as the above one on method but with more precise code and same performance
*/
ListNode *addTwoNumbers_M2(ListNode *l1, ListNode *l2) {
    ListNode head(0), *prev = &head;  //error: improvement: this is better than ListNode *head = new ListNode(0)
    int carry = 0;
    while(l1 || l2 || carry) {
        int sum = l1 ? l1->val : 0 + l2 ? l2->val : 0 + carry;
        prev->next = new ListNode(sum % 10);
        prev = prev->next;
        carry = sum / 10;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return head.next;
}

void printList(ListNode *head) {
    while(head) {
        cout << head->val << ", ";
        head = head -> next;
    }
    cout << endl;
}
ListNode* buildList(int l[], int len) {
    ListNode *head = new ListNode(0), *prev = head;
    for(int i=0; i < len; ++i) {
        prev->next = new ListNode(l[i]);
        prev = prev->next;
    }
    return head->next;
}
int main() {
    int l1_i[] = {2, 4, 3}, l2_i[] = {5, 6, 4, 1};
    ListNode *l1 = buildList(l1_i, 3), *l2 = buildList(l2_i, 4);
    printList(addTwoNumbers_M2(l1, l2));
}
