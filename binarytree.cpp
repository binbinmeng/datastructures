//
// Created by binbinm on 2020/6/13.
//

#include "binarytree.h"

template <class T>
BinaryTree<T>::BinaryTree(){

}

template <class T>
BinaryTree<T>::~BinaryTree(){

}

template <class T>
bool BinaryTree<T>::createTree(const vector<T> &nodeValues) {
    /*
     * 利用层序遍历创建二叉树
     */
    if(nodeValues.size() == 0){
        assert(nodeValues.size() != 0);
        return false;
    }

    root = new TreeNode<T>();//创建第一个root节点对象
    int index = 0;
    root->value = nodeValues[index];
    root->left = NULL;
    root->right = NULL;

    queue<TreeNode<T>*> Q;
    Q.push(root);

    while(index < nodeValues.size()){

        TreeNode<T>* front_node = Q.front();

        if(front_node != NULL){
            front_node->left = new TreeNode<T>();//创建左节点对象
            front_node->left->value = nodeValues[++index];
            front_node->left->left = NULL;
            front_node->left->right = NULL;
            Q.push(front_node->left);//左节点入队

            front_node->right = new TreeNode<T>();//创建右节点对象
            front_node->right->value = nodeValues[++index];
            front_node->right->left = NULL;
            front_node->right->right = NULL;
            Q.push(front_node->right);//右节点入队
        }

        Q.pop();//队头，即root节点出队
    }
    return true;
}

template <class T>
void BinaryTree<T>::visitTree(enum VISIT_TYPE type) {
    switch (type) {
        case 0:
            preOrder_recursive(root);
            break;
        case 1:
            inOrder_recursive(root);
            break;
        case 2:
            postOrder_recursive(root);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            level_unrecursive(root);
            break;
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
template <class T>
void BinaryTree<T>::inOrder_recursive(TreeNode<T> *root) {
    if(root == NULL)
        return;

    inOrder_recursive(root->left);
    std::cout<<root->value<<std::endl;
    inOrder_recursive(root->right);
}

template <class T>
void BinaryTree<T>::postOrder_recursive(TreeNode<T> *root) {
    if(root == NULL)
        return;

    postOrder_recursive(root->left);
    postOrder_recursive(root->right);
    std::cout<<root->value<<std::endl;
}

template <class T>
void BinaryTree<T>::level_unrecursive(TreeNode<T> *root) {
    if(root == NULL)
        return;

    queue<TreeNode<T>*> Q;
    Q.push(root);

    while(!Q.empty()) {
        TreeNode<T> *front_node = Q.front();
        std::cout << front_node->value << std::endl;

        if (front_node->left) {
            //std::cout << front_node->left->value << std::endl;
            Q.push(front_node->left);
        }
        if (front_node->right) {
            //std::cout << front_node->right->value << std::endl;
            Q.push(front_node->right);
        }

        Q.pop();
    }
}

template <class T>
void BinaryTree<T>::preOrder_unrecursive(TreeNode<T> *root) {

}

template <class T>
void BinaryTree<T>::inOrder_unrecursive(TreeNode<T> *root) {

}

template <class T>
void BinaryTree<T>::postOrder_unrecursive(TreeNode<T> *root) {

}

template <class T>
int BinaryTree<T>::getHight(TreeNode<T> *root) {
    if(root == NULL)
        return 0;

    int left_height = getHight(root->left);
    int right_height = getHight(root->right);

    return max(left_height,right_height)  + 1;
}

template <class T>
void BinaryTree<T>::imageTree(TreeNode<T> *root) {

}

