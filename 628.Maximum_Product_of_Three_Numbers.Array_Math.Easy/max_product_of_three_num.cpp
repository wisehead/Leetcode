/*******************************************************************************
 *      file name: max_product_of_three_num.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/28-17:46:30                              
 *  modified time: 2018/08/28-17:46:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		if (nums[len -1] > 0)
		{
			int temp = max(nums[0]*nums[1], nums[len-2]*nums[len-3]);
			return temp*nums[len -1];
		}
		else
			return nums[0]*nums[1]*nums[2];
    }
};
int main()
{}
