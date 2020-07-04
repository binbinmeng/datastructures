//
// Created by binbinm on 2020/6/15.
//

#ifndef ALGORITHMS_LISTSTACK_H
#define ALGORITHMS_LISTSTACK_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T>* next;
    Node(T &data) :value(data),next(NULL){}
};

template<typename T>
class ListStack {
public:
    ListStack(){
        head = NULL;
        top_pointer = head;
    }
    ~ListStack(){}
    ListStack<T> operator = (const ListStack<T>&){}
    ListStack(const ListStack<T>&){}

    void pop() const;
    Node<T>& top()const;
    void push(Node<T>& node);

private:
    Node<T>* head;
    Node<T>* top_pointer;
};

template class ListStack<string>;
template class ListStack<int>;

#endif //ALGORITHMS_LISTSTACK_H
