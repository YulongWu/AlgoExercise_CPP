#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int map[128];
    fill_n(map, 128, -1);  //error: previously used "int map[26] = {-1};" which will only set the first element to -1 and rest to 0. std::fill_n() is a library function for this.
    int max_len=0, cur_len=0;
    for(int i=0; i<s.length(); ++i) {
        ++cur_len;
        char c = s[i];
        if(map[c] == -1) {
            map[c] = i;
        }
        else {
            int temp_len = i - map[c];
            if(temp_len < cur_len) 
                cur_len = temp_len;
            map[c] = i;
        }
        max_len = cur_len > max_len ? cur_len : max_len;  //error: logical error: I previously put this line under line 13, which will lost the update of last iteration for somecases.
    }
    return max_len;
}
/*
 * This guy's method is in same complexity with mine but more pricise
 */
int lengthOfLongestSubstring_M2(string s) {
    // for ASCII char sequence, use this as a hashmap
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }

    return longest;
}

int main() {
    string s = "tmmzuxt";
    cout << lengthOfLongestSubstring(s) << endl;
}
