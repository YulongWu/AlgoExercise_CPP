#include "Util_Set1.h"
#include <algorithm>

template <typename T>
Set1<T>::Set1() {
    ;
}
template <typename T>
Set1<T>::Set1(T e) {
    elements_.push_back(e);
}
template <typename T>
void Set1<T>::AddElement(T e) {
    elements_.push_back(e);
}
template <typename T>
T Set1<T>::GetElement(int index) {
    if(index >= elements_.size()) {
        cout << "Frankie said: GetElement index illegal." << endl;
        throw -1;
    }
    return elements_[index];
}
template <typename T>
Set1<T> Union(Set1<T> &s1, const Set1<T> &s2, bool (*compare)(T v1, T v2)) {
    Set1<T> merge_set;
    for(int i=0; i<s1.elements_.size(); ++i) {
        merge_set.elements_.push_back(s1.elements_[i]);
    }
    for(int i=0; i<s2.elements_.size(); ++i) {
        merge_set.elements_.push_back(s2.elements_[i]);
    }
    sort(merge_set.elements_.begin(), merge_set.elements_.end(), compare);
    for(int i=0; i<merge_set.elements_.size()-1; ++i) {  //is there problem when size() changed?
        if(merge_set.elements_[i].value_ == merge_set.elements_[i+1].value_) {
            merge_set.elements_[i].Merge(merge_set.elements_[i+1]);
            merge_set.elements_.erase(merge_set.elements_.begin()+i+1);
        }
    }
    return merge_set;
}
template <typename T>
int Set1<T>::GetSetSize() const{
    return elements_.size();
}
