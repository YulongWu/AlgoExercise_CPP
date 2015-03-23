#include <iostream>
#include "common.h"
using namespace std;
LList<int> *CombineSortedLList(LList<int> *la, LList<int> *lb) {
    if(!la) return lb;
    if(!lb) return la;
    if(la->data <= lb->data) {
        la->next = CombineSortedLList(la->next, lb);
        return la;
    }
    else {
        lb->next = CombineSortedLList(la, lb->next);
        return lb;
    }
}

int main() {
    LList<int> *p1, *p2, *head1=new LList<int>(), *head2=new LList<int>();
    for(int i=0; i<3; ++i) {
        if(!i) {
            p1 = head1; p2 = head2;
            p1->data = 2*i;
            p2->data = 2*i+1;
        }
        else {
            p1->next = new LList<int>();
            p2->next = new LList<int>();
            p1 = p1->next;
            p2 = p2->next;
            p1->data = 2*i;
            p2->data = 2*i+1;
        }
    }
    p1->next = p2->next = NULL;
    cout << "head1: " << *head1 << endl;
    cout << "head2: " << *head2 << endl;
    cout << "combined: " << *CombineSortedLList(head1, head2) << endl;
}
