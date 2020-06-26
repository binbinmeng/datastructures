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

enum CONSTRUTE_TYPE{
    head_type = 0,
    tail_type = 1,
};

template <class T>
struct Node{
    T value;
    Node<T> * next;
    Node(const T & data) : value(data), next(NULL){}
};

template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &linked_list);
    LinkedList<T>& operator = (const LinkedList<T> linked_list);
    void create(vector<T>& value, enum  CONSTRUTE_TYPE type);
    void destroy();
    void print() const ;

    void reverse(Node<T>* head);

    void create_recurrent_list(Node<T>* head);

public:
    Node<T> *head_m;

};

template class LinkedList<std::string>;
template class LinkedList<int>;
#endif //ALGORITHMS_LINKEDLIST_H
