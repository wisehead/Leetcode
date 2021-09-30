/*******************************************************************************
 *      file name: house_rob.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/08-12:12                                    
 *  modified time: 17/12/08-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
		vector<int> fn;
		int size = nums.size();
		if (size == 0)
			return 0;
		if (size == 1)
			return nums[0];
		fn.push_back(nums[0]);
		if (nums[1] > nums[0])
			fn.push_back(nums[1]);
		else
			fn.push_back(nums[0]);
		for (int i=2; i<size; i++)
		{
			if (fn[i-2] + nums[i] > fn[i-1])
				fn.push_back(fn[i-2] + nums[i]);
			else
				fn.push_back(fn[i-1]);
		}
		return fn.back();
    }
};
int main()
{}
