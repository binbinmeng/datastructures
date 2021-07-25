#include "binarytree.h"

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(TreeNode<T> *node)
{
    root = node;
}

template <class T>
void BinaryTree<T>::PreOrder()
{
    if (root != NULL)
    {
        stack<TreeNode<T> *> tree_node_stack;
        tree_node_stack.push(root);
        while (tree_node_stack.empty() == false)
        {
            TreeNode<T> *front_node = tree_node_stack.top();
            std::cout << front_node->value << " | ";
            tree_node_stack.pop();

            if (front_node->right != NULL)
            {
                tree_node_stack.push(front_node->right);
            }

            if (front_node->left != NULL)
            {
                tree_node_stack.push(front_node->left);
            }
        }
        std::cout << std::endl;
        return;
    }
    return;
}

template <class T>
void BinaryTree<T>::InOrder()
{
    if (root != NULL)
    {
        stack<TreeNode<T> *> tree_node_stack;
        tree_node_stack.push(root);

        while (tree_node_stack.empty() == false)
        {
            TreeNode<T> *front_node = tree_node_stack.top();

            if (front_node->left == NULL && front_node->right == NULL)
            {
                std::cout << front_node->value << " | ";
                tree_node_stack.pop();
            }
            else
            {
                if (front_node->visited_num > 0)
                {
                    std::cout << front_node->value << " | ";
                    tree_node_stack.pop();

                    if (front_node->right != NULL)
                    {
                        tree_node_stack.push(front_node->right);
                    }
                }
                else
                {
                    if (front_node->left != NULL)
                    {
                        tree_node_stack.push(front_node->left);
                        front_node->visited_num++;
                    }
                }
            }
        }
        std::cout << std::endl;
        return;
    }
    return;
}

template <class T>
void BinaryTree<T>::PostOrder()
{
    if (root != NULL)
    {
        stack<TreeNode<T> *> tree_node_stack;
        tree_node_stack.push(root);

        while (tree_node_stack.empty() == false)
        {
            TreeNode<T> *front_node = tree_node_stack.top();

            if (front_node->left == NULL && front_node->right == NULL)
            {
                std::cout << front_node->value << " | ";
                tree_node_stack.pop();
            }
            else
            {
                if (front_node->visited_num > 0)
                {
                    std::cout << front_node->value << " | ";
                    tree_node_stack.pop();
                }
                else
                {
                    if (front_node->right != NULL)
                    {
                        tree_node_stack.push(front_node->right);
                        front_node->visited_num++;
                    }
                    if (front_node->left != NULL)
                    {
                        tree_node_stack.push(front_node->left);
                        front_node->visited_num++;
                    }
                }
            }
        }
        std::cout << std::endl;
        return;
    }
    return;
}

template <class T>
void BinaryTree<T>::LevelOrder()
{
    if (root != NULL)
    {
        queue<TreeNode<T> *> tree_node_queue;
        tree_node_queue.push(root);

        while (tree_node_queue.empty() == false)
        {
            TreeNode<T> *front_node = tree_node_queue.front();
            std::cout << front_node->value << " | ";

            if (front_node->left != NULL)
            {
                tree_node_queue.push(front_node->left);
            }
            if (front_node->left != NULL)
            {
                tree_node_queue.push(front_node->right);
            }

            tree_node_queue.pop();
        }
        std::cout << std::endl;
        return;
    }
    return;
}

template <class T>
int BinaryTree<T>::Hight(TreeNode<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_hight = Hight(root->left);
    int right_hight = Hight(root->right);

    return max(left_hight, right_hight) + 1;
}

template <class T>
void BinaryTree<T>::ImageTree(TreeNode<T> *root)
{
    if (root == NULL)
    {
        return;
    }

    swap(root->left, root->right);
    ImageTree(root->left);
    ImageTree(root->right);
}
template <class T>
int BinaryTree<T>::SpecificPath(int sum)
{
    vector<vector<T>> paths;
    return paths.size();
}

template <class T>
void BinaryTree<T>::AllPath()
{
    if (root != NULL)
    {
        vector<vector<TreeNode<T> *>> paths;
        stack<TreeNode<T> *> tree_node_stack;
        tree_node_stack.push(root);

        while (tree_node_stack.empty() == false)
        {
            TreeNode<T> *front_node = tree_node_stack.top();

            if (front_node->left == NULL && front_node->right == NULL)
            {   
                //for get sub path elements
                vector<TreeNode<T> *> path;
                stack<TreeNode<T> *> tree_node_stack_temp = tree_node_stack;
                while (!tree_node_stack_temp.empty())
                {
                    path.push_back(tree_node_stack_temp.top());
                    tree_node_stack_temp.pop();
                }
                std::cout << "subpath lenth = "<<path.size() << std::endl; 
                for (int t = 0; t < path.size(); ++t)
                {
                    std::cout << path[t]->value << " | ";
                } 
                std::cout << std::endl;
                //
                
                tree_node_stack.pop();
            }
            else
            {
                if (front_node->visited_num > 0)
                {
  
                    if (front_node->right != NULL && front_node->visited_num != 2)
                    {
                        tree_node_stack.push(front_node->right);
                        front_node->visited_num++;
                    } 
                    else
                    {
                        tree_node_stack.pop();
                    }  
                }
                else
                {
                    if (front_node->left != NULL)
                    {
                        tree_node_stack.push(front_node->left);
                        front_node->visited_num++;
                    }
                }
            }
        }
    }

    return;
}