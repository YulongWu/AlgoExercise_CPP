#include <iostream>
using namespace std;

int ord(int v, int index) {
//    cout << "v=" << v << "; index=" << index << endl;
    int mask = 1;
    while(mask*10 <= v) 
        mask *= 10;
    for(int i=1; i<index; ++i) {
        mask /= 10;
    }
    int res;
    if(!mask)
        return -1;
    v %= mask*10;
    res = v / mask;
//    cout << "result:" << res << endl;
    return res;
}
int Compare4MinInArray(int v1, int v2) {
//    cout << "compare:" << v1 << " and " << v2 << ": "<<endl;
    int prev_n1=0, prev_n2=0, i=1, n1=0, n2=0, res;
    do {
        prev_n1 = n1; prev_n2 = n2;
        n1 = ord(v1, i);
        n2 = ord(v2, i);
        ++i;
    }while(n1 != -1 && n1 == n2); 
    if(n1==-1 && n2==-1) {
        res = 0;
    }
    else if(n1 == -1) {
        i=1;
        do{
            n2 = ord(v2,i);
//            cout << "n2:" << n2 << endl;
            ++i;
        }while(n2 == prev_n1);
//        for(i=1; (n2=ord(v2, i)) == prev_n1; ++i);
//        cout << "v2:" << v2 << " i:" << i << " n2:" << n2 << " prev_n1" << prev_n1 <<endl;
        res = (n2==-1?0:prev_n1 - n2);
    }
    else if(n2 == -1) {
        for(i=1; (n1=ord(v1, i)) == prev_n2; ++i);
        res = (n1==-1?0:n1 - prev_n2);
    }
    else
        res = n1 - n2;
//    cout << "result:" << res << endl;
    return res;
}
void SimpleSelectSort(int a[], int len, int (*compare)(int, int)) {
    int min_pos;
    for(int i=0; i<len-1; ++i) {
        for(int j=i; j<len; ++j) {
            if(i==j) 
                min_pos = j;
            else if(compare(a[min_pos], a[j]) > 0)
                min_pos = j;
        }
        if(i != min_pos) {
            a[i] ^= a[min_pos];
            a[min_pos] ^= a[i];
            a[i] ^= a[min_pos];
        }
    }
}
void PrintMinPermutation(int a[], int len) {
    SimpleSelectSort(a, len, &Compare4MinInArray);
    for(int i=0; i<len; ++i)
        cout << a[i] << ",";
    cout << endl;
}

int main() {
    int a[] = {4,44,444, 451,454,456,442,41,0,99};
    PrintMinPermutation(a, sizeof(a)/sizeof(int));
}
