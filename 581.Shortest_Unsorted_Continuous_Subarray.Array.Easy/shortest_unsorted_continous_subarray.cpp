/*******************************************************************************
 *      file name: shortest_unsorted_continous_subarray.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-22:37:13                              
 *  modified time: 2018/08/25-22:37:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
		vector<int> orig(nums);
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int i = 0, j = len - 1;
		for (i = 0; i <len; i++)
		{
			if (nums[i] != orig[i])
				break;
		}
		for (j = len -1; j >= 0; j--)
		{
			if (nums[j] != orig[j])
				break;
		}
		
		if (j - i < 0)
			return 0;
		return j - i + 1;
    }
};
int main()
{}
