/*******************************************************************************
 *      file name: array_partition_I.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-21:51:55                              
 *  modified time: 2018/08/25-21:51:55                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ret = 0;
		for (int i = 0; i < nums.size(); i+=2)
		{
			ret += nums[i];
		}
		return ret;
    }
};
int main()
{}
