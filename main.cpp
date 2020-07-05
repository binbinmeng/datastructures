//
// Created by binbinm on 2020/7/4.
//

#include <iostream>
#include "binarytree.h"
#include "ndarray.h"
#include "linkedlist.h"

void test_binarytree(){

    std::vector<std::string> values;
    values.push_back("A");
    //values.push_back("#");
    values.push_back("B");
    values.push_back("C");
    //values.push_back("#");
    values.push_back("D");
    //values.push_back("#");
    values.push_back("E");
    //values.push_back("#");
    values.push_back("F");

    BinaryTree<string> bt;
    bt.createTree(values, "#");


    std::cout << "pre order recursive visit !" << std::endl;
    bt.visitTree(VISIT_TYPE::pre_recursive);

    std::cout << "in order recursive visit !" << std::endl;
    bt.visitTree(VISIT_TYPE::in_recursive);

    std::cout << "post order recursive visit !" << std::endl;
    bt.visitTree(VISIT_TYPE::post_recursive);

    std::cout << "level unrecursive visit !" << std::endl;
    bt.visitTree(VISIT_TYPE::level_unrecursive);

    std::cout << "pre order unrecursive visit !" << std::endl;
    bt.visitTree(VISIT_TYPE::pre_unrecursive);

    std::cout << "in order unrecursive visit !" << std::endl;
    bt.visitTree(VISIT_TYPE::in_unrecursive);

    std::cout << "image tree by recursive:" << std::endl;
    bt.imageTree_recursive(bt.root);
    bt.visitTree(VISIT_TYPE::level_unrecursive);

    std::cout << "image tree by unrecursive:" << std::endl;
    bt.imageTree_unrecursive(bt.root);
    bt.visitTree(VISIT_TYPE::level_unrecursive);

    std::cout << "binary tree height = "<<bt.getHight(bt.root) << std::endl;

    std::vector<std::set<TreeNode<std::string> *>> paths;
    bt.allPaths(bt.root, paths);

    std::cout << "binary tree path = "<<paths.size() << std::endl;
    for(int k=0; k< paths.size(); ++k){
        std::cout << "binary tree path "<<k<<":"<<std::endl ;
        for(typename std::set<TreeNode<string>*>::iterator it=paths[k].begin(); it!=paths[k].end(); it++)
        {
            cout<<(*it)->value<<" | "<<endl;
        }
    }
    std::cout << "binary tree path recursive method = "<< std::endl;
    vector<string> path;
    vector<vector<string>> allpaths;
    bt.allPaths_recursive(bt.root, path, allpaths);
    std::cout<<"path number = "<<allpaths.size()<<std::endl;
    for(int k=0; k<allpaths.size();++k)
    {
        for(int t=0; t<allpaths[k].size();++t){
            std::cout<<allpaths[k][t]<<" | ";
        }
        std::cout<<std::endl;
    }

    std::cout<<bt.is_full_binary_tree(bt.root)<<std::endl;
}

void test_ndarray(){
    /*std::vector<std::vector<std::string>> vec_2d;
    std::string A1[] = { "1","2","3","4","5"};
    vec_2d.push_back(vector<std::string>(A1, A1+5));
    std::string A2[] = { "3","4","5","6","7"};
    vec_2d.push_back(vector<std::string>(A2, A2+5));
    std::string A3[] = { "4","6","7","8","1O"};
    vec_2d.push_back(vector<std::string>(A3, A3+5));

    std::cout<<"########"<<std::endl;
    NDArray<std::string> array;
    array.create(vec_2d);
    array.print();
    vector<std::string> target;
    target.push_back("A");
    target.push_back("B");
    target.push_back("G");
    target.push_back("H");
    target.push_back("M");
    target.push_back("N");
    target.push_back("O");
    bool result = array.word_searh(vec_2d,target);
    std::cout<<result<<std::endl;
*/
    std::vector<std::vector<int>> vec_2d_int;
    int B1[] = { 1, 2, 3, 4, 5};
    vec_2d_int.push_back(vector<int>(B1, B1+5));
    int B2[] = { 3, 4, 5, 6, 7};
    vec_2d_int.push_back(vector<int>(B2, B2+5));
    int B3[] = { 4, 6, 7, 8, 10};
    vec_2d_int.push_back(vector<int>(B3, B3+5));

    NDArray<int> ndarray_int;
    ndarray_int.create(vec_2d_int);
    ndarray_int.print();
    bool isFind = ndarray_int.find_target(vec_2d_int, 1);
    std::cout<<isFind<<std::endl;

}

void test_list(){
    vector<string> values;
    values.push_back("A");
    values.push_back("B");
    values.push_back("C");
    values.push_back("D");
    values.push_back("E");
    values.push_back("F");
    values.push_back("G");
    values.push_back("H");
    values.push_back("I");
    values.push_back("G");

    LinkedList<std::string> str_list;
    str_list.create(values, CONSTRUT_TYPE::head_type);
    str_list.print(str_list.head_m);

    str_list.reverse(str_list.head_m);
    str_list.print(str_list.head_m);

    str_list.reverse_print(str_list.head_m);

    //str_list.create_recurrent_list(str_list.head_m);
    //str_list.josephus_ring(str_list.head_m,2);

    //Node<string> * new_head_1 = str_list.reverse_recursive_method1(str_list.head_m, NULL);
    //str_list.print(new_head_1);

    //Node<string> * new_head_2 = str_list.reverse_recursive_method2(str_list.head_m);
    //str_list.print(new_head_2);

}
int main() {

    test_binarytree();

    //test_ndarray();

    //test_list();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
