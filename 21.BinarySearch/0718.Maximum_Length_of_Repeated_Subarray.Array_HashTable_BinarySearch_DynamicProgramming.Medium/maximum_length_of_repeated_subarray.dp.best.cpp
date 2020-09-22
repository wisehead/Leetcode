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
/**
 * dp[i][j] = a[i] == b[j] ? 1 + dp[i + 1][j + 1] : 0;
 * dp[i][j] : max lenth of common subarray start at a[i] & b[j];
 */
class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if (!m || !n) return 0;
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[j] = a[i] == b[j] ? 1 + dp[j + 1] : 0);
            }
        }
        return res;
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
