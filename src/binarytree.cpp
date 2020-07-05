//
// Created by binbinm on 2020/6/13.
//

#include "binarytree.h"

template <class T>
BinaryTree<T>::BinaryTree(){
    LOG();
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    LOG();

}

template <class T>
bool BinaryTree<T>::createTree(const vector<T> &nodeValues, const T & empty_node_symbol) {
    LOG();
    /*
     * 利用层序遍历创建二叉树
     */
    if(nodeValues.empty()){
        root = NULL;
        return false;
    }

    root = new TreeNode<T>(nodeValues[0]);
    std::queue<TreeNode<T> *> Q_nodes;
    Q_nodes.push(root);

    int index = 0;
    while(!Q_nodes.empty() && index < nodeValues.size()){

        TreeNode<T> * leaf = Q_nodes.front();
        Q_nodes.pop();
        index++;
        if(leaf != NULL) {
            if ((nodeValues[index] == empty_node_symbol) || index >= nodeValues.size()) { //  empty node and no data also means empty node
                leaf->left = NULL;
            } else {
                leaf->left = new TreeNode<T>(nodeValues[index]);
            }

            Q_nodes.push(leaf->left);

            index++;
            if ((nodeValues[index] == empty_node_symbol) || index >= nodeValues.size()) { //  empty node and no data also means empty node
                leaf->right = NULL;
            } else {
                leaf->right = new TreeNode<T>(nodeValues[index]);
            }

            Q_nodes.push(leaf->right);
        }
    }
    return true;
}

template <class T>
void BinaryTree<T>::visitTree(enum VISIT_TYPE type) {
    LOG();
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
        case 3:{
            std::cout<<"method1 :"<<std::endl;
            preOrder_unrecursive_method1(root);
            std::cout<<"method2 :"<<std::endl;
            preOrder_unrecursive_method2(root);
            break;
        }
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
    LOG();
    if(root == NULL)
        return;

    std::cout<<root->value<<std::endl;
    preOrder_recursive(root->left);
    preOrder_recursive(root->right);
}
template <class T>
void BinaryTree<T>::inOrder_recursive(TreeNode<T> *root) {
    LOG();
    if(root == NULL)
        return;

    inOrder_recursive(root->left);
    std::cout<<root->value<<std::endl;
    inOrder_recursive(root->right);
}

template <class T>
void BinaryTree<T>::postOrder_recursive(TreeNode<T> *root) {
    LOG();
    if(root == NULL)
        return;

    postOrder_recursive(root->left);
    postOrder_recursive(root->right);
    std::cout<<root->value<<std::endl;
}

template <class T>
void BinaryTree<T>::level_unrecursive(TreeNode<T> *root) {
    LOG();
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
void BinaryTree<T>::preOrder_unrecursive_method1(TreeNode<T> *root) {
    LOG();
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
void BinaryTree<T>::preOrder_unrecursive_method2(TreeNode<T> *root) {
    LOG();
    if(root == NULL)
        return;
    stack<TreeNode<T>*> S;
    TreeNode<T>* current_node = root;

    while(current_node != NULL || !S.empty()){

        while(current_node != NULL){
            S.push(current_node);
            std::cout<<current_node->value<<std::endl;
            current_node = current_node->left;
        }

        if(!S.empty()){
            current_node = S.top();
            S.pop();
            current_node = current_node->right;
        }
    }
}

template <class T>
void BinaryTree<T>::inOrder_unrecursive(TreeNode<T> *root) {
    LOG();
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

            if(S.top().first->left == NULL){
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
    LOG();
    if(root == NULL)
        return 0;

    int left_height = getHight(root->left);
    int right_height = getHight(root->right);

    return max(left_height,right_height)  + 1;
}

template <class T>
void BinaryTree<T>::imageTree_recursive(TreeNode<T> *root) {
    LOG();
    if(root == NULL)
        return;

    if(root->left || root->right){
        swap(root->left, root->right);
    }

    imageTree_recursive(root->left);
    imageTree_recursive(root->right);
}

template <class T>
void BinaryTree<T>::imageTree_unrecursive(TreeNode<T> *root) {
    LOG();
    if(root == NULL)
        return;

    queue<TreeNode<T>*> Q;
    Q.push(root);

    while(!Q.empty()){

        TreeNode<T>* front_node = Q.front();
        if(front_node){
            if(front_node->left || front_node->right){
                swap(front_node->left, front_node->right);
                Q.push(front_node->left);
                Q.push(front_node->right);
            }
        }
        Q.pop();
    }
}

template <class T>
void BinaryTree<T>::allPaths(TreeNode<T> *root, std::vector<std::set<TreeNode<T> *>> &paths) {
    LOG();
    if(root == NULL){
         paths.clear();
         return;
     }
    //TO DO
}

template <class T>
void BinaryTree<T>::allPaths_recursive(TreeNode<T> *root, vector<T>& path, vector<vector<T>>& paths) {
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->value);
        paths.push_back(path);

        return;
    }
    if(root->left){
        if(!root->visited) {
            path.push_back(root->value);/*顺序压入vector的元素,如果root节点开始*/
        }
        root->visited = true;
        allPaths_recursive(root->left,path, paths);
        path.pop_back();/*回溯弹出vector的元素,支持root节点*/
    }
    if(root->right){

        if(!root->visited) {
            path.push_back(root->value);/*顺序压入vector的元素,如果未被访问过的节点开始*/
        }
        root->visited = true;
        allPaths_recursive(root->right,path, paths);
        path.pop_back();/*回溯弹出vector的元素,支持root节点*/
    }
}

template <class T>
int BinaryTree<T>::getWidth(TreeNode<T> *root) {
    return -1;
}

template <class T>
bool BinaryTree<T>::is_full_binary_tree(TreeNode<T> *root) {
    return false;
}