#include <iostream>
using namespace std;

string CompressString(const string orig) {
    if(orig.empty())
        return orig;
    string compr;
    string::const_iterator it = orig.begin();  //error 1: forget const_ before iterator again.
    char prev = *it++;  //error 4: don't forget to handle first character before the loop
    int count = 1;
    for(; it<orig.end(); ++it) {  //error 2: it's orig.end(), not it.end()
        if(prev != *it) {
            compr += prev + to_string(count);
            prev = *it;
            count = 1;  //error 3: count = 1, not count = 0
        }
        else {
            count++;
        }
    }
    //error 4: don't forget to handle last character after the loop
    compr += prev + to_string(count);
    if(compr.length() < orig.length())
        return compr;
    else
        return orig;
}

int main() {
    string orig = "aabccde";
    cout << orig << endl << "compressed: " << CompressString(orig);
}
