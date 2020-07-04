//
// Created by binbinm on 2020/6/15.
//

#include "linkedlist.h"

template <class T>
LinkedList<T>::LinkedList() {
     head_m = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    if(head_m != NULL)
        delete head_m;
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

template<class T>
void LinkedList<T>::print(Node<T> *head) const {
    if(head == NULL)
        return;

    Node<T>* p = head;
    while(p != NULL){
        std::cout<<p->value<<" | ";
        p = p->next;
    }
    std::cout<<std::endl;
}

template <class T>
void LinkedList<T>::reverse(Node<T>* head) {
    if (head_m == NULL)
        return ;

    Node<T> *cur = head_m;
    Node<T> *post = cur->next;
    Node<T> *pre = NULL;
    switch (2) {
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
             * 利用一个list, 动态从后面的list的头拿掉，指向最开始（循环指向）,cur 指针的位置不变
             * A(head/p) ->B(q) ->C ->D ->E->F
             * 1. B(head) ->A(p) ->C(q) ->D ->E ->F
             * 2. C(head) ->B ->A(p) ->D(q) ->E ->F
             * 3. D(head) ->C ->B ->A(p) ->E(q) ->F
             * 4. E(head) ->D ->C(p) ->B(q) ->A(p) ->F(q)
             */
            while (post != NULL) {
                cur->next = post->next;
                post->next = head_m;
                head_m = post;
                post = cur->next;
            }
            break;
        }
        case 3:{
            head_m = reverse_recursive_method1(head,NULL);
            break;
        }
        default:
            break;
    }
}

template<class T>
Node<T> * LinkedList<T>::reverse_recursive_method1(Node<T> *head, Node<T> *prev) {
    /*
     * 如何理解？首先看递归条件就是剩余最后两个元素时，完成反向指向动作，返回最后一个元素（结束时的head指向元素），
     * 它就是递归函数返回值的last,即last指向元素就是原来列表最后一个元素
     * 依次回溯操作：后一个元素指向前一个元素
     */
    if(head->next == NULL){
        head->next = prev;
        return head;
    }

    Node<T> *last = reverse_recursive_method1(head->next,head);
    head->next = prev;
    return last;
}

template<class T>
Node<T> * LinkedList<T>::reverse_recursive_method2(Node<T> *head) {
    if(head->next == NULL){
        return head;
    }

    Node<T> *prev = head;//record history node
    Node<T> * cur = head->next;
    Node<T> *last = reverse_recursive_method2(cur);
    cur->next = prev;//current node 指向 history node
    head->next = NULL; //last step
    return last;
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
Node<T> * LinkedList<T>::reverse_by_K(Node<T> *head, Node<T> *prev, const int K) {

}

template<class T>
void LinkedList<T>::josephus_ring(Node<T> *head, const int num) {
    if(head == NULL)
        return;

    Node<T> * p = head;
    while(p->next != p){
        for(int k=0; k<num-1; ++k){
            p=p->next;
        }
        Node<T> *temp = p->next;
        p->next = p->next->next;
        std::cout<<temp->value<<" | ";
        delete temp;
        p=p->next;
    }
    std::cout<<p->value<<std::endl;
    std::cout<<"last node is "<<p->value<<std::endl;
    delete p;
}
