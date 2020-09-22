/*******************************************************************************
 *      file name: maximum_length_of_repeated_subarray.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/18-10:17:15                              
 *  modified time: 2019/05/18-10:17:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
/*
The idea is to shift one of the arrays left by k position (0 <= k < n), and to find the longest common sub-array in each case. The run time is O(mn).
For example,

shift array A left by 2 positions, max length is helper(A, B, 2, 0)
A: 3 5 1 2 3 4 6 2
B:     1 2 3 4 5 4
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0, m = A.size(), n = B.size();
        for (int i = 0; i < m; i++) 
            ans = max(ans, helper(A, B, i, 0));
        for (int j = 1; j < n; j++) 
            ans = max(ans, helper(A, B, 0, j));
        return ans;
    }
private:
    int helper(vector<int>& A, vector<int>& B, int i, int j) {
        int len = 0, cnt = 0;
        for (;i < A.size() && j < B.size(); i++, j++) {
            if (A[i] == B[j]) 
                len = max(len, ++cnt);
            else 
                cnt = 0;
        }
        return len;
    }
};
int main()
{
	Solution sol;
	//int arrA[] = {1,2,3,2,1};
	//int arrB[] = {3,2,1,4,7};
	int arrA[] = {0,0,0,0,0};
	int arrB[] = {0,0,0,0,0};
	vector<int> A(arrA, arrA+5);
	vector<int> B(arrB, arrB+5);
	sol.findLength(A, B);
}
