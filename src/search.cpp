//
// Created by binbinm on 2021/8/11.
//

#include "search.h"

template<class T>
SearchFactory<T>::SearchFactory() {

}

template<class T>
SearchFactory<T>::SearchFactory(T *data, int num) {
    NUM = num;
    array = data;
}

template<class T>
bool SearchFactory<T>::BinarySearch(const T &value, int start, int end) {

    int middle_index = (start + end) / 2;
    if (value == array[middle_index]) {
        std::cout << "find value " << value << ", which index is " << middle_index << std::endl;
        return true;
    }
    if (value < array[start] || value > array[end]) {
        std::cout << "can't find value " << value << std::endl;
        return false;
    }
    if (value > array[middle_index]) {
        BinarySearch(value, middle_index + 1, end);
    }
    if (value < array[middle_index]) {
        BinarySearch(value, 0, middle_index - 1);
    }

}

template<class T>
void SearchFactory<T>::Print() {

}
