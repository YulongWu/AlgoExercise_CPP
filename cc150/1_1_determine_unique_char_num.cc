#include <iostream>
#include <string>
using namespace std;
#define ERROR -1
int CountBit1InBinary(int mask) {
    int res = 0;
    while(mask) {
        ++res;
        mask &= mask - 1;
    }
    return res;
}
int CountUniqueCharInStr(string s) {
    int mask = 0;
    for(int i=0; i < s.length(); ++i) {
        char c = s[i];
        if(c < 'A' || c > 'z' ) {
            cout << "illegal c=" << c << endl;  //for debug
            throw ERROR;
        }
        if(c > 'z')
            c -= 26;
        mask |= 1 << (c-'a');
    }
    return CountBit1InBinary(mask);
}

int main() {
    string s = "abcccdefhhgijklmnopqrstuvwxyzz";
    cout << "number of unique char is " << CountUniqueCharInStr(s) << endl;
}
