//
// Created by binbinm on 2020/6/14.
//

#include "ndarray.h"

template <class T>
NDArray<T>::NDArray() {

}

template <class T>
NDArray<T>::~NDArray() {

}

template <class T>
bool NDArray<T>::create(vector<vector<T> >& array) {
    row = array.size();
    col = array.begin()->size();
    std::cout<<"row = "<<row<<","
               "col = "<<col<<
    std::endl;

    m_array = array;
}

template <class T>
void NDArray<T>::print() {
    for(int k=0; k<row; ++k){
        for(int l=0; l<col; ++l){
            std::cout<<m_array[k][l]<<" | ";
        }
        std::cout<<std::endl;
    }
}
template <class T>
bool NDArray<T>::find_target() {

}

template <class T>
int NDArray<T>::numIslands() {

}

template <class T>
void NDArray<T>::find_topk() {

}

template <class T>
bool NDArray<T>::word_searh() {

}

template <class T>
void NDArray<T>::print_Z() {

}

template <class T>
void NDArray<T>::F() {

}