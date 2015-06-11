#include <iostream>
using namespace std;

void print(int a[], int len) {
    if(!a || len < 1)
        return;
    int *p = a;
    while(p-a < len) {
        cout << *(p++) << ", ";
    }   
    cout << endl;
}

int comp_int(int v1, int v2) {
    return v1 - v2;
}
