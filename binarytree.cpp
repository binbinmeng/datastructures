//
// Created by binbinm on 2020/6/13.
//

#include "binarytree.h"

template <class T>
BinaryTree<T>::BinaryTree(){
    root = new TreeNode<T>();
}

template <class T>
BinaryTree<T>::~BinaryTree(){

}

template <class T>
bool BinaryTree<T>::createTree(const vector<T> &nodeValues) {
    if(nodeValues.size() == 0){
        assert(nodeValues.size() != 0);
        return false;
    }

    int index = 0;

    root->value = nodeValues[index];
    root->left = NULL;
    root->right = NULL;

    queue<TreeNode<T>*> Q;
    Q.push(root);

    while(index < nodeValues.size()){

        TreeNode<T>* front_node = Q.front();

        if(front_node != NULL){
            front_node->left = new TreeNode<T>();
            front_node->left->value = nodeValues[++index];
            front_node->left->left = NULL;
            front_node->left->right = NULL;
            Q.push(front_node->left);

            front_node->right = new TreeNode<T>();
            front_node->right->value = nodeValues[++index];
            front_node->right->left = NULL;
            front_node->right->right = NULL;
            Q.push(front_node->right);
        }
        Q.pop();
    }
    return true;
}

template <class T>
void BinaryTree<T>::visitTree(enum VISIT_TYPE type) {
    switch (type) {
    case 0:
        preOrder_recursive(root);
    }
}
template <class T>
void BinaryTree<T>::preOrder_recursive(TreeNode<T> *root) {
    if(root == NULL)
        return;

    std::cout<<root->value<<std::endl;
    preOrder_recursive(root->left);
    preOrder_recursive(root->right);
}