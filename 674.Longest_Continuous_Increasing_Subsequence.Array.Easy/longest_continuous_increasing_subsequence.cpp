/*******************************************************************************
 *      file name: longest_continuous_increasing_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/14-22:02:18                              
 *  modified time: 2018/09/14-22:02:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		int count = 1, max = 1;
        if (len == 0) return 0;
		if (len == 1) return 1;
		for (int i=0; i+1<len; i++)
		{
			count = 1;
			while(nums[i+1] > nums[i] && i+1 < len)
			{
				count++;
				if (count > max) max = count;
				i++;
			}
		}
		return max;
    }
};
int main()
{}
