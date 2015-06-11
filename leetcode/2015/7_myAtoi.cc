//#include <cctype>
#include <iostream>
#include <string>
//#include <limits>
using namespace std;
/*
 * Errors I make...
 * Error 1: forget to assign negative value when there is '-'.
 * Error 2: forget to check the out of range cases.
 * Error 3: ugly code when adding the logic to check the out of range cases.
 */
int myAtoi(string str) {
    int res = 0;
    bool in_prefix = true, is_negative = false;
    int i=-1, val_begin=-1;
    for(i = 0; i < str.length(); ++i) {
        if(in_prefix && isspace(str[i]));
        else if(in_prefix && (str[i] == '-' || str[i] == '+')) {
            is_negative = str[i] == '-' ? true : false;
            in_prefix = false;
            val_begin = i+1;
        }
        else {
            in_prefix = false;
            if(str[i] >= '0' && str[i] <= '9') { //valid character test
                res = res * 10 + (str[i] - '0');
                if(val_begin == -1)
                    val_begin = i;
            }
            else
                break;    
        }
    }
    if(val_begin >= 0 && val_begin < i) {
        string value = str.substr(val_begin, i - val_begin);
        cout << "value: " << value << endl;
        int max_len = 10; //"2147483647".length()
        if(value.length() > max_len || !is_negative && value.length() == max_len && value > "2147483647" || is_negative && value.length() == max_len && value > "2147483648") {
            return is_negative ? -2147483648 : 2147483647;
        }
        //cout << "val_begin: " << val_begin << ", i: " << i << endl;
    }
    return is_negative ? 0-res : res;
}

int myAtoi_v2(string str) {
    int res = 0;
    bool is_negative = false, is_whitescan = true;
    for(string::iterator it = str.begin(), end = str.end(); it != end; ++it) {
        if(is_whitescan && isspace(*it));
        else if(is_whitescan && (*it == '-' || *it == '+')) {
            is_negative = *it == '-' ? true : false;
            is_whitescan = false;
        }
        else if(*it >= '0' && *it <= '9') {
            is_whitescan = false;
            //decide whether the current value will out of range
            if(res > 214748364 || res == 214748364 && (*it-'0' >= 8 || !is_negative && *it-'0' == 7))
                return is_negative ? -2147483648 : 2147483647;
            res = res * 10 + (*it - '0');
        }
        else {
            break;
        }
    }
    return is_negative ? 0-res : res;
}
/*
 * A more elegant implementation
 */
int myAtoi_v3(string str) {
    int res = 0;
    bool is_negative = false, is_whitescan = true;
    string::iterator it = str.begin(), end = str.end();
        while(it != end && isspace(*it))
            ++it;
        if(*it == '-' || *it == '+') {
            is_negative = *it == '-' ? true : false;
            it++;
        }
        while(it != end && *it >= '0' && *it <= '9') {
            //decide whether the current value will out of range
            if(res > INT_MAX / 10 || res == INT_MAX / 10 && (*it-'0' >= 8 || !is_negative && *it-'0' == 7))
                return is_negative ? INT_MIN : INT_MAX;
            res = res * 10 + (*it - '0');
            ++it;
        }
    return is_negative ? 0-res : res;
}
int main () {
    cout << myAtoi_v3("  -234") << endl;
    cout << myAtoi_v3("  234") << endl;
    cout << myAtoi_v3("  234abd  ") << endl;
    cout << myAtoi_v3("   ") << endl;
    cout << myAtoi_v3("  -a") << endl;
    cout << myAtoi_v3("  a") << endl;
    cout << myAtoi_v3("2147483648") << endl;
    cout << myAtoi_v3("-2147483648") << endl;
    cout << myAtoi_v3("-2147483649") << endl;
    cout << myAtoi_v3("1") << endl;
}
