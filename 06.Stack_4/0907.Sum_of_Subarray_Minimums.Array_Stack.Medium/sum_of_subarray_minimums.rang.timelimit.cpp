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
		for (int i = 0; i < n; i++)
		{
			int left = 1, right = 1;
			for (int j = i-1; j >= 0; j--)
			{
				if (A[j] >= A[i])
					left++;
				else
					break;
			}
			for (int j = i+1; j < n; j++)
			{
				if (A[j] > A[i])
					right++;
				else
					break;
			}
			cnt += (left*right)*A[i];
            if (cnt >= 1000000007)
			    cnt %= (1000000007);
		}
		return cnt;
    }
};
int main()
{}
