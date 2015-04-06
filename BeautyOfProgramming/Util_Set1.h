/* This is a set which is originally implemented for 24Points game. It  supports following operations:
 * 1. Union
 * 2. Traverse
 * It just maintained an ordered array for elements of set.
*/
#pragma once
#include <vector>
using namespace std;

template <typename T>
class Set1 {
private:
    vector<T> elements_;
public:
    friend class Set1<T>;
    Set1();
    Set1(T e);
    template <typename TT>
    friend Set1<TT> Union(Set1<TT> &s1, const Set1<TT> &s2, bool (*compare)(TT, TT)); 
    T GetElement(int index);
    void AddElement(T e);
    int GetSetSize() const;
};

