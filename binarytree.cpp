//
// Created by binbinm on 2020/6/13.
//

#include "binarytree.hpp"

template <class T>
BinaryTree<T>::BinaryTree() {

}

template <class T>
BinaryTree<T>::~BinaryTree(){

}

template <class T>
bool BinaryTree<T>::createTree(const vector<T> &nodeValues) {
    if(nodeValues.size()){
        root = NULL;
        assert(nodeValues.size() != 0);
    }

    int index = 0;
    root->value = nodeValues[index];
    root->left = NULL;
    root->right = NULL;

    queue<TreeNode<T>*> Q;
    Q.push(root);

    while(index < nodeValues.size()){
        TreeNode<T>* front_node = Q.front();
        if(front_node->left){
            front_node->left->value = nodeValues[index++];
            front_node->left->left = NULL;
            front_node->left->right = NULL;
        }
        if(front_node->right){
            front_node->right->value = nodeValues[index++];
            front_node->right->left = NULL;
            front_node->right->right = NULL;
        }
    }
    return true;
}

template <class T>
void BinaryTree<T>::preOrder_recursive(TreeNode<T> *root) {
    if(root == NULL)
        return;

    std::cout<<root->value<<std::endl;
    BinaryTree<T>(root->left);
    BinaryTree<T>(root->right);
}