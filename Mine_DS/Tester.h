#include <string>
#include <iostream>
using namespace std;
template<class T>
class Tester {
public:
    static void SameCheck(T *p1, T * p2) {
        if(*p1 == *p2)
            cout << "Check pass!" << endl;
        else {
            cout << "Check fail!" << endl;
            cout << "p1: " << *p1 << endl;
            cout << "p2: " << *p2 << endl;
        }
    }
};
