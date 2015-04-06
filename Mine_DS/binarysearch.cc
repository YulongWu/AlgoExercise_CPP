#include <iostream>
using namespace std;
int BinarySearch(char * arr, int b, int e, char v) {
    if(!arr || b > e)
        return -1;
    int low = b, high = e, mid = 0;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(arr[mid] <= v)
            low = mid + 1;
        else if(arr[mid] > v)
            high = mid - 1;
    }
    if(arr[high] == v)
        return high;
    return -1;
}

int main() {
    char s[] = "23444567";
    cout << BinarySearch(s, 0, 6, '4') << endl;
}
