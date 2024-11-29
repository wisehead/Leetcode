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
		vec[n-1] = A[n-1];
		int maxv = A[0];
		for (int i = n - 2; i >= 0; i--)
		{
			vec[i] = min(A[i], vec[i+1]);
		}

		for (int i = 0; i < n - 1; i++)
		{
			maxv = max(A[i], maxv);
			if (maxv <= vec[i+1])
				return i+1;
		}
		return 0;
    }
};
int main()
{}
