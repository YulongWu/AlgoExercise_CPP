/*
 * This question is interesting, especially for the O(n) solution. 
 * The question is: For an unsorted array, pls return a sub-array which has the max result of array length multiply the min value of it, which could be considered as the area of the sub-array.
 */
#include <iostream>
#include <stack>
#include <limits>
using namespace std;

struct Node {
    int value;
    int pos;
};

int GetArea(int min, int start, int end) {
    return min * (end - start);
}

int GetMaxAreaInArray_M1(int array[], int length) {
    int max_area = numeric_limits<int>::min();  //error 2: I used incorrect data to represent the minimum value of int. The correct one should be following:
/* 
 * #include <limits>  
 * int imin = std::numeric_limits<int>::min(); // minimum value
 * int imax = std::numeric_limits<int>::max();
 */
    stack<Node> s;  //error 1: s shouldn't be stack<int> type
    for(int i=0; i < length; ++i) {
        if(s.empty() || array[i] > s.top().value) {
            Node n = {array[i], i};
            s.push(n);
        }
        else {
            while(!s.empty() && s.top().value >= array[i]) {
                int area = GetArea(s.top().value, s.top().pos, i);
                if(area > max_area)
                    max_area = area;
                s.pop();
            }
            Node n = {array[i], i};
            s.push(n);
        }
    }
    while(!s.empty()) {
        int area = GetArea(s.top().value, s.top().pos, length-1);
        if(area > max_area)
            max_area = area;
        s.pop();
    }
    return max_area;
}

int recursive_M2(int array[], int start, int end) {
    if(start == end)
        return array[start];
    int mid = start + (end - start) / 2;
    int area_low = recursive_M2(array, start, mid);
    int area_high = recursive_M2(array, mid+1, end);
    int low = mid, high = mid + 1, min = array[mid];
    int max_area = numeric_limits<int>::min();
    int low_value = array[low], high_value = array[high];  //error 3: forget to initial them
    while(low >= start || high <= end) {  //error 4: left error: after changed update mechanism of low_value and high_value, forget change the "&&" to "||"
        if(low_value >= high_value) {
            if(min > low_value)  //error 5: it should be ">" not "<"
                min = low_value;
            int area = GetArea(min, low, high);
            if(max_area < area)
                max_area = area;
            --low;
            if(low < start)
                low_value = numeric_limits<int>::min();
            else
                low_value = array[low];
        }
        else {
            if(min > high_value)  //error 5: it should be ">" not "<"
                min = high_value;
            int area = GetArea(min, low, high);
            if(max_area < area)
                max_area = area;
            ++high;
            if(high > end)
                high_value = numeric_limits<int>::min();
            else
                high_value = array[high];
        }
    }
    if(area_low > area_high)
        max_area = max_area < area_low ? area_low : max_area;
    else
        max_area = max_area < area_high ? area_high : max_area;
    return max_area;
}
int GetMaxAreaInArray_M2(int array[], int length) {
    return recursive_M2(array, 0, length-1);
}
int main() {
    int a[] = {3,5,2,6,12,8,1,3,4};
    int a1[] = {3,5,2};
    cout << GetMaxAreaInArray_M1(a, sizeof(a)/sizeof(int)) << endl;
    cout << GetMaxAreaInArray_M2(a, sizeof(a)/sizeof(int)) << endl;
}
// * sum up popular operations of stack, queue, vector.
