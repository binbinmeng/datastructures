//
// Created by binbinm on 2020/6/13.
//

#ifndef ALGORITHMS_BINARYTREE_HPP
#define ALGORITHMS_BINARYTREE_HPP
#include <iostream>
#include "string"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "assert.h"
using namespace std;

template <class T>
struct TreeNode{
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

enum VISIT_TYPE{
  pre_recursive = 0,
  in_recursive = 1,
  post_recursive = 2,
  pre_unrecursive = 3,
  in_unrecursive = 4,
  post_unrecursive = 5,
  level_unrecursive =6,
};

template <class T>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    bool createTree(const vector<T> &nodeValues);

    void visitTree(enum VISIT_TYPE);

private:
    TreeNode<T>* root;

    void preOrder_recursive(TreeNode<T>* root);

};

template class BinaryTree<string>;
template class BinaryTree<int>;

#endif //ALGORITHMS_BINARYTREE_HPP
