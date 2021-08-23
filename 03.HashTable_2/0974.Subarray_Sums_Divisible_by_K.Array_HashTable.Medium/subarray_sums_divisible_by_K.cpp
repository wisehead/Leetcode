/*******************************************************************************
 *      file name: subarray_sums_divisible_by_K.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/07-18:01:54                              
 *  modified time: 2019/07/07-18:01:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
		int n = A.size();
		int cnt = 0;
		//vector<int> vec(A.begin(), A.end());
		vector<int> vec(n, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				vec[j] = vec[j] + A[j+i];
				if (vec[j] % K == 0)
					cnt++;
			}
		}
		return cnt;
    }
};
int main()
{}
