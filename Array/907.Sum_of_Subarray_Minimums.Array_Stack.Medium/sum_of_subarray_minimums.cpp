/*******************************************************************************
 *      file name: sum_of_subarray_minimums.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/22-09:54:20                              
 *  modified time: 2019/06/22-09:54:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
		int n = A.size();
		long long int  cnt = 0;
		vector<int> dp(A.begin(), A.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				dp[j] = min(dp[j], A[i+j]);
				cnt += dp[j];
                //cout<<"cnt:"<<cnt<<endl;
                if (cnt >= 1000000000 +7)
                    cnt %= (1000000000 +7);
                //cout<<"cnt %:"<<cnt<<endl;
			}
		}
		return cnt;
    }
};
int main()
{}
