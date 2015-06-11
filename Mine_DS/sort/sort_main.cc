#include "sorts.cc"

int main() {
    int a[] = {0,4,8,6,2,0,8,-9,234,8};  //for convenience, the first element will not be used
//    int a[] = {0,3,1,2};
    int a_len = sizeof(a)/sizeof(int)-1;
    try {
//    SimpleInsertSort<int>(a, a_len, comp_int);
//    BinaryInsertSort<int>(a, a_len, comp_int);
//    BubbleSort_v2(a, a_len, comp_int);
//    QuickSort(a, a_len);
//        SimpleSelectSort(a, a_len);
        MaxHeapSort(a, a_len);
//        MergeSort(a, a_len);
//        MergeSort2(a, a_len);
    }catch(int e){
        if(e == ERROR)
            cout << "The sort function occured some pre-defined error." << endl;
    }
    print(a+1, a_len);
}
