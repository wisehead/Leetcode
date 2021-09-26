/*******************************************************************************
 *      file name: partition_array_into_three_parts_with_euqal_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/14-15:58:33                              
 *  modified time: 2019/07/14-15:58:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
		int n = A.size();
		vector<int> sumvec(n, 0);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += A[i];
			sumvec[i] = sum;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int first = sumvec[i];
			for (int j = i+1; j < n; j++)
			{
				int second = sumvec[j] - sumvec[i];
				if (second != first) continue;
				int third = sumvec[n-1] - sumvec[j];
				if (first == third) return true;
				else continue;

			}
		}
		return false;
    }
};
int main()
{}
