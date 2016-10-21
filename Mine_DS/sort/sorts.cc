// input: a[0] will not be used to store value, a[len] will store the last value.
#define ERROR -1
#include <cstddef>
#include "sort_util.cc"
#include <iostream>
using namespace std;

void my_swap(int &v1, int &v2) {
    v1 ^= v2;
    v2 ^= v1;
    v1 ^= v2;
}
template <typename T>
void my_swap(T &v1, T &v2) {
    T p = v1;
    v1 = v2;
    v2 = p;
}
template <typename T>
void SimpleInsertSort(T a[], int len, int (*comp)(T, T)) {
    if(a == NULL || len <= 0)
        return;
    for(int i=2; i<=len; ++i) {
        if(comp(a[i], a[i-1]) < 0) {  //***this improvement is easy to forget, but this improvement will make the program looks more complicated, the version without it see bolow.
            a[0] = a[i];
            int j=i-1;
            for(; comp(a[j],a[0])>0; --j) {
                a[j+1] = a[j];
            }
            a[j+1] = a[0];
        }
    }
}

template <typename T>
void SimpleInsertSort_v2(T a[], int len, int (*comp)(T, T)) {
    if(a == NULL || len <=0)
        return;
    for(int i=2; i <= len; ++i) {
        a[0] = a[i];
        int j = i-1;
        for(; comp(a[j], a[0]) > 0; --j)
            a[j+1] = a[j];
        a[j+1] = a[0];
    }
}

/*
 * The time complexity is still O(n^2), due to the times of movement
 */
template <typename T>
void BinaryInsertSort(T a[], int len, int (*comp)(T, T)) {
    if(a == NULL || len <= 0)
        return;
    for(int i=2; i<=len; ++i) {
        if(comp(a[i], a[i-1]) < 0) {
            int low = 1, high = i-1;
            while(low <= high) {  //*don't forget "="
                int mid = (low+high)/2;
                if(comp(a[mid], a[i]) < 0)  //***in order to make sort stable, we should consider a[mid] < a[i] and a[mid] == a[i] the same.
//** It's a[i] >= a[mid], not a[mid] >= a[i]!
                    low = mid+1;
                else
                    high = mid-1;
            }
            a[0] = a[i];
            int j;
            for(j=i; j > low; --j) {
                a[j] = a[j-1];
            }
            a[j] = a[0];
        }
    }
}

template <typename T>
void BubbleSort(T a[], int len, int (*comp)(T, T)) {
    for(int i=1; i <=len-1; ++i) {
        for(int j=1; j <= len-i; ++j) {
            if(comp(a[j], a[j+1]) > 0) {
                a[j] ^= a[j+1];
                a[j+1] ^= a[j];
                a[j] ^= a[j+1];
            }
        }
    }
}
/*
 * Given the array is approximate sorted, there is a improvement for BubbleSort.
 * Consider this case: 8, 2, 3, 4, 5, 6, 1, 7, in which only two elements(8 and 1) is unordered. So we improvement the bubble sort as following to deal with this kind of cases.
 */
template <typename T>
void BubbleSort_v2(T a[], int len, int (*comp)(T, T)) {
    int low = 1, high = len;
    for(; low < high; ) {
        for(int i = low; i < high; ++i)
            if(comp(a[i], a[i+1]) > 0)
                swap(a[i], a[i+1]);
        --high;
        for(int i = high; i > low; --i)
            if(comp(a[i], a[i-1]) < 0)
                swap(a[i], a[i-1]);
        ++low;
    }
}

