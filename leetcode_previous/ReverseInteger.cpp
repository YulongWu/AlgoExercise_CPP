#include "stdafx.h"
#include "ReverseInteger.h";
int ReverseInteger::reverse(int x) {
		char intArray[32];
		char index = 0;
		int res = 0;
		res = x<0 ? 0 - x : x;
		while (res != 0){
			intArray[index++] = res % 10;
			res /= 10;
		}
		for (int i = 0; i<index; ++i){
			res = res * 10 + intArray[i];
		}
		if (x < 0)
			res = 0 - res;
		return res;
}