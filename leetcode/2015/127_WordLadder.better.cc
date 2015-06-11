#include <iostream>
#include <unordered_set>
#include <limits>
#include <vector>
#include "../CommonUtils.hpp"
using namespace std;
/*
 * Before performance tuning, the original code running for 2074ms.
 * After the tuning as following, running for .
 */
bool inline _isDistanceOne(const string &a, const string &b) {
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
int _ladder(string start, string end, unordered_set<string> &dict) {  //previously I used mask as int, it will occur error when the size of dict is above 31
    unordered_set<string> set1, set2, *set_cur, *set_target;
    //two-end BFS to effectively prune, BFS strategy will get the smaller end to traverse in each iteration
    set1.insert(start);
    set2.insert(end);
    int K = start.size();
    bool isUpdated = true;
    for(int depth = 2; isUpdated; ++depth) {  //error: removed dict.size() > 0, because it will cause loop break before the last iteration
        if(set1.size() > set2.size()) {
            set_cur = &set2;
            set_target = &set1;
        }
        else {
            set_cur = &set1;
            set_target = &set2;
        }
        unordered_set<string> inter_set;
        isUpdated = false;
        for(auto iteri=set_cur->begin(), end = set_cur->end(); iteri!=end; ++iteri) {
            for(int i=0; i<K; ++i) {
                string temp = (*iteri);
                char ch = 'a';
                for(int c = 0; c<26; ++c) {
                    temp[i] = ch + c;
                    if(set_target->find(temp) != set_target->end())
                        return depth;
                    if(dict.find(temp) != dict.end()) {
                        inter_set.insert(temp);
                        dict.erase(temp);
                        isUpdated = true;
                    }
                }
            }
        }
        *set_cur = inter_set;
//        swap(set1, inter_set);  //how about set1 = inter_set; ?
    }
    return 0;
}
int ladderLength(string start, string end, unordered_set<string> &dict) {
    if(start == end)
        return 1;
    if(_isDistanceOne(start, end))  //error: I forgot this case.
        return 2;
    return _ladder(start, end, dict);
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
    string start = "hit", end = "cog";
//    string start = "qa", end = "sq";
    unordered_set<string> *dict = new unordered_set<string>();

    dict->insert("hot");
    dict->insert("dot");
    dict->insert("dog");
    dict->insert("lot");
    dict->insert("log");

//    string src = "si,go,se,cm,so,ph,mt,db,mb,sb,kr,ln,tm,le,av,sm,ar,ci,ca,br,ti,ba,to,ra,fa,yo,ow,sn,ya,cr,po,fe,ho,ma,re,or,rn,au,ur,rh,sr,tc,lt,lo,as,fr,nb,yb,if,pb,ge,th,pm,rb,sh,co,ga,li,ha,hz,no,bi,di,hi,qa,pi,os,uh,wm,an,me,mo,na,la,st,er,sc,ne,mn,mi,am,ex,pt,io,be,fm,ta,tb,ni,mr,pa,he,lr,sq,ye";
//    dict = _buildSet(src);
    cout << ladderLength(start, end, *dict) << endl;
}
