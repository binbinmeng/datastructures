//
// Created by binbinm on 2020/6/14.
//

#ifndef ALGORITHMS_BACKTRACKING_H
#define ALGORITHMS_BACKTRACKING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class BackTracking {
public:
    /*
     * Determine all possible combinations of k numbers out of 1 ... N
     * for example: generate_all_combinations(N=4, k=2)
                    [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]].
     */
    void combination(vector<T> data, int N, int k);

    /*
    * Determine all possible permutationof numbers out of 1 ... N
    * for example: A B C
         ABC ACB  BAC BCA CAB CBA
    */
    void permutationn(vector<T> data);

    /*
     *
     */
    void subsequences(vector<T> data);

};


#endif //ALGORITHMS_BACKTRACKING_H
