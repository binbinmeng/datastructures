#include <iostream>
#include "binarytree.h"

void test_binarytree(){
    std::vector<std::string> values;
    values.push_back("A");
    values.push_back("#");
    values.push_back("B");
    values.push_back("C");
    values.push_back("D");
    values.push_back("E");
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

    std::cout << "binary tree height = "<<bt.getHight(bt.root) << std::endl;
}
int main() {

    test_binarytree();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
