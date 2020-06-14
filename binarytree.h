//
// Created by binbinm on 2020/6/13.
//

#ifndef ALGORITHMS_BINARYTREE_HPP
#define ALGORITHMS_BINARYTREE_HPP
#include <iostream>
#include "string.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include <set>
#include "assert.h"
using namespace std;

template <class T>
struct TreeNode{
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(const T x) : value(x), left(NULL), right(NULL) {}
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

    bool createTree(const vector<T> &nodeValues,const T & empty_node_symbol);

    void visitTree(enum VISIT_TYPE);

    int getHight(TreeNode<T>* root);

    int getWidth(TreeNode<T>* root);

    void imageTree_recursive(TreeNode<T>* root);

    void imageTree_unrecursive(TreeNode<T>* root);

    void allPaths(TreeNode<T> *root, std::vector<std::set<TreeNode<T> *>>& paths);

    void allPaths_recursive(TreeNode<T> *root, stack<TreeNode<T>*> nodes);

    bool is_full_binary_tree(TreeNode<T>* root);

public:
    TreeNode<T>* root;
private:
    void preOrder_recursive(TreeNode<T>* root);
    void inOrder_recursive(TreeNode<T>* root);
    void postOrder_recursive(TreeNode<T>* root);
    void level_unrecursive(TreeNode<T>* root);
    void preOrder_unrecursive_method1(TreeNode<T>* root);
    void preOrder_unrecursive_method2(TreeNode<T>* root);
    void inOrder_unrecursive(TreeNode<T>* root);
    void postOrder_unrecursive(TreeNode<T>* root);

};

template class BinaryTree<std::string>;
template class BinaryTree<int>;


template <class T>
class AVLTree : public BinaryTree<T>{
public:
    AVLTree();
    ~AVLTree();

};

#endif //ALGORITHMS_BINARYTREE_HPP
