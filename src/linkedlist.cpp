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
void LinkedList<T>::create(vector<T>& value,enum  CONSTRUT_TYPE type) {
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

    Node<T> *cur = head_m;
    Node<T> *post = cur->next;
    Node<T> *pre = NULL;
    switch (1) {
        /* 利用head指针作，动态调整指向拆分前后两个list，p,q分别指向前后两个指针的头部节点
          input: A->B->C->D->E->F->NULL
          NULL(pre) A(cur)->B(post)->C->D->E->F->NULL
          NULL<-A(pre)  B(cur)->C(post)->D->E->F->NULL
          NULL<-A<-B(pre) C(cur)->D(post)->E->F->NULL
        */
        case 1: {
            while (post->next != NULL) {
                cur->next = pre;
                pre = cur;
                cur = post;
                post = post->next;
            }
            /*when NULL<-A<-B<-C<-D(pre)  E(cur)->F(post)->NULL do following:*/
            cur->next = pre;
            post->next = cur;
            head_m = post;
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
            while (cur != NULL) {
                cur->next = post->next;
                post->next = head_m;
                head_m = post;
                post = cur->next;
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

template <class T>
void LinkedList<T>::reverse_by_K(Node<T> *head, const int K) {
    if(head == NULL)
        return;
    Node<T> *p = head_m;
    Node<T> *q = p->next;
    int step =0;
    while(p->next != NULL){
        p->next = q->next;
        q->next = head_m;

        head_m = q;
        q = p->next;
        step++;
        if(step == K){

        }
    }
}