template <typename T>
int Partition(T a[], int start, int end) {
    if(start > end)
        throw ERROR;
    T pivot = a[start], low = start, high = end;
    while(low < high) {
        while(low < high && a[high] >= pivot)
            --high;
        a[low] = a[high];
        while(low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}
/*
 * This partition method is easier to be understand than previous one, but it result in more times of movements for many cases.
 * 20160528: this partition is not correct
 */
template <typename T>
int Partition_v2(T a[], int start, int end) {
    int wall = start, cur = start;
    while(cur < end) {
        if(a[cur] < a[end]) {
            my_swap(a[wall], a[cur]);
            ++wall;
        }
        ++cur;
    }
    my_swap(a[wall], a[end]);
    return wall;
}
// Following is Quick Sort code.
template <typename T>
void QSort(T a[], int start, int end) {
    int split;
    if(start < end) {
        split = Partition<T>(a, start, end);
        QSort(a, start, split-1);
        QSort(a, split+1, end);
    }
    cout << "split: " << split << endl;
    print(a+start, end-start+1);
}
template <typename T>
void QuickSort(T a[], int len) {
    if(a == NULL || len <= 0)
        return;
    QSort<T>(a, 1, len);
}

template <typename T>
void SimpleSelectSort(T a[], int len) {
    if(a == NULL || len <= 0) 
        return;
    int min_pos=0;
    for(int i=1; i<len; ++i) {
        min_pos = i;
        for(int j=i+1; j<=len; ++j) {
            if(a[min_pos] > a[j])
                min_pos = j;
        }
        if(min_pos != i) {
            a[i] ^= a[min_pos];
            a[min_pos] ^= a[i];
            a[i] ^= a[min_pos];
        }
    }
}

// Following is Heap Sort code.
void MaxHeapAdjust(int a[], int len, int root_pos) {
    if(!a || len <=0 || root_pos<1 || root_pos>len) 
        throw ERROR;
    if(2*root_pos > len)
        return;
    else if(2*root_pos+1 > len && a[root_pos] < a[2*root_pos]) 
        my_swap(a[root_pos], a[2*root_pos]);
    else {
        int max_pos = a[root_pos*2] > a[root_pos*2+1] ? root_pos*2:root_pos*2+1;
        my_swap(a[root_pos], a[max_pos]);
        MaxHeapAdjust(a, len, max_pos);  //Actually there's a more elegant  way, instead of recursion for heap adjust, see MaxHeapAdjust_v2 following.
    }
}
void MaxHeapAdjust_v2(int a[], int len, int root_pos) {
    if(!a || len <= 0 || root_pos < 1 || root_pos > len) 
        return;
    int prev_pos = root_pos;
    a[0] = a[root_pos];
    for(int max_pos=2*root_pos; max_pos <= len; max_pos *= 2) {
        if(max_pos<len && a[max_pos+1]>a[max_pos])
            max_pos++;
        if(a[0] > a[max_pos])
            break;
        a[prev_pos] = a[max_pos];
        prev_pos = max_pos;
    }
    a[prev_pos] = a[0];
}
void MaxHeapSort(int a[], int len) {
    if(!a || len <= 0)
        return;
    //build max heap
    for(int r=len/2; r>=1; --r) {
        MaxHeapAdjust(a, len, r);
    }
    //maxheap sort
    for(int trans_pos=len; trans_pos > 1; --trans_pos) {
        my_swap(a[1], a[trans_pos]);
        MaxHeapAdjust_v2(a, trans_pos-1, 1);
    }
}
//following is merge sort code
void Merge(int SR[], int TR[], int start, int mid, int end) {
    int p1=start, p2=mid+1, tr_pos=start;
    for(; p1<=mid && p2 <= end; ++tr_pos) {
        if(SR[p1] <= SR[p2]) TR[tr_pos] = SR[p1++];
        else
            TR[tr_pos] = SR[p2++];
    }
    while(p1 <= mid) {
        TR[tr_pos++] = SR[p1++];
    }
    while(p2 <= end) {
        TR[tr_pos++] = SR[p2++];
    }
}
void MSort(int SR[], int TR[], int start, int end) {
    if(!SR || start > end)
        throw ERROR;
    if(start == end)
        TR[start] = SR[start];
    else if(start < end) {
        int mid = (start + end)/2;
        MSort(TR, SR, start, mid);
        MSort(TR, SR, mid+1, end);
        Merge(SR, TR, start, mid, end);
    }
}
void MergeSort(int a[], int len) {
    if(!a || len < 1)
        return;
    int *buf = new int[len+1];
    for(int i=0; i <= len; ++i)
        buf[i] = a[i];
    MSort(buf, a, 1, len);
}
//following is non-recursive version
void MergeSort2(int a[], int len) {
    if(!a || len <= 1)
        return;
    int *buf = new int[len+1];
    for(int i=0; i <= len; ++i)
        buf[i] = a[i];
    int step=1;
    int *b1=a, *b2=buf;
    while(step < len) {
        my_swap(b1, b2);
        for(int start=1; start+step <= len; start+=step*2) {
            int s = start, m = start + step - 1, h = start + step*2 - 1 <= len ? start+step*2-1 : len;
            int t1 = s, t2 = m + 1, t_pos = s;
            for(; t1 <= m && t2 <= h;) {
                if(b1[t1] <= b1[t2])
                    b2[t_pos++] = b1[t1++];
                else
                    b2[t_pos++] = b1[t2++];
            }            
            while(t1<=m)
                b2[t_pos++] = b1[t1++];
            while(t2<=h)
                b2[t_pos++] = b1[t2++];

        }
        step *= 2;
    }
    if(b2 != a)
        for(int i=0; i <= len; ++i)
            a[i] = b2[i];
}
