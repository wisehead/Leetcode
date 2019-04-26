/*******************************************************************************
 *      file name: valid_triangle_number.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/26-17:58:14                              
 *  modified time: 2019/04/26-17:58:14                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		int n = nums.size(), cnt = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = i+1; j < n - 1; j++)
			{
				for (int k = j+1; k < n; k++)
				{
					if (nums[i] + nums[j] > nums[k])
						cnt++;
				}
			}
		}
		return cnt;
    }
};
int main()
{}
