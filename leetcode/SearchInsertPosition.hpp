#include "stdafx.h"
#include "Structs.h"
using namespace std;

class SearchInsertPosition {
public:
	int searchInsert(const int A[], const int n, const int target) {
		int maxId = n - 1, minId = 0, midId;
		while (maxId > minId + 1)
		{
			midId = (maxId + minId) / 2;
			if (A[midId] == target)
				return midId;
			else if (A[midId] > target)
				maxId = midId;
			else
				minId = midId;
		}
		if (target == A[minId] || target == A[maxId])
			return target == A[minId] ? minId : maxId;
		else if (target < A[minId])
			return minId;
		else if (target > A[maxId])
			return maxId + 1;
		else
			return maxId;
	}
};