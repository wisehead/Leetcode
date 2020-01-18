/*******************************************************************************
 *      file name: previous_permutation_with_one_swap.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-12:56:45                              
 *  modified time: 2020/01/18-12:56:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), left = n - 2, right = n - 1;
        while (left >= 0  && A[left] <= A[left + 1]) left--;
        if (left < 0) return A;
        while (A[left] <= A[right]) right--;
        while (A[right - 1] == A[right]) right--;
        swap(A[left], A[right]);
        return A;
    }
};
int main()
{}
