#include "linkedlist.h"

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(Node<T> *node)
{
    head = node;
}

template <class T>
LinkedList<T>::LinkedList(T *elements, int num)
{
    if (elements == NULL)
        return;

    head = new Node<T>(elements[0]);
    Node<T> *p = head;

    for (int k = 1; k < num; ++k)
    {
        Node<T> *node = new Node<T>(elements[k]);
        p->next = node;
        p = p->next;
    }
}

template <class T>
void LinkedList<T>::Reverse()
{
    switch (2)
    {
    case 1: /*focus on post pointer!*/
    {
        Node<T> *pre = NULL;
        Node<T> *cur = head;
        Node<T> *post = head->next;

        while (post != NULL)
        {
            cur->next = pre;
            pre = cur;
            cur = post;
            post = post->next;
        }

        cur->next = pre;
        head = cur;
    }
    break;

    case 2: /*focus on cur pointer!*/
    {
        Node<T> *pre = NULL;
        Node<T> *cur = head;
        Node<T> *post = head;
        while (cur != NULL)
        {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        head = pre;
    }
    break;

    default:
        break;
    }

    return;
}

template <class T>
void LinkedList<T>::Reverse(Node<T> *start_node, Node<T> *end_node)
{
}

template <class T>
void LinkedList<T>::Reverse(int step)
{
    Reverse();
}

template <class T>
void LinkedList<T>::JosephusRing(int k)
{
    if (head != NULL)
    {
        Node<T> *p = head;
        while (p->next != p)
        {
            for (int step = 1; step < k - 1; ++step)
            {
                p = p->next;
            }
            Node<T> *temp = p->next;
            std::cout << temp->data << " -> ";
            p->next = temp->next;
            p = p->next;
        }
        std::cout << p->data << std::endl;
    }
    return;
}

template <class T>
void LinkedList<T>::Print()
{
    if (head == NULL)
    {
        return;
    }
    Node<T> *p = head;
    while (p != NULL)
    {
        std::cout << p->data << " -> ";
        p = p->next;
    }
    std::cout << " NULL " << std::endl;
    return;
}
