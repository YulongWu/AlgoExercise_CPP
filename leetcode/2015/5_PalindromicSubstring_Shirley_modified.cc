#include <iostream>
using namespace std;

int MaxHuiwen(string str)
{
    if(str.empty())
        return 0;
    string strCharp = "#";
    for(int i = 0; i < str.length(); ++i)
    {
        strCharp += str[i];
        strCharp += "#";
    }
    int len = strCharp.length();
    int *p = new int[len];
    p[0] = 0;
    int l = 0, c = 0, r = 0, maxl = 1;
    for(int i = 1; i < len; ++i)
    {
        int j = (c << 1) - i;
        if(j >= 0 && i + p[j] < r)
            p[i] = p[j] < r - i ? p[j] : r - i;
        else
        {
            for(p[i] = j<0?0:j-l; i-p[i]-1 >= 0 && i+p[i]+1 < len && strCharp[i+p[i]+1] == strCharp[i-p[i]-1]; ++p[i]);
            c = i;
            r = i+p[i];
            l = i-p[i];
        }
        //cout << "i=" << i << ", p[i]=" << p[i] << endl;
        maxl = maxl > p[i] ? maxl : p[i];
    }
    delete p;
    return maxl;
}

int main() {
    //cout <<  MaxHuiwen("babcbabcbab");
    cout <<  MaxHuiwen("abcbadabcea");
}
