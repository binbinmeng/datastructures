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
bool NDArray<T>::find_target(vector<vector<T> >& array, int target) {
    for(int i=0, j=col-1; i<row && j>=0;){
         if(array[i][j] == target){
             std::cout << "find target="<< target <<", i="<<i<<", "<<"j="<<j<< std::endl;
             return true;
         }
         if(array[i][j] < target){
             i++;
             continue;
         }
         if(array[i][j] > target){
             j--;
             continue;
         }
     }
     return false;
}

template <class T>
int NDArray<T>::numIslands(vector<vector<T> >& array) {

}

template <class T>
void NDArray<T>::find_topk(vector<vector<T> >& array, int K) {

}

template <class T>
bool NDArray<T>::word_searh(vector<vector<T> >& array, vector<T> &target) {
    std::cout<<"target size = "<<target.size()<<std::endl;
    /*
     * 只允许右/下
     */
    int i=0,j=0,k=0;
    for(;i<row,j<col,k<target.size();){
        if(array[i][j]==target[k]){/*优先向右遍历匹配*/
            std::cout<<array[i][j]<<" | "<<std::endl;
            j++;
            k++;
        }
        else{/*否则，跳转到下方遍历匹配*/
            j--;
            i++;
        }
    }
    /*
     *
     */

    if(k == target.size()){
        return true;
    }else {
        return false;
    }
}

template <class T>
void NDArray<T>::print_Z() {

}

template <class T>
void NDArray<T>::F() {

}