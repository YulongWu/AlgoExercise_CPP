#include <cstdio>
#include <utility>
using namespace std;

/*Macro for test*/
#define TEST(x) \
    qsort(x, sizeof(x)/sizeof(int));  \
    for(int i=0; i < sizeof(x)/sizeof(int); ++i) {  \
        printf("%d, ", x[i]);  \
    }  \
    printf("\n");

void qsort(int x[], int n) {
    if(!x || n <= 1)
        return;
    int i = 0, j = n, t = x[0];
    /*pre loop condition: {i<j && x[0...i]<=t && x[j...n-1]>t} */
    while(i <= j) {
        do {
            ++i;
        }while(i < n && x[i] <= t);
        while(x[--j] > t)
            ;
        /*condition: 
         * (i < j && x[i] > t && x[j] <= t || i == j+1 && x[0...i-1] <= t && x[j+1...n-1] > t)
         */
        if(i < j) swap(x[i], x[j]);
    }
    /* termination: i == j+1 && x[0...i-1] <= t && x[j+1...n-1] > t*/
    swap(x[0], x[i-1]);
    qsort(x, i-1);
    qsort(x+i, n-j-1);
}

#define MAXSIZE 128
int main() {
    int c1[] = {3};
    TEST(c1);
    int c2[] = {1,2,3,4};
    TEST(c2);
    int c3[] = {4,3,2,1};
    TEST(c3);
    int c4[] = {5,5,5};
    TEST(c4);

}
