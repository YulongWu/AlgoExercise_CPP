#include <iostream>
#include <string>
using namespace std;
bool findInMatrix(const int matrix[][4], const int width, const int length, const int toFind) {
    if(matrix == NULL) return false;
    for(int i=0; i<width;) {
        for(int j=length-1; j>=0;) {
            if(toFind == matrix[i][j])
                return true;
            else if(toFind < matrix[i][j])
                --j;
            else
                ++i;
        }
    }
    return false;
}
int main() {
    int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    int i;
    while(1) {
    cin >> i;
    cout << findInMatrix(matrix, 4,4,i) << endl;
    }
}
