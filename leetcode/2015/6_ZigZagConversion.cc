#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    int len = s.length();
    string res = "";
    for(int r = 0; r < numRows; ++r) {
        int curCol = 0;
        int curIndex= (2 * numRows - 2) * curCol + r; 
        while(curIndex < len) {
            res.push_back(s[curIndex]);
            if(r != 0 && r != numRows - 1) {
                int midIndex = curIndex + numRows - r - 1 + numRows-2-r+1;
                if(midIndex < len)
                    res.push_back(s[midIndex]);
            }
            ++curCol;
            curIndex = (numRows > 1 ? 2 * numRows - 2 : 1) * curCol + r;
        }
    }
    return res;
}

int main() {
    string s = "PAYPALISHIRING";
    string s2 = "PAY";
    cout << convert(s, 3) << endl;
}
