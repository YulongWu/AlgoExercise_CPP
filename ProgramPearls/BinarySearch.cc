#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
template<typename T>

//util functions for testing the binary search function
bool sorted(const vector<int> $array) {
    for(int i=1; i < array.size(); ++i) {
        if(array[i] < array[i-1])
            return 0;
    }
    return 1;
}

int binarySearch(const vector<T> &array, T t) {
    assert(sorted(array));
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

void scaffold_binarySearch(int n, int t) {
    vector<int> array(n);
    for(int i=0; i<n; ++i) array[i] = 10*i;
    int res_index = binarySearch<int>(array, t);
    cout << "  find at " << res_index << " for " << t << " in [";
    for(auto i : array) cout << i << ' ';
    cout << "]" << endl;
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

    //following scaffolding test method is learned from the book.
    scaffold_binarySearch(3, -5);
    scaffold_binarySearch(3, 0);
    scaffold_binarySearch(3, 5);
    scaffold_binarySearch(3, 10);
    scaffold_binarySearch(3, 15);
    scaffold_binarySearch(3, 20);
    scaffold_binarySearch(3, 25);
}
