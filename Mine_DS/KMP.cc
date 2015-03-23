#define OUTPUT(ins, s, p) cout << "Match index on \"" << s << "\" with \"" << p << "\" is " << ins.KMPMatch(s, p) << endl;
#include <iostream>
#include "KMP.h"

int KMP::KMPMatch(const string s, const string pattern) {
    GetNext(pattern);
    if(s.length() == 0)
        throw -1;      //error
        int i=0, j=0;
        while(i<s.length() && j<pattern.length()) {
            if(s[i] == pattern[j]) {
                ++i; ++j;
            }
            else {
                if(j == 0)
                    ++i;
                j = next_[j];
            }
        }
        if(j == pattern.length())
            return i - j;
    return -1;
}

void KMP::GetNext(const  string pattern) {
    if(next_)
        delete next_;
    next_ = new int[pattern.length()];
    int p_index=0, next_value=0;
    for(int next_index=0; next_index<pattern.length(); ++next_index) {
        if(next_index < 2) {
            ;
        }
        else if(pattern[p_index] == pattern[next_index-1]) {
            ++next_value;
            ++p_index;
        }
        else {
            while(pattern[next_index-1] != pattern[p_index] && p_index != 0)
                p_index = pattern[p_index];
            if(p_index == 0) {
                next_value = 0;
            }
            else {
                next_value = pattern[p_index] + 1;
            }
        }
        next_[next_index] = next_value;
    }
}

int main() {
    string s = "ababcabcacbab", p1 = "abcad", p2 = "abcac";
    KMP instance;
    OUTPUT(instance, s, p1);
    OUTPUT(instance, s, p2);
}
