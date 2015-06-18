/* Following is the answers of problem 11 in section 11.5 of "Programming Pearls"
 */
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int partition(vector<int> a, int len) {
    if(len < 1) 
        return -1;
    if(len == 1)
        return 0;
    int t = a[0];
    int i = 0, j = len, it = -1, jt = len;
    while(i < j) {
        while(--j > i) {
            if(a[j] == t) 
                swap(a[j], a[--jt]);
            else if(a[j] < t)
                break;
        }
        if(i < j) a[i] = a[j];
        while(++i < j) {
            if(a[i] == t)
                swap(a[i], a[++it]);
            else if(a[i] > t)
                break;
        }
        if(i < j) a[j] = a[i];
    }
    a[j] = t;
    for(int ii = j-1; ii >= j-it-1; --ii)
        swap(a[ii], a[j-ii-1]);
    for(int jj = j+1; jj <= j+len-jt; ++jj)
        swap(a[jj], a[len - (jj - j)]);
    printf("\t\t");
    for(int i=0; i<len; ++i)
        printf("%d, ", a[i]);
    printf("\n");
    return j;
}

/*This version 2 is modified based on the program on p223 select1 function*/
int partition_v2(vector<int> a, int len) {
    if(len < 1)
        return -1;
    int t = a[0];
    int i = -1, j = len, it = -1, jt = len;
    while(true) {
        while(a[--j] >= t && j > 0) {
            if(a[j] == t)
                swap(a[j], a[--jt]);
        }
        while(a[++i] <= t && i <= j) {
            if(a[i] == t)
                swap(a[i], a[++it]);
        }
        if(i <= j) swap(a[i], a[j]);
        else break;
    }
    //printf("i=%2d, j=%2d, it=%2d, jt=%2d\n", i, j, it, jt);
    for(int ii=j; ii >= j - it && ii > it; --ii)
        swap(a[ii], a[j - ii]);
    for(int jj=i; jj < i + len - jt; ++jj)
        swap(a[jj], a[len - jj + i - 1]);
    printf("\t\t");
    for(int i=0; i<len; ++i)
        printf("%d, ", a[i]);
    printf("\n");
    return j;
}
static const int TEST_NUM = 6;
int main() {
    vector<int>* cases[TEST_NUM] = {0};
    int c1[] = {7,5,8,7,12,-3};
    cases[0] = new vector<int>(c1, c1 + sizeof(c1) / sizeof(int));
    int c2[] = {5,3,3,3};
    cases[1] = new vector<int>(c2, c2 + sizeof(c2) / sizeof(int));
    int c3[] = {5,6,6,6};
    cases[2] = new vector<int>(c3, c3 + sizeof(c3) / sizeof(int));
    int c4[] = {5,5,5,3};
    cases[3] = new vector<int>(c4, c4 + sizeof(c4) / sizeof(int));
    int c5[] = {3,5,5,5};
    cases[4] = new vector<int>(c5, c5 + sizeof(c5) / sizeof(int));
    int c6[] = {5,6,5,3};
    cases[5] = new vector<int>(c6, c6 + sizeof(c6) / sizeof(int));
    for(int c=0; c < TEST_NUM; ++c) {
        printf("  Test cases %d:\n", c);
        printf("    Original:\n");
        printf("\t\t");
        for(int i=0; i<cases[c]->size(); ++i)
            printf("%d, ", (*cases[c])[i]);
        printf("\n");
        printf("    v1:\n");
        partition(*cases[c], cases[c]->size());
        printf("    v2:\n");
        partition_v2(*cases[c], cases[c]->size());
    }
}
