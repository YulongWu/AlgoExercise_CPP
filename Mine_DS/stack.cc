#include "stack.h"
#define MIN_SIZE 4
template<class T>
Stack<T>::Stack() {
    current_size_ = MIN_SIZE;
    buffer_ = new T[MIN_SIZE];
    top_ = buffer_;
}
template<class T>
Stack<T>::~Stack() {
    delete buffer_;
}
template<class T>
int Stack<T>::GetLength() {
    return top_ - buffer_;
}
template<class T>
bool Stack<T>::IsEmpty() {
    return 0 == GetLength();
}

template<class T>
bool Stack<T>::Push(T value) {
    if(GetLength() >= current_size_-1) {     //alloc new space
        T *temp = buffer_;
        buffer_ = new T[current_size_*2];
        for(int i=0; i < current_size_-1; ++i) {
            buffer_[i] = temp[i];
        }
        top_ = buffer_ + current_size_ -1;
        current_size_ *= 2;
        delete temp;
    }
    *top_ = value;
    ++top_;
    return true;
}

template<class T>
T Stack<T>::Pop() {
    if(IsEmpty())
        throw -1;
    T result = *(--top_);
    return result;
}

template<class T>
T Stack<T>::GetTop() {
    if(IsEmpty())
        throw -1;
    return *(top_-1);
}
