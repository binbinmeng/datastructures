#ifndef SORT_H
#define SORT_H
#include <iostream>
using namespace std;

template<class T>
class SortFactory{
public:
    SortFactory();
    SortFactory(T *data, int num);
    void InsertSort();
    void BublleSort();
    void QuickSort();
    void MergeSort();

    void Print();

private:
    int NUM;
    T *array;

};

template class SortFactory<int>;
#endif // SORT_H