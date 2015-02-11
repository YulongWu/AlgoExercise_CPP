#include <iostream>
#include <string>
using namespace std;

bool findInMatrix(const int matrix[][4], const int rows, const int columns, const int toFind) {
    if(matrix == NULL) return false;
    for(int row=0; row<rows;) {
        for(int column=columns-1; column>=0;) {
            if(toFind == matrix[row][column])
                return true;
            else if(toFind < matrix[row][column])
                --column;
            else
                ++row;
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
