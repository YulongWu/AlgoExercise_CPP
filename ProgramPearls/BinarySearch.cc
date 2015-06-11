#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
template<typename T>
int binarySearch(const vector<T> &array, T t) {
    if(array.size() == 0)
        return -1;
    int low = 0, high = array.size()-1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(array[mid] >= t)
            high = mid - 1;
        else
            low = mid + 1;
        //assert(low <= high);  //used for test function of assertion
    }
    if(low < array.size() && array[low] == t)
        return low;
    else
        return -1;
}

int main() {
    int buf[] = {1,2,5,8,10};
    vector<int> *array = new vector<int>(buf, buf + sizeof(buf) / sizeof(int));
    vector<int> *array1 = NULL;  //this test will result in runtime error when copy the *array1 to parameter, so the function won't be entered.
    //assert(array != NULL && is_sorted(array))
    cout << binarySearch<int>(*array, 8) << endl;
    /*
     * if(result == -1) 
     *     assert(!mustbe(array, 0, array.size-1, 8));
     * else 
     *     assert(array[result] == 8);
     */
}
