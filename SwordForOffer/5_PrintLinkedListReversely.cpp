#include <iostream>
#include <stack>
#include <string>
#include "LinkedList.hpp"
using namespace std;

string printLinkedListReversely(LinkedNode<int> *head) {
    if(head == NULL) return "";
    string output; 
    stack<LinkedNode<int>*> stack;
    for(LinkedNode<int> *p = head; p != NULL; p = p->next) {
        stack.push(p);
    }
    for(LinkedNode<int> *p;!stack.empty(); stack.pop()) {
        p = stack.top();
        output = output + to_string(p->data); 
    }
    return output;
}

int main() {
    LinkedNode<int> *p = new LinkedNode<int>[5];
    for(int i=0; i<5; ++i) {
        p[i].data = i;
        p[i].next = NULL;
        if(i>0) p[i-1].next = p+i;
    }
    cout << printLinkedListReversely(p) << endl;
}
