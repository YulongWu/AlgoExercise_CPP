#include "Tester.h"
#include "LinkedList.h"

template<class T>
int LinkedList<T>::GetLength() {
    int length=0;
    LinkedNode<T> *p=head;
    while(p) {
        p = p->next;
        ++length;
    }
    return length;
}

template<class T>
void LinkedList<T>::PushBack(const T value) {
    LinkedNode<T> *node = new LinkedNode<T>;
    node->value = value;
    node->next = NULL;
    if(!head) {
        head = node;
    }
    else {
        LinkedNode<T> *tail = head;
        while(tail->next) 
            tail = tail->next;
        LinkedNode<T> *to_add = new LinkedNode<T>;
        *to_add = *node;
        tail->next = to_add;
    }
}

template<class T>
LinkedNode<T> LinkedList<T>::PopFront() {
    if(!head)
        throw -1;
    LinkedNode<T> *to_delete = head;
    head = head->next;
    return *to_delete;
}

template<class T>
int LinkedList<T>::Insert(const int index, const T value) {
    if(!head || index < 0)
        return -1;
    LinkedNode<T> *node = new LinkedNode<T>;
    node->value = value;
    LinkedNode<T> *prev=head;
    if(index == 0) {
        prev = new LinkedNode<T>;
        *prev = *node;
        prev->next = head;
        head = prev;
    }
    else {
        int position=0;
        while(prev && position < index-1) {
            prev = prev->next;
            ++position;
        }
        if(position < index-1)
            return -1;
        LinkedNode<T> *to_add = new LinkedNode<T>;
        *to_add = *node;
        to_add->next = prev->next;
        prev->next = to_add;
    }
    return index;
}

template<class T>
int LinkedList<T>::Remove(const int index) {
    if(index < 0 || index >= GetLength())
        return -1;
    LinkedNode<T> *prev = head;
    if(index == 0) {
        head = head->next;
        delete prev;
    }
    else {
        int position = 0;
        while(prev && position < index-1) {
            prev = prev->next;
            ++position;
        }
        LinkedNode<T> *to_delete = prev->next;
        prev->next = prev->next->next;
        delete to_delete;
    }
    return index; 
}

template<class T>
string LinkedList<T>::ToString() {
    string output = "";
    LinkedNode<T> *p = head;
    while(p) {
        output += (output.empty()?"":", ") + to_string(p->value);
        p = p->next;
    }
    return output;
}

int main() {
    LinkedList<int> list;
    //extreme test
    int check_num = 0;
    try {
    LinkedNode<int> result = list.PopFront();
    } catch(int) {
        cout << "Check 1 pass!" << endl;
        check_num = 1;
    }
    if(!check_num)
        goto fail;
    if(check_num++ && list.Insert(1, 1) == -1)
        cout << "Check 2 pass!" << endl;
    else 
        goto fail;
    if(check_num++ && list.Remove(1) == -1)
        cout << "Check 3 pass!" << endl;
    else 
        goto fail;
    if(check_num++ && list.ToString() == "")
        cout << "Check 4 pass!" << endl;
    else
        goto fail;
    list.PushBack(1); 
    list.PushBack(2);
    list.PushBack(3);
    if(check_num++ && list.ToString() == "1, 2, 3")
        cout << "Check 5 pass!" << endl;
    else
        goto fail;
    if(check_num++ && list.Remove(5) != -1)
        goto fail;
    check_num = 10;
    if(list.Remove(1) != 1 || list.ToString() != "1, 3")
        goto fail;
    check_num = 11;
    if(list.Insert(0, 0) != 0 || list.ToString() != "0, 1, 3")
        goto fail;
    check_num = 12;
    list.Insert(2,2);
    list.PushBack(4);
    if(list.GetLength() != 5 || list.ToString() != "0, 1, 2, 3, 4")
        goto fail;
    check_num = 13;
    list.PopFront();
    list.PopFront();
    if(list.PopFront().value != 2 || list.GetLength() != 2)
        goto fail;
    cout << "Contratulation! All tests passed!" << endl;
    goto final;
fail:
    cout << "Check " << check_num << " failed!" << endl <<"list output: " << list.ToString() <<endl;
final:
    cin.get();
}
