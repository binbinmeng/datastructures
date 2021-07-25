#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node() {}
    Node(const T &data) : data(data), next(NULL) {}
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(Node<T> *node);
    LinkedList(T *elements, int num);

    /*common algorithms*/
    void Reverse();
    void Reverse(Node<T> *start_node, Node<T> *end_node);
    void Reverse(int step);

    void JosephusRing(int k);

    void Print();

private:
    Node<T> *head;
};

template class LinkedList<int>;

#endif // LINKEDLIST_H
