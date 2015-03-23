#pragma once
#include <vector>
using namespace std;
template<class T>
class Stack {
private:
    unsigned int current_size_;
    T *buffer_, *top_;
public:
    Stack();
    ~Stack();
    bool IsEmpty();
    int GetLength();
    bool Push(T value);
    T Pop();
    T GetTop();
};
