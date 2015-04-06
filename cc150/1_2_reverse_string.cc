#include <iostream>
using namespace std;

void reverse(char *str) {
    if(!str)
        return;
    int length = 0;
    char *p = str;
    while(*(p++)) 
        ++length;
    char *low = str, *high = str + length - 1;  //error 1: forget to add "- 1" in the assignment of high.
    while(low < high) {
        *low ^= *high;  //notice 1: we can also do bit operations on char type.
        *high ^= *low;
        *low ^= *high;
        ++low; --high;  //error 2: forget to update pointers in the loop.
    }
}

int main() {
    char *str = "hello, world.";
    char buff[1024];  //error 3: if you just modify the referenced content of str, you will get error: "Bus error: 10", due to the constant property of the content.
    strcpy(buff, str);
    reverse(buff);
    cout << buff << endl;
}
