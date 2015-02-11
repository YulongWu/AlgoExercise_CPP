#include <iostream>
using namespace std;

class Solution{
	public:
	static bool isUgly(long num){
		while(num%2 == 0)
			num /= 2;
		while(num%3 == 0)
			num /= 3;
		while(num%5 == 0)
			num /= 5;
		return num==1?true:false;
	}
};
int main() {
	long num = 78732000L;
	cout << "is " << num << " ugly? " << Solution::isUgly(num) << endl;
	num = 78125000L;
	cout << "is " << num << " ugly? " << Solution::isUgly(num) << endl;
	num = 80621568L;
	cout << "is " << num << " ugly? " << Solution::isUgly(num) << endl;
}
