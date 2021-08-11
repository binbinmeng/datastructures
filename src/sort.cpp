#include "sort.h"

template<class T>
SortFactory<T>::SortFactory() {
}

template<class T>
SortFactory<T>::SortFactory(T *data, int num) {
    NUM = num;
    array = data;
}

template<class T>
void SortFactory<T>::InsertSort() {
    for (int k = 0; k < NUM - 1; ++k) {
        for (int t = k; t >= 0; --t) {
            if (array[t] > array[t + 1]) {
                int temp;
                temp = array[t];
                array[t] = array[t + 1];
                array[t + 1] = temp;
            }
        }
    }
}

template<class T>
void SortFactory<T>::BublleSort() {
    for (int k = 0; k < NUM; ++k) {
        for (int t = 0; t < NUM - k; ++t) {
            if (array[t] > array[t + 1]) {
                int temp;
                temp = array[t];
                array[t] = array[t + 1];
                array[t + 1] = temp;
            }
        }
    }
}

template<class T>
void SortFactory<T>::Print() {
    for (int k = 0; k < NUM; ++k) {
        std::cout << array[k] << " | ";
    }
    std::cout << std::endl;
}

template<class T>
void SortFactory<T>::QuickSort() {

}

template<class T>
void SortFactory<T>::MergeSort() {

}
