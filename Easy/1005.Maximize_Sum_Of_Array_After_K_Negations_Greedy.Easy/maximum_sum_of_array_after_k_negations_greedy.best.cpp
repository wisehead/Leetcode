/*******************************************************************************
 *      file name: maximum_sum_of_array_after_k_negations_greedy.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/15-15:00:46                              
 *  modified time: 2020/09/15-15:00:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; K > 0 && i < A.size() && A[i] < 0; ++i, --K)
            A[i] = -A[i];
        return accumulate(A.begin(), A.end(), 0) - (K%2) * *min_element(A.begin(), A.end()) * 2;
    }
};

int main()
{}
