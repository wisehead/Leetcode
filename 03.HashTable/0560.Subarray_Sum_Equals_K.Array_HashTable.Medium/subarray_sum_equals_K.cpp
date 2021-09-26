/*******************************************************************************
 *      file name: subarray_sum_equals_K.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/24-22:49:52                              
 *  modified time: 2019/04/24-22:49:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int n = nums.size(), count = 0;
		vector<int> vec(n, 0);
		for (int step = 1; step <= n; step++)
		{
			for (int i = 0; i < n - step + 1; i++)
			{
				vec[i] = vec[i] + nums[i+step-1];
				if (vec[i] == k) count++;
			}
		}
		return count;
    }
};
int main()
{}
