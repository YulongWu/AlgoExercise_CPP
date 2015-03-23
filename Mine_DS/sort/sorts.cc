// input: a[0] will not be used to store value, a[len] will store the last value.
#define ERROR -1
#include <cstddef>

void swap(int &v1, int &v2) {
    v1 ^= v2;
    v2 ^= v1;
    v1 ^= v2;
}
template <typename T>
void swap(T &v1, T &v2) {
    T p = v1;
    v1 = v2;
    v2 = p;
}
template <typename T>
void SimpleInsertSort(T a[], int len, int (*comp)(T, T)) {
    if(a == NULL || len <= 0)
        return;
    for(int i=2; i<=len; ++i) {
        if(comp(a[i], a[i-1]) < 0) {  //***an improve which easy to forget
            a[0] = a[i];
            int j=i;
            for(; comp(a[j-1],a[0])>0 && j>1; --j) {
                a[j] = a[j-1];
            }
            a[j] = a[0];
        }
    }
}

template <typename T>
void BinaryInsertSort(T a[], int len, int (*comp)(T, T)) {
    if(a == NULL || len <= 0)
        return;
    for(int i=2; i<=len; ++i) {
        if(comp(a[i], a[i-1]) < 0) {
            int low = 1, high = i-1;
            while(low <= high) {  //*don't forget "="
                int mid = (low+high)/2;
                if(comp(a[i], a[mid]) >= 0)  //***in order to make sort stable, we should merge bigger and equal together.
//** It's a[i] >= a[mid], not a[mid] >= a[i]!
                    low = mid+1;
                else
                    high = mid-1;
            }
            a[0] = a[i];
            for(int j=i-1; j > high; --j) {
                a[j+1] = a[j];
            }
            a[high+1] = a[0];
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
// Following is Quick Sort code.
template <typename T>
void QSort(T a[], int start, int end) {
    if(start < end) {
        int split = Partition<T>(a, start, end);
        QSort(a, start, split-1);
        QSort(a, split+1, end);
    }
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
    else if(2*root_pos+1 > len) {
        if(a[root_pos] < a[2*root_pos]) {
            swap(a[root_pos], a[2*root_pos]);
            MaxHeapAdjust(a, len, 2*root_pos);
        }
    }
    else {
        int max_pos = a[root_pos*2] > a[root_pos*2+1] ? root_pos*2:root_pos*2+1;
        swap(a[root_pos], a[max_pos]);
        MaxHeapAdjust(a, len, max_pos);  //Actually there's a more beautiful way instead of recursion for heap adjust, see MaxHeapAdjust2 following.
    }
}
void MaxHeapAdjust2(int a[], int len, int root_pos) {
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
        MaxHeapAdjust2(a, len, r);
    }
    //maxheap sort
    for(int trans_pos=len; trans_pos > 1; --trans_pos) {
        swap(a[1], a[trans_pos]);
        MaxHeapAdjust2(a, trans_pos-1, 1);
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
        swap(b1, b2);
        for(int start=1; start+step <= len; start+=step*2) {
            int s = start, m = start + step - 1, h = start + step*2 - 1 <= len ? start+step*2-1 : len;
            int t1 = s, t2 = m + 1, t_pos = s;
            for(;t1<=m && t2 <= h;) {
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
