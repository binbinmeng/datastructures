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

    stack<TreeNode<string>*> nodes;
    bt.allPaths_recursive(bt.root, nodes);
    std::cout<<nodes.size()<<std::endl;

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

    LinkedList<std::string> str_list;
    str_list.create(values, CONSTRUT_TYPE::head_type);
    str_list.print();

    str_list.reverse(str_list.head_m);
    str_list.print();

    //str_list.create_recurrent_list(str_list.head_m);
    //str_list.print();
    str_list.reverse_by_K(str_list.head_m,1);
    str_list.print();
}
int main() {

    //test_binarytree();

    //test_ndarray();

    test_list();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
