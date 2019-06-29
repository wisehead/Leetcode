/*******************************************************************************
 *      file name: maximum_sum_circular_subarray.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/29-08:56:56                              
 *  modified time: 2019/06/29-08:56:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
		int n = A.size();
		vector<int> B(A.begin(), A.end());
		for (int i = 0; i < n; i++)
		{
			if (A[i] <= 0) continue;
			int sum = A[i];
			for (int j = i + 1; j % n != i; j++)
			{
                j = j % n;
				sum += A[j];
				B[i] = max(B[i], sum);
			}
		}
		int ret = INT_MIN;
		for (auto e: B)
			ret = max(ret, e);
		return ret;
    }
};
int main()
{}
