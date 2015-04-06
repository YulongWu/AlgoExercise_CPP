#include <iostream>
#include <cmath>
using namespace std;

//method 1: a crude solution
int M1Count1InK(int k) {
    int log_k=k, count = 0;
    while(k) {
        if(k%10==1)
            ++count;
        k /= 10;
    }
//    cout << "M1Count1InK: k=" << log_k << ", result=" << count << endl;
    return count;
}
int M1Count1(int n) {
    int sum=0;
    if(n<0) n=-n;
    for(int i=1; i<=n; ++i) {
        sum += M1Count1InK(i);
    }
    return sum;
}

//method 2: a wiser solution, by analyzing the law of number
//Recursive method
int M2Count1_Recursive(int n) {
    if(n<0) n = -n;
    int mask=1, sum=0, p=0;
    while(10*mask <= n) {  //make a mask to get the dth number of n
        mask *= 10;
        ++p;
    }
    int k = n / mask;
    if(p >= 1)
        sum += k * p * pow(10, p-1);
    if(k == 1)
        sum += n % mask + 1;
    else if(k > 1)
        sum += pow(10, p);
    if(p > 0)
        sum += M2Count1_Recursive(n % mask);
    return sum;
}
//Non-recursive method
int M2Count1_NonRecursive(int n) {
    if(n<0) n = -n;
    int mask=1, sum=0, p=0;
    while(10*mask <= n) {  //make a mask to get the dth number of n
        mask *= 10;
        ++p;
    }
    for(; mask > 0; n %= mask, mask/=10, --p) {
        int k = n / mask;
        if(p >= 1) 
            sum += (k) * (p) * pow(10, p-1);  //count 1 occurences below dth
        //count 1 occurences at dth position
        if(k == 1) 
            sum += n % mask + 1;  
        else if(k > 1) 
            sum += pow(10, p);
    }
    return sum;
}
//Method 3: A method from "Beauty of Programming"
int M3Count1_1_(int n, int p) {
    int mask = 1;
    for(int i=1; i <= p; ++i) 
        mask *= 10;
    int low_nums = n % mask;
    int high_nums = n / (mask * 10);
    int k = n / mask % 10;
    if(k == 0)
        return high_nums * pow(10, p);
    else if(k == 1)
        return high_nums * pow(10, p) + low_nums + 1;
    else
        return (high_nums + 1) * pow(10, p);
}
int M3Count1_1(int n) {
    if(n<0) n = -n;
    int sum = 0;
    for(int i=1, p=0; i <= n; i *= 10, p++) {
        sum += M3Count1_1_(n, p);
    }
    return sum;
}
int M3Count1_2(int n) {
    int mask = 1, k = 0, high_nums = 0, low_nums = 0, sum = 0, p = 0;
    for(; mask <= n; mask *= 10, ++p) {
        high_nums = n / (mask * 10);
        low_nums = n % mask;
        k = n / mask % 10;
        if(k == 0)
            sum +=  high_nums * pow(10, p);
        else if(k == 1)
            sum +=  high_nums * pow(10, p) + low_nums + 1;
        else
            sum +=  (high_nums + 1) * pow(10, p);
    }
    return sum;
}
int binstrtoi(string s) {
    int res = 0;
//    cout << "s=\"" << s << "\", s.length()=" << s.length() << endl;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '0' || s[i] == '1')
            res = (res << 1) + (s[i]=='0'?0:1);
        else {
            cout << "illegal character(only '0' or '1') is permitted.";
            throw -1;
        }
//        cout << "In loop: i=" << i << ", s[i]=" << s[i] << ", res=" << res << endl;
    }
    return res;
}
int Count1AsBinary(int b) {
    int count = 0;
    while(b) {
        b &= (b-1);
        ++count;
    }
    return count;
}
int Count1InBinary_M1(string s){
    int n = binstrtoi(s), count = 0;
    for(int i=1; i <= n; ++i) {
        count += Count1AsBinary(i);
    }
    return count;
}
int Count1InBinary_M2(string s) {
    int sum = 0, len = s.length(), p = len - 1;
    string buf_high, buf_low;
    for(int i=0; i < len; ++i, --p) {
        buf_high = s.substr(0, i);
        buf_low = s.substr(i+1, len-i-1);
//        cout << endl << "s=\"" << s << "\", i=" << i << ", s[i]='" << s[i] << "', buf_high=\"" << buf_high << "\", buf_low=\"" << buf_low << "\"" ;
        if(s[i] == '1')
            sum += binstrtoi(buf_high) * pow(2, p) + binstrtoi(buf_low) + 1;
        if(s[i] == '0')
            sum += binstrtoi(buf_high) * pow(2, p);
    }
    return sum;
}
int main() {
    int input=0;
    do {
    cin >> input;
    cout << "method1: " << M1Count1(input) << endl;
    cout << "method2( non-recursive): " << M2Count1_NonRecursive(input) << endl;
    cout << "method2( recursive): " << M2Count1_Recursive(input) << endl;
    cout << "method3(1): " << M3Count1_1(input) << endl;
    cout << "method3(2): " << M3Count1_2(input) << endl;
    cout << "Count in binary: method1:"<< Count1InBinary_M1(to_string(input)) << endl;
    cout << "Count in binary: method2:"<< Count1InBinary_M2(to_string(input)) << endl;
    }while(input != 0);
}
