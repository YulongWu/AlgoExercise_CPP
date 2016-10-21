#include <iostream>
using namespace std;

char *replaceSpace(char const *s) {
    if(s == NULL) 
        return NULL;
    int newLen = 0;
    for(char const *p = s; *p != '\0'; ++p) {
        if(*p == ' ')
            newLen += 2;
        ++newLen;
    }
    char *newBuf = new char[newLen];
    char const *oldP = s;
    char *newP = newBuf;
    for(; *oldP != '\0'; ++oldP, ++newP) {
        if(*oldP != ' ')
            *newP = *oldP;
        else {
            *(newP++) = '%';
            *(newP++) = '2';
            *newP = '0';
        }
    }
    return newBuf;
}

int main() {
    char *s = "We are happy.";
    s = replaceSpace(s);
    if (s)
        cout << s << endl;
}
