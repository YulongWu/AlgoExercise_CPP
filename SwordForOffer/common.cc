#include "common.h"
template <typename T>
ostream & LList<T>::operator<<(ostream &out, LList<T> &obj) {
    out << obj.data << ", ";
    LList *p = next;
    while(p) {
        out << p->data << ", ";
        p = p->next;
    }
    out << endl;
    return out;
}
