#include <iostream>
using namespace std;

/*
 * Error 1: @line 11 for case 1783234548. add "mask < INT_MAX/10"
 * Error 2: @line 14 for case 1000021. change from "x >= 10" to "mask > 1"
 */
bool isPalindrome(int x) {
    if(x < 0) 
        return false;
    int mask = 1;
    while(mask < INT_MAX/10 && mask*10 <= x)  
        mask *= 10;
    while(mask > 1) {
        if(x / mask == x % 10) {
            x = x % mask / 10;
        }
        else
            return false;
        mask /= 100;
    }
    return true;
}

int main() {
    cout << isPalindrome(23432);
    cout << isPalindrome(1);
    cout << isPalindrome(138535831);
    cout << isPalindrome(0);

    cout << isPalindrome(-23);
    cout << isPalindrome(3456534);
    cout << isPalindrome(-2);
}
