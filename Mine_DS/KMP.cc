#define OUTPUT(ins, s, p) cout << "Match index on \"" << s << "\" with \"" << p << "\" is " << ins.KMPMatch(s, p) << endl;
#include <iostream>
#include "KMP.h"

int KMP::KMPMatch(const string s, const string pattern) {
    cout << "enter KMPMatch..." << endl;
    GetNextBetter(pattern);
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
    if(pattern.length() < 1)
        return;
    if(next_)
        delete next_;
    next_ = new int[pattern.length()];
    int p_index=0, next_value=0;
    for(int next_index=0; next_index<pattern.length(); ++next_index) {
        if(next_index < 2);
        else if(pattern[p_index] == pattern[next_index-1]) {
            ++next_value;
            ++p_index;
        }
        else if(p_index != 0){
            while(pattern[next_index-1] != pattern[p_index] && p_index != 0)
                p_index = pattern[p_index];
            next_value = pattern[p_index] + (p_index == 0 ? 0 : 1);
        }
        next_[next_index] = next_value;
    }
}

void KMP::GetNextBetter(const string pattern) {
    cout << "enter GetNextBetter..." << endl;
    if (pattern.length() < 1)
        return;
    if (next_)
        delete next_;
    next_ = new int[pattern.length()]; //error1: forgot to new next_, which result in dangling pointer and segmentation fault
    int i=0, j=0;
    next_[0] = 0;
    while (i < pattern.length()) {
        cout << "i=" << i << "; j=" << j << endl;
        if (j == 0 || pattern[i] == pattern[j]) {
            if(i != j && pattern[i] == pattern[j]) ++j;
            ++i; 
            next_[i] = j;
        }
        else {
            j = next_[j];
        }
    }
    /* for debug
    cout << "generated pattern string: " << endl;
    for (int i = 0; i < pattern.length(); ++i) {
        cout << next_[i] << " ";
    }
    cout << endl;
    */ //for debug end
}

int main() {
    //string s = "ababcabcacbab", p1 = "abcad", p2 = "abcac";
    string s = "ababcabcacbab", p1 = "abaabc", p2 = "abcab";
    KMP instance;
    OUTPUT(instance, s, p1);
    OUTPUT(instance, s, p2);
}
