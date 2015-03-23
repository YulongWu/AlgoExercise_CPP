#pragma once
#include <string>
using namespace std;
template<class T>
struct LinkedNode {
    T value;
    struct LinkedNode *next;
};
template<class T>
class LinkedList {
private:
    LinkedNode<T> *head;
public:
    int GetLength();
    void PushBack(const T value);
    LinkedNode<T> PopFront();
    int Insert(const int index, const T value);
    int Remove(const int index);
    string ToString();
};
