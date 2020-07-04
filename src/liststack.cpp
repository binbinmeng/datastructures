//
// Created by binbinm on 2020/6/15.
//

#include "liststack.h"

template<class T>
void ListStack<T>::pop()const{
    if(top_pointer!=NULL){

    }
}

template<class T>
Node<T>& ListStack<T>::top()const{

}

template<class T>
void ListStack<T>::push(Node<T>& node){
    top_pointer->next = &node;
    top_pointer = top_pointer->next;
}

