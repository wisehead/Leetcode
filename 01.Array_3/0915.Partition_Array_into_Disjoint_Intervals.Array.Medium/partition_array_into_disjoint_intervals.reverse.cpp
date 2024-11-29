/*******************************************************************************
 *      file name: partition_array_into_disjoint_intervals.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/28-09:43:01                              
 *  modified time: 2019/06/28-09:43:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
		int n = A.size();
		vector<int> vec(n, 0);
		int minv = A[n-1];
		int maxv = A[0];
		for (int i = 0; i < n; i++)
		{
			maxv = max(A[i], maxv);
			vec[i] = maxv;
		}
		for (int i = n - 1; i > 0; i--)
		{
			minv = min(A[i], minv);
			if (vec[i-1] < minv)
				return i;
		}
		return 0;
    }
};
int main()
{}
