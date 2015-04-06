#include <vector>
using namespace std;

class NumTrees {
private:
	vector<unsigned long long> cache;
public:
	unsigned long long numTrees(int n) {
		if (n <= 1)
			return n<1 ? 0 : 1;
		if (cache.size()<n)
			cache.resize(n * 2);
		if (cache[n] != 0)
			return cache[n];
		unsigned long long res = 0;
		//when n >= 2
		for (unsigned long long i = 0; i<n; i++)   //i means the number of nodes assigned to the other side
		{
			unsigned long long leftNum = numTrees(n - 1 - i);
			unsigned long long rightNum = numTrees(i);
			res += (leftNum == 0 ? 1 : leftNum) * (rightNum == 0 ? 1 : rightNum);
		}
		cache[n] = res;
		return res;
	}
	unsigned long long numTreesNoOpt(int n) {
		if (n <= 1)
			return n<1 ? 0 : 1;
		unsigned long long res = 0;
		//when n >= 2
		for (unsigned long long i = 0; i<n; i++)   //i means the number of nodes assigned to the other side
		{
			unsigned long long leftNum = numTrees(n - 1 - i);
			unsigned long long rightNum = numTrees(i);
			res += (leftNum == 0 ? 1 : leftNum) * (rightNum == 0 ? 1 : rightNum);
		}
		return res;
	}
};