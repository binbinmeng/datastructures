#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;

template<class T>
struct TreeNode {
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;
    int visited_num;

    TreeNode(T data) : value(data), left(NULL), right(NULL), visited_num(0) {}
};

template<class T>
class BinaryTree {
public:
    BinaryTree();

    BinaryTree(TreeNode<T> *node);

    void PreOrder();

    void InOrder();

    void PostOrder();

    void LevelOrder();

    int Hight(TreeNode<T> *root);

    void ImageTree(TreeNode<T> *root);

    int SpecificPath(int sum);

    void AllPath();


private:
    TreeNode<T> *root;
};

template
class BinaryTree<int>;

#endif // BINARYTREE_H