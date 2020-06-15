//
// Created by binbinm on 2020/6/15.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H
#include <iostream>
#include "string.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include <set>
#include "assert.h"
using namespace std;

template <class T>
struct Node{
    T value;
    Node<T> * next;
    Node(const T & data) : value(data), next(NULL){}
};

template <class T>
class LinkedList {
public:
    void create();
    void destroy();

private:
    Node<T> head;

};

template class LinkedList<std::string>;
template class LinkedList<int>;
#endif //ALGORITHMS_LINKEDLIST_H
