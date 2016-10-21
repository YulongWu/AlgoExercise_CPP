#pragma once
#include <string>
using namespace std;

class KMP {
private:
    int *next_;
    void GetNext(const string pattern);
    void GetNextBetter(const string &pattern);
public:
    int KMPMatch(const string s, const string pattern);
};
