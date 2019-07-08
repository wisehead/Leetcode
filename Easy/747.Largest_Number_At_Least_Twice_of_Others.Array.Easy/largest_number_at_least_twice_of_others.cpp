/*******************************************************************************
 *      file name: largest_number_at_least_twice_of_others.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/05-10:59:31                              
 *  modified time: 2018/10/05-10:59:31                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findMax(vector<int>& nums, int& pos) {
		int len = nums.size();
		if (len == 0) return -1;
		int max = nums[0];
		pos = 0;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
				pos = i;
			}
		}
		return max;
	}
    int dominantIndex(vector<int>& nums) {
		int pos = -1;
		int max = findMax(nums, pos);
		nums.erase(nums.begin() + pos);
		int pos2 = -1;
		int secMax = findMax(nums, pos2);
		if (max >= 2*secMax) return pos;
		return -1;
    }
};
int main()
{}
