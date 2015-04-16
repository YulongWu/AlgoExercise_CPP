#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
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
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, vector<vector<string>>> set1, set2, *set_cur, *set_target;  //error: too few template arguments for class template 'unordered_map'. This error is caused by missing unordered_map header.
    //two-end BFS to effectively prune, BFS strategy will get the smaller end to traverse in each iteration
    //error: logic error: notice that the search paths is not a tree but a graph, so unordered_map<string, vector<string>> would leads to paths lost, need to use unordered_map<string, vector<vector<string>>> 
    vector<vector<string>> vec_start(1, vector<string>(1, start)), vec_end(1, vector<string>(1, end));  //error: this is a good practise to initializing 2-dimentional vector
    set1[start] = vec_start;
    set2[end] = vec_end;
    int K = start.size();
    bool isUpdated = true, isFinished = false;
    vector<vector<string>> res;
    for(int depth = 2; isUpdated && !isFinished; ++depth) {  //error: removed dict.size() > 0, because it will cause loop break before the last iteration
        if(set1.size() > set2.size()) {
            set_cur = &set2;
            set_target = &set1;
        }
        else {
            set_cur = &set1;
            set_target = &set2;
        }
        unordered_map<string, vector<vector<string>>> inter_set;
        isUpdated = false;
        unordered_set<string> deleting;
        for(auto iteri=set_cur->cbegin(), end = set_cur->cend(); iteri!=end; ++iteri) {
            for(int i=0; i<K; ++i) {
                string temp = (*iteri).first;
                char ch = 'a';
                for(int c = 0; c<26; ++c) {
                    temp[i] = ch + c;
                    if(set_target->find(temp) != set_target->end()) {
                        const vector<vector<string>> *new_paths_first = &(*iteri).second;
                        const vector<vector<string>> *new_paths_second = &(*set_target)[temp];
                        auto iter_in = set_cur->cbegin();
                        if(((*iter_in).second)[0][0] != start) {  //error: must determine the start path and end path before the merging
                            new_paths_first = &(*set_target)[temp];
                            new_paths_second = &(*iteri).second;  
                        }
                        for_each(new_paths_first->cbegin(), new_paths_first->end(), [&] (const vector<string> &first_path) {
                                for_each(new_paths_second->cbegin(), new_paths_second->cend(), [&] (const vector<string> &second_path) {
                                    vector<string> temp_path = first_path;
                                    for_each(second_path.crbegin(), second_path.crend(), [&](const string &s) {
                                        temp_path.push_back(s);
                                        });
                                    res.push_back(temp_path);
                                    });
                                });  //merge two vectors and reversely for second vector
                        isFinished = true;
                    }
                    else if(dict.find(temp) != dict.end()) {
                        vector<vector<string>> new_paths = (*iteri).second;
                        for_each(new_paths.begin(), new_paths.end(), [&] (vector<string> &path) {
                                path.push_back(temp);
                                });
                        if(inter_set.find(temp) == inter_set.end())
                            inter_set[temp] = new_paths;
                        else {
                            for_each(new_paths.begin(), new_paths.end(), [&] (vector<string> &path) {
                                    inter_set[temp].push_back(path);
                                    });
                        }
                        //dict.erase(temp);  // error: can't erase here. It will cut the possible search path in following
                        deleting.insert(temp);
                        isUpdated = true;
                    }
                }
            }
        }
        for_each(deleting.begin(), deleting.end(), [&] (const string &s) {
                    dict.erase(s);
                });
        *set_cur = inter_set;
//        swap(set1, inter_set);  //how about set1 = inter_set; ?
    }
    return res;
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
void printPaths(vector<vector<string>> paths) {
    for_each(paths.begin(), paths.end(), [](vector<string> v) {
                for_each(v.begin(), v.end(), [](string s) {
                    cout << s << ", ";
                    });
                cout << endl;
            });
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
//    cout << ladderLength(start, end, *dict) << endl;
    vector<vector<string>> all_paths = findLadders(start, end, *dict);
    printPaths(all_paths);
}
