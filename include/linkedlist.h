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

enum CONSTRUT_TYPE{
    head_type = 0,
    tail_type = 1,
};

template <class T>
struct Node{
    T value;
    Node<T> * next;
    bool visited;
    Node(const T & data) : value(data), next(NULL), visited(false){}
};

template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &linked_list);
    LinkedList<T>& operator = (const LinkedList<T> linked_list);
    void create(vector<T>& value, enum  CONSTRUT_TYPE type);
    void destroy();
    void print() const;
    void print(Node<T>* head) const;

    void reverse(Node<T>* head);
    Node<T> *reverse_recursive_method1(Node<T>* head,Node<T>* prev);
    Node<T> *reverse_recursive_method2(Node<T>* head);
    Node<T> *reverse_by_K(Node<T>* head, Node<T> *prev, const int K);
    void reverse_print(Node<T>* head);

    void create_recurrent_list(Node<T>* head);
    void josephus_ring(Node<T> *head, const int num);

public:
    Node<T> *head_m;

};

template class LinkedList<std::string>;
template class LinkedList<int>;
#endif //ALGORITHMS_LINKEDLIST_H
