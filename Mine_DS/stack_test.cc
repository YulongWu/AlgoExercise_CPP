#include <iostream>
#include "stack.cc"
using namespace std;
int main() {
    int test_num = 0;
    Stack<int> s;
    if(++test_num && !s.IsEmpty() && s.GetLength() != 0)
        goto fail;
    if(++test_num && !s.Push(1))
        goto fail;
    if(++test_num && s.Pop() != 1)
        goto fail;
    for(int i=0; i<32; ++i)
        s.Push(i);
    if(++test_num && s.GetTop() != 31)
        goto fail;
    if(++test_num && s.GetLength() != 32)
        goto fail;
    for(int i=0; i<32; ++i)
        if(s.Pop() != 31 - i)
            goto fail;
    if(++test_num && s.GetLength() != 0)
        goto fail;
    try {
        s.Pop();
    } catch(int) {
        goto success;
    }
fail:
    cout << "test " << test_num << " failed." << endl;
    cout << "Pop: " << s.GetTop();
    return 1;
success:
    cout << "congratulation, all tests passed.";
    //cin.get();
    return 0;
}
