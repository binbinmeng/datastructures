#include <iostream>
#include "binarytree.hpp"

void test_binarytree(){
    std::vector<std::string> values;
    values.push_back("A");
    values.push_back("B");
    values.push_back("C");
    values.push_back("D");
    values.push_back("E");
    values.push_back("F");

    BinaryTree<string> bt;
    bt.createTree(values);
    //bt.visitTree(VISIT_TYPE::pre_recursive);
}
int main() {

    test_binarytree();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
