#include <iostream>
using namespace std;

int add(int a, int b) {
    int res=0, mask=1, carry=0;
    for(int i=0; i<sizeof(int)<<3; ++i,mask<<=1) {
        if((a&1)==1 && (b&1)==1) {
            if(carry)
                res |= mask;
            carry = 1;
        }
        else if((a&1)==1 || (b&1)==1) {
            if(!carry)
                res |= mask;
        }
        else {
            if(carry)
                res |= mask;
            carry = 0;
        }
        a>>=1;
        b>>=1;
    }
    return res;
}
int main() {
    int v1=0, v2=0;
    do{
        cout << "input:";
        cin >> v1 >> v2;
        cout << v1 << "+" << v2 << "=" << add(v1,v2) << endl;
    }while(v1);
}
