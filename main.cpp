#include "linkedlist.h"
#include "binarytree.h"
#include "sort.h"
#include "iostream"
using namespace std;

int test_linkedlist()
{

    Node<int> node1 = Node<int>(1);
    Node<int> node2 = Node<int>(2);
    Node<int> node3 = Node<int>(3);
    Node<int> node4 = Node<int>(4);
    Node<int> node5 = Node<int>(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node1;

    LinkedList<int> list(&node1);
    //list.print();
    list.JosephusRing(3);

    int data[] = {3, 2, 4, 6, 7, 9};
    LinkedList<int> list1(data, sizeof(data) / sizeof(data[0]));
    list1.Print();
    list1.Reverse();
    list1.Print();

    return 0;
}

int test_binarytree()
{
    TreeNode<int> node1 = TreeNode<int>(1);
    TreeNode<int> node2 = TreeNode<int>(2);
    TreeNode<int> node3 = TreeNode<int>(3);
    TreeNode<int> node4 = TreeNode<int>(4);
    TreeNode<int> node5 = TreeNode<int>(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    BinaryTree<int> binarytree(&node1);
    binarytree.LevelOrder();
    binarytree.PreOrder();
    //binarytree.InOrder();
    //binarytree.PostOrder();
    //int hight = binarytree.Hight(&node1);
    //std::cout<<hight<<std::endl;

    //binarytree.ImageTree(&node1);
    //binarytree.LevelOrder();
    //int paths = binarytree.SpecificPath(8);
    //std::cout<<paths<<std::endl;
    binarytree.AllPath();
}

int test_sort(){

    int data[] = {2,3,5,1,9,6,4,8,7};
    SortFactory<int> sortfactory(data, 9);
    sortfactory.Print();
    sortfactory.BublleSort();
    sortfactory.Print();
}

int main()
{
    //test_linkedlist();
    //test_binarytree();
    test_sort();
}
