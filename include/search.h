//
// Created by binbinm on 2021/8/11.
//

#ifndef SRC_SEARCH_H
#define SRC_SEARCH_H

#include <iostream>

using namespace std;

template<class T>
class SearchFactory {
public:
    SearchFactory();

    SearchFactory(T *data, int num);

    bool BinarySearch(const T &value, int start, int end);

    void Print();

private:
    int NUM;
    T *array;


};

template
class SearchFactory<int>;

#endif //SRC_SEARCH_H
