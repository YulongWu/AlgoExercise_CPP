#include <iostream>
#include <string>
using namespace std;

bool IsPermutationOfString(const string sa, const string sb) {
    int occur_nums[128] = {0};
    for(string::const_iterator it = sa.begin(); it < sa.end(); ++it) {  //error 1: if you are using iterator on a const object, you must declare a const iterator.
        occur_nums[*it]++;
    }
    for(string::const_iterator it = sb.begin(); it < sb.end(); ++it) {
        occur_nums[*it]--;
        if(occur_nums[*it] < 0)
            return false;
    }
    for(int i=0; i<128; ++i) {
        if(occur_nums[i] != 0)
            return false;
    }
    return true;
}

int main() {
    string sa = "hello,  world.", sb = "wodlr., lleoh";
    cout << IsPermutationOfString(sa, sb) << endl; 
}
