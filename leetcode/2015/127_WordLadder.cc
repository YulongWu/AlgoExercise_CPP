#include <iostream>
#include <unordered_set>
#include <limits>
#include <vector>
#include "../CommonUtils.hpp"
using namespace std;

bool inline _isDistanceOne(const string &a, const string &b) {
    if(a.length() != b.length())
        throw -1;
    int distance = 0;
    for(int i=0; distance < 2 && i < a.length(); ++i) {
        if(a[i] != b[i])
            ++distance;
    }
    return distance == 1;
}
void _printMask(int mask[], int size) {
    cout << "mask: ";
    for(int i=0; i<size; ++i) {
        cout << mask[i];
    }
    cout << endl;
}
int _ladder(string end, unordered_set<string> &dict, int mask[]) {  //previously I used mask as int, it will occur error when the size of dict is above 31
    bool isUpdated = true;
    auto iteri = dict.begin(), iterj = dict.begin();  //I previously declared 
    for(int depth = 2; isUpdated && depth <= dict.size()+2; ++depth) {
        int i, j;
        isUpdated = false;
        for(i=0, iteri=dict.begin(); i<dict.size(); ++i, ++iteri) {
            if(mask[i] == depth) {
                if(_isDistanceOne(*iteri, end))
                    return depth + 1;
                for(j=0, iterj=dict.begin(); j<dict.size(); ++j, ++iterj) {
                    if(mask[j] == -1 && _isDistanceOne(*iteri, *iterj)) {
                        mask[j] = depth + 1;
                        isUpdated = true;
                    }
                }
            }
        }
    }
    return 0;
}
int ladderLength(string start, string end, unordered_set<string> &dict) {
    if(start == end)
        return 1;
    if(_isDistanceOne(start, end))  //error: I forgot this case.
        return 2;
    int *mask = new int[dict.size()];
    for(int i=0; i < dict.size(); ++i){
        mask[i] = -1;
    }
    int i=0;
    for(auto iter=dict.begin(); i<dict.size(); ++i, ++iter) 
        if(mask[i] == -1 && _isDistanceOne(start, *iter)) 
            mask[i] = 2;
    return _ladder(end, dict, mask);
}
unordered_set<string>* _buildSet(const string &src) {
    vector<string> vec = Boosted_string::tokenize_string(src, ",");
    unordered_set<string> *set = new unordered_set<string>();
    for_each(vec.begin(), vec.end(), [&] (string s){
            set->insert(s);
            });
    return set;
}
int main() {
//    string start = "hit", end = "cog";
    string start = "qa", end = "sq";
    unordered_set<string> *dict = new unordered_set<string>();
/*
    dict->insert("hot");
    dict->insert("dot");
    dict->insert("dog");
    dict->insert("lot");
    dict->insert("log");
*/
    string src = "si,go,se,cm,so,ph,mt,db,mb,sb,kr,ln,tm,le,av,sm,ar,ci,ca,br,ti,ba,to,ra,fa,yo,ow,sn,ya,cr,po,fe,ho,ma,re,or,rn,au,ur,rh,sr,tc,lt,lo,as,fr,nb,yb,if,pb,ge,th,pm,rb,sh,co,ga,li,ha,hz,no,bi,di,hi,qa,pi,os,uh,wm,an,me,mo,na,la,st,er,sc,ne,mn,mi,am,ex,pt,io,be,fm,ta,tb,ni,mr,pa,he,lr,sq,ye";
    dict = _buildSet(src);
    cout << ladderLength(start, end, *dict) << endl;
}
