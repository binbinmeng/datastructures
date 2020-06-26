//
// Created by binbinm on 2020/6/14.
//

#ifndef ALGORITHMS_NDARRAY_H
#define ALGORITHMS_NDARRAY_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "stack"
using namespace std;

template <class T>
class NDArray {
public:
    NDArray();
    ~NDArray();
    NDArray(const NDArray<T>&);
    NDArray<T>& operator = (const NDArray<T> &ndarray);
    NDArray<T>& operator > (const NDArray<T> &ndarray);
    NDArray<T>& operator < (const NDArray<T> &ndarray);
    NDArray<T>& operator == (const NDArray<T> &ndarray);
    bool create(vector<vector<T> >& array);
    void print();

public:
    /*给定一个二维网格和一个单词(单词必须按照字母顺序)，找出该单词是否存在于网格中。
     * board =
        [
          ['A','B','C','E'],
          ['S','F','C','S'],
          ['A','D','E','E']
        ]

        给定 word = "ABCCED", 返回 true.
        给定 word = "SEE", 返回 true.
        给定 word = "ABCB", 返回 false.
     */
    bool word_searh(vector<vector<T> >& array, vector<T> &target);

    /*
     * 在二维数组中(int)，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序
     * 问题：输入一个整数，判断数组中是否含有该整数
     */
    bool find_target(vector<vector<T> >& array, int target);

    /*
     * 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
        示例 1:
        输入:
        11110
        11010
        11000
        00000
        输出: 1

        示例 2:
        输入:
        11000
        11000
        00100
        00011
        输出: 3
        */
       int numIslands(vector<vector<T> >& array);

       /*
        * 二维矩阵转置操作
        * board =
        [
          ['A','B','C','E'],
          ['S','F','C','S'],
          ['A','D','E','E']
        ]

        转置后：
        board =
        [
          ['A','S','A'],
          ['B','F','D'],
          ['C','C','E']
          ['E','S','E']
        ]
        */
       void reverse();

       /*
        * 给定一个 M x N 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
        */
       void find_topk(vector<vector<T> >& array, int K);

       /*
        * "之"字形打印二维数组元素，array[n][m]
        * board =
        [
          ['A','S','A'],
          ['B','F','D'],
          ['C','C','E']
          ['E','S','E']
        ]
        输出：A,B,S,A,F,C,E,C,D,E,S,E
        */

       void print_Z();

       /*
        * 顺时针打印，array[n][m]
        *board =
        [
          ['A','S','A'],
          ['B','F','D'],
          ['C','C','E']
          ['E','S','E']
        ]
        输出：A,S,A,D,E,E,S,E,C,B,F,C
        */
       void print_rataion();

       /*
        * 输入一个无序整数数组，调整数组中数字的顺序， 所有偶数位于数组的前半部分，使得所有奇数位于数组的后半部分。
            要求时间复杂度为O(n)。
        */

       void F();

       /*
        * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个排好序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
        */

       /*
        * 输入参数为字符串型的n维数组，数组的每一项值为数组 或 int型数字。请实现一个函数，可以获取列表嵌套列表的最大深度为多少。
        */
private:
    int row;
    int col;

    vector<vector<T>> m_array;
};

//template class NDArray<std::string>;
template class NDArray<int>;
#endif //ALGORITHMS_NDARRAY_H
