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
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		int n = A.size();
		vector<int> vec(n, 0);
		vector<int> vecl;
		//suppose L <= M
		if (L > M) swap(L, M);

		for (int l = 1; l <= M; l++)
		{
			for (int i = 0; i < n+1-l; i++)
			{
				vec[i] += A[i+l-1]; 
			}
			if (l == L) vecl.assign(vec.begin(), vec.end());
		}
		int max1 = 0;
		//from left to right
		vector<int> vec1(n, 0);
		for (int i = 0; i < n +1-M; i++)
		{
			max1 = max(max1, vec[i]);
			vec1[i] = max1;
		}
		int max2 = 0;
		//from right to left 
		vector<int> vec2(n, 0);
		for (int i = n-1; i >= M-1; i--)
		{
			max2 = max(max2, vec[i - M +1]);
			vec2[i-M+1] = max2;
		}
		int ret = 0;
		for (int i = 0; i < n+1-L; i++)
		{
			if (i < M)
			{
				int x = vecl[i] + vec2[i+L];
				ret = max(ret, x);
			}
			else if (i >= n - M -L)
			{
				int x = vecl[i] + vec1[i-M];
				ret = max(ret, x);
			}
			else
			{
				int y = max(vec1[i-M], vec2[i+L]);
				ret = max(ret, vecl[i]+y);
			}
		}
		return ret;
    }
};
int main()
{}
