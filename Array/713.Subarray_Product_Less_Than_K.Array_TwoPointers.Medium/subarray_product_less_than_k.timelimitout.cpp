/*******************************************************************************
 *      file name: subarray_product_less_than_k.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/14-10:50:46                              
 *  modified time: 2019/05/14-10:50:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		vector<int> vec(nums);
		int n = nums.size();
		int cnt = 0;
		for (auto e: nums)
			if (e < k) cnt++;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n-i; j++)
			{
                if (vec[j] >= k) continue;
				vec[j] = vec[j]*nums[j+i];
				if (vec[j] < k) cnt++;
			}
		}
		return cnt++;
    }
};
int main()
{}
