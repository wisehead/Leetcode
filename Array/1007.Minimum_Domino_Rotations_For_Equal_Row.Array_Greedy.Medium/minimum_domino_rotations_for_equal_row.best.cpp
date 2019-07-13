/*******************************************************************************
 *      file name: minimum_domino_rotations_for_equal_row.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/12-09:52:44                              
 *  modified time: 2019/07/12-09:52:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Solution 2
Try A[0]
Try B[0]
return -1
One observation is that, if A[0] works, no need to check B[0].
Because if both A[0] and B[0] exist in all dominoes,
the result will be the same.
 */
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        for (int i = 0, a = 0, b = 0; i < n && (A[i] == A[0] || B[i] == A[0]); ++i) {
            if (A[i] != A[0]) a++;
            if (B[i] != A[0]) b++;
            if (i == n - 1) return min(a, b);
        }
        for (int i = 0, a = 0, b = 0; i < n && (A[i] == B[0] || B[i] == B[0]); ++i) {
            if (A[i] != B[0]) a++;
            if (B[i] != B[0]) b++;
            if (i == n - 1) return min(a, b);
        }
        return -1;
    }
};
int main()
{}
