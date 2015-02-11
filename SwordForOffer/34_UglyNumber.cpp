#include <iostream>
using namespace std;
class Solution {
	public:
		static long getNthUglyNumber(int n) {
			if(n<=0) return 0L;
			long *uglyNumbers = new long[n];
			int uglyNumbersIndex = 0;
			uglyNumbers[uglyNumbersIndex++]= 1;
			long *pMultiply2=uglyNumbers, *pMultiply3=uglyNumbers, *pMultiply5=uglyNumbers;
			while(uglyNumbersIndex<n) {
				long min = getMin(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
				uglyNumbers[uglyNumbersIndex++] = min;
				if(min == *pMultiply2*2)
					++pMultiply2;
				if(min == *pMultiply3*3)
					++pMultiply3;
				if(min == *pMultiply5*5)
					++pMultiply5;
			}
			int res = uglyNumbers[uglyNumbersIndex-1]; 
			delete[] uglyNumbers;
			return res; 
		}
		static long getMin(long a, long b, long c) {
			return a>=b?(b>c?c:b):(a>c?c:a);
		}
};
int main() {
	for(int i=1; i<=15; ++i) {
		cout << i << "th Ugly:" << Solution::getNthUglyNumber(i) << endl;
	}
	cout << "3th Ugly: " << Solution::getNthUglyNumber(3) << endl;
	cout << "5th Ugly: " << Solution::getNthUglyNumber(5) << endl;
	cout << "1500th Ugly: " << Solution::getNthUglyNumber(1500) << endl;
	cout << "1499th Ugly: " << Solution::getNthUglyNumber(1499) << endl;
	cout << "100th Ugly: " << Solution::getNthUglyNumber(100) << endl;

}
