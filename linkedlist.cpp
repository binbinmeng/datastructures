//
// Created by binbinm on 2020/6/15.
//

#include "linkedlist.h"

template <class T>
LinkedList<T>::LinkedList() {

}

template <class T>
LinkedList<T>::~LinkedList() {
    //destroy();
}

template <class T>
void LinkedList<T>::create(vector<T>& value,enum  CONSTRUTE_TYPE type) {
    if(value.size() == 0)
        return;
    switch (type) {
        case head_type:{
            Node<T>* head = new Node<T>(value[value.size()-1]);
            Node<T>* p;
            for(int k=value.size()-2; k>=0; --k){
                p = new Node<T>(value[k]);
                p->next = head;
                head = p;
            }
            head_m = head;
            std::cout<<"finish head type construction"<<std::endl;
            break;
        }
        case tail_type:{
            Node<T>* head = new Node<T>(value[0]);
            Node<T>* p = head;
            for(int k=1; k<value.size(); ++k){
                Node<T>* node = new Node<T>(value[k]);
                p->next = node;
                p = p->next;
            }
            head_m = head;
            std::cout<<"finish tail type construction"<<std::endl;
            break;
        }
    }
}
template <class T>
void LinkedList<T>::print() const {
    if(head_m == NULL)
        return;

    Node<T>* p = head_m;
    while(p != NULL){
        std::cout<<p->value<<" | ";
        p = p->next;
    }
    std::cout<<std::endl;
}

template <class T>
void LinkedList<T>::reverse(Node<T>* head) {
    if (head_m == NULL)
        return;

    Node<T> *p = head_m;
    Node<T> *q = p->next;
    switch (1) {
        /* 利用head指针作，动态调整指向拆分前后两个list，p,q分别指向前后两个指针的头部节点
        * A ->B ->C ->D ->E->F
        * 1: A(head/p) ->B(q) ->C ->D ->E ->F
        * 2: A(head/p) | B(q) ->C ->D ->E- >F
        * 3: A(head) | B(p) ->C(q) ->D ->E- >F
        * 4: A(head)<- B(p) | C(q) ->D ->E ->F
        * 5: A<- B(head) | C(p) ->D(q) ->E ->F
        * 6: A<- B(head)<- C(p) | D(q) ->E ->F
        * 7: A<- B<- C(head) | D(p) ->E(q) ->F
        */
        case 1: {
            head_m->next = NULL;
            p = q;
            q = q->next;
            std::cout<<"finish processing first node"<<std::endl;

            while (q != NULL) {
                p->next = head_m;
                head_m = p;
                p = q;
                q = q->next;
            }
            p->next = head_m;
            head_m = p;
            std::cout<<"finish processing last node"<<std::endl;
            break;
        }
        case 2: {
            /*
             * 利用一个list, 动态从后面的list的头拿掉，指向最开始（循环指向）,p 指针的位置不变
             * A(head/p) ->B(q) ->C ->D ->E->F
             * 1. B(head) ->A(p) ->C(q) ->D ->E ->F
             * 2. C(head) ->B ->A(p) ->D(q) ->E ->F
             * 3. D(head) ->C ->B ->A(p) ->E(q) ->F
             * 4. E(head) ->D ->C(p) ->B(q) ->A(p) ->F(q)
             */
            while (q != NULL) {
                p->next = q->next;
                q->next = head_m;
                head_m = q;
                q = p->next;
            }
            break;
        }
    }
}

template <class T>
void LinkedList<T>::create_recurrent_list(Node<T>* head) {
    Node<T>* p = head_m;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = head_m;
}

template <class T>
void LinkedList<T>::destroy() {
    if(head_m != NULL){
        while(head_m != NULL){
            Node<T>* temp = head_m;
            head_m = head_m->next;
            delete temp;
        }
    }
}