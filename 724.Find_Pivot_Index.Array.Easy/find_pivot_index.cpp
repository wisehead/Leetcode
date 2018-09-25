/*******************************************************************************
 *      file name: find_pivot_index.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/25-11:08:40                              
 *  modified time: 2018/09/25-11:08:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
		vector<int> vec1;
		vector<int> vec2;
		int len = nums.size();
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += nums[i];
			vec1.push_back(sum);
		}
		sum = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			sum += nums[i];
			vec2.push_back(sum);
		}
		for (int i = 0; i < len; i++)
		{
			if (vec1[i] == vec2[len - 1 - i])
				return i;
		}
		return -1;
    }
};
int main()
{}
