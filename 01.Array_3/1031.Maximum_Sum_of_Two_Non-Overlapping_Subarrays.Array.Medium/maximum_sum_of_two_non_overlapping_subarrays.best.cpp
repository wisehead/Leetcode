/*******************************************************************************
 *      file name: maximum_sum_of_two_non_overlapping_subarrays.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/15-09:08:43                              
 *  modified time: 2019/07/15-09:08:43                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Explanation
Lsum, sum of the last L elements
Msum, sum of the last M elements

Lmax, max sum of contiguous L elements before the last M elements.
Mmax, max sum of contiguous M elements before the last L elements/

Complexity
Two pass, O(N) time,
O(1) extra space.

It can be done in one pass. I just don't feel like merging them.
If you don't like change the original input, don't have to.
*/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (int i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            Lmax = max(Lmax, A[i - M] - A[i - L - M]);
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            res = max(res, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
        }
        return res;
    }
};
int main()
{}
