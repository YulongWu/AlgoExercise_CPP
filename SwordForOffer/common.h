#pragma once
#include <string>
using namespace std;
template <typename T>
class LList {
    public:
        T data;
        LList *next;
};
template <typename T>
inline ostream & operator<<(ostream &out, LList<T> &obj) {
    out << obj.data << ", ";
    LList<T> *p = obj.next;
    while(p) {
        out << p->data << ", ";
        p = p->next;
    }   
    out << endl;
    return out;
}
