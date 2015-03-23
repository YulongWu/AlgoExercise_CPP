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
int M2Count1(int n) {
    if(n<0) n = -n;
    int mask=1, sum=0, d=1;
    while(10*mask <= n) {  //make a mask to get the dth number of n
        mask *= 10;
        ++d;
    }
    for(; mask > 0; mask/=10, --d,n %= mask) {
        int k = n / mask;
        if(d >= 2) 
            sum += (k) * (d-1) * pow(10, d-2);  //count 1 occurences below dth
        //count 1 occurences at dth position
        if(k == 1) 
            sum += n % mask + 1;  
        else if(k > 1) 
            sum += pow(10, d-1);
    }
    return sum;
}

int main() {
    int input=0;
    do {
    cin >> input;
    cout << "method1: " << M1Count1(input) << endl;
    cout << "method2: " << M2Count1(input) << endl;
    }while(input != 0);
}
