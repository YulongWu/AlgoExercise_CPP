#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../CommonUtils.hpp"
using namespace std;
/*
 * Runtime: 32ms
 */
vector<int> twoSum_M1(vector<int> &numbers, int target) {
    vector<int> res = vector<int>(2, 0); 
    if(numbers.size() < 2)
        return res;
    unordered_map<int, int> set;
    for(int i=0; i < numbers.size(); ++i) {
        set[target - numbers[i]] = i;
    }       
    for(int i=0; i<numbers.size(); ++i) {
        if(set.find(numbers[i]) != set.end()) {
            res[0] = i + 1;  //plus 1 to change 0 based index to 1 based index
            res[1] = set[numbers[i]] + 1;
            if(res[0] != res[1])  //error: logical error: without this if, if will fail in the case: [3,2,4] target=6
                break;  //error: forgot the break
        }   
    }       
    if(res[0] == res[1])
        res[0] = res[1] = -1; 
    return res;
}
/*
 * Optimized by using a direct address hash-table instead of the normal hash-table. Running time: 13ms
 */
vector<int> twoSum_M2(vector<int> &numbers, int target) {
    vector<int> res = vector<int>(2, 0);
    if(numbers.size() < 2)
        return res;
    int set[100000] = {0};
    for(int i=0; i < numbers.size(); ++i) {
        if(numbers[i] < -50000 || numbers[i] >= 50000)
            throw "input value out of the range:[-50000, 50000)";
        set[numbers[i] + 50000] = i + 1;
    }
    for(int i=0; i<numbers.size(); ++i) {
        if(set[target - numbers[i] + 50000]) {
//            cout << "i=" << i << ", numbers[i]=" << numbers[i] << ", set[numbers[i]]=" << set[numbers[i]] << endl;
            res[0] = i + 1;  //plus 1 to change 0 based index to 1 based index
            res[1] = set[target - numbers[i] + 50000];
            if(res[0] != res[1])  //error: logical error: without this if, if will fail in the case: [3,2,4] target=6
                break;  //error: forgot the break
        }
    }
   if(res[0] == res[1])
        res[0] = res[1] = -1;
    return res;
}
/*
 * Following method is same as the above writen by C, which only used 4ms to finish all the test cases.
 */
int* twoSum_C(int numbers[], int n, int target) {
//    static int res_c[2] = {0};
    int *res_c = (int *)malloc(2*sizeof(int));
    if(n < 2)
        return res_c; 
    int set[100000] = {0};
    for(int i=0; i<n; ++i) {
        if(numbers[i] < -50000 || numbers[i] >= 50000)
            exit(1);  //in fact: there should return an error
        if(set[target - numbers[i] + 50000]) {
//            cout << "i=" << i << ", numbers[i]=" << numbers[i] << ", set[numbers[i]]=" << set[numbers[i]] << endl;
            res_c[0] = set[target - numbers[i] + 50000];
            res_c[1] = i + 1;  //plus 1 to change 0 based index to 1 based index
            if(res_c[0] != res_c[1])  //error: logical error: without this if, if will fail in the case: [3,2,4] target=6
                break;  //error: forgot the break
        }
        else
            set[numbers[i] + 50000] = i + 1;
    }
   if(res_c[0] == res_c[1])
        res_c[0] = res_c[1] = -1;
    return res_c;
}

int main() {
    vector<int> input = {3,2,4};
    int target = 6;
    vector<int> res = twoSum_M2(input, target);
    PrintVector(res);
    int input_c[] = {3,2,4};
    int* res_c = twoSum_C(input_c, 3, target);
    cout << "C: [ " << res_c[0] << ", " << res_c[1] << " ]" << endl;
    free(res_c);
}
