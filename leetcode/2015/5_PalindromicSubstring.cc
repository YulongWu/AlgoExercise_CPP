#include <iostream>
#include <string>
using namespace std;

//for leetcode question: https://leetcode.com/problems/longest-palindromic-substring/
string longestPalindrome(string s) {
    string sharped_s = "";
    for(string::iterator it = s.begin(), end = s.end(); it != end; ++it) {
        sharped_s.push_back('#');
        sharped_s.push_back(*it);
    }
    sharped_s.push_back('#');
    int left = 0, right = 1, center=1, p_i=-1, p_j=-1, p_len=sharped_s.length();
    int max_len = 0, max_begin = 0;
    int *p = new int[sharped_s.length()];  //error: keep in mind that call memset after new.
    memset(p, 0, sharped_s.length()*sizeof(int));  //TODO: any other way to init memory?
    for(p_i=1; p_i < sharped_s.length(); p_i++) {
        p_j = (center << 1) - p_i; //center - (p_i - center);
        if(p_j >= 0 && p_i + p[p_j] >= right) {
            for(p[p_i] = p_j - left; p_i - p[p_i] - 1 >= 0 && p_i + p[p_i] + 1 < p_len && sharped_s[p_i - p[p_i] - 1] == sharped_s[p_i + p[p_i] + 1]; ++p[p_i]);
            center = p_i;
            left = center - p[p_i];
            right = center + p[p_i];
            if(max_len < p[p_i]) {
                max_len = p[p_i];
                max_begin = left >> 1;
            }
        }
        else {
            p[p_i] = p[p_j];
        }
    }
    cout << max_begin << ", " << max_len << endl;
    return s.substr(max_begin, max_len);
}

int main() {
    //cout << longestPalindrome("babcbabcbabab") << endl;
    cout << longestPalindrome("abcbadabcea") << endl;
}
