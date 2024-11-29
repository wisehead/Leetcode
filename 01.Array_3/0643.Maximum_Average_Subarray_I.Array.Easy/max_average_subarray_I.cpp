/*******************************************************************************
 *      file name: max_average_subarray_I.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/30-13:27:16                              
 *  modified time: 2018/08/30-13:27:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
		int64_t sum = 0;
		int64_t max = -0x7fffffffffffffff;
		int len = nums.size();
		for (int i = 0; i < len - k + 1; i++)
		{
			sum = 0;
			for (int j=i; j < i+k; j++)
			{
				sum += nums[j];
			}
			if (sum > max)
				max = sum;
		}
		return (double)max/k;
    }
};
int main()
{}
