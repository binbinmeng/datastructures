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
bool BinaryTree<T>::createTree(const vector<T> &nodeValues, const T & empty_node_symbol) {
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

    while(index < nodeValues.size() - 2 ){ //父节点之后还会有两个节点要访问

        TreeNode<T>* front_node = Q.front();
        std::cout<<index<<" || "<<front_node->value<<std::endl;

        if(front_node != NULL){

            T value_left = nodeValues[++index];
            std::cout<<index<<" | "<<value_left <<std::endl;
            if(value_left  != empty_node_symbol){
                front_node->left = new TreeNode<T>();//创建左节点对象
                front_node->left->value = value_left;
                front_node->left->left = NULL;
                front_node->left->right = NULL;
                Q.push(front_node->left);//左节点入队
            }

            T value_right = nodeValues[++index];
            std::cout<<index<<" | "<<value_right <<std::endl;
            if(value_right != empty_node_symbol){
                front_node->right = new TreeNode<T>();//创建右节点对象
                front_node->right->value = value_right;
                front_node->right->left = NULL;
                front_node->right->right = NULL;
                Q.push(front_node->right);//右节点入队
            }
        }
        Q.pop();//队头，即root节点出队
    }

    std::cout<<"create binary tree seccessfull !"<<std::endl;
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
            preOrder_unrecursive(root);
            break;
        case 4:
            inOrder_unrecursive(root);
            break;
        case 5:
            postOrder_unrecursive(root);
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
            Q.push(front_node->left);
        }
        if (front_node->right) {
            Q.push(front_node->right);
        }

        Q.pop();
    }
}

template <class T>
void BinaryTree<T>::preOrder_unrecursive(TreeNode<T> *root) {
    if(root == NULL)
        return;
    stack<TreeNode<T>*> S;
    S.push(root);

    while(!S.empty()){
        TreeNode<T>* top_node = S.top();
        std::cout << top_node->value << std::endl;
        S.pop(); //访问完父节点，即可弹出栈

        if(top_node->right)
            S.push(top_node->right);
        if(top_node->left)
            S.push(top_node->left);

    }
}

template <class T>
void BinaryTree<T>::inOrder_unrecursive(TreeNode<T> *root) {
    if(root == NULL)
        return;

    stack<pair<TreeNode<T>*, bool>> S;
    S.push(std::make_pair(root, false));

    while(!S.empty()){

        if(S.top().second)
        {
            std::cout << S.top().first->value<< std::endl;
            S.pop();

        }
        else{
            S.top().second = true;

            if(S.top().first->left){
                S.push(make_pair(S.top().first->left, false));
            }
            if(S.top().first->right){
                S.push(make_pair(S.top().first->right, false));
            }

            if((S.top().first->left&&S.top().first->right) == NULL){
                std::cout << S.top().first->value << std::endl;
                S.pop();
            }
        }
    }
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

