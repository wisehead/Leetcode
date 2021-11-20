/*******************************************************************************
 *      file name: next_greater_element_I.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/20-09:17:51                              
 *  modified time: 2018/08/20-09:17:51                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int>::iterator it1, it2, it3;
		vector<int> res;
		for (it1 = findNums.begin(); it1 != findNums.end(); it1++)
		{
			bool exist = false;
			for (it2 = nums.begin(); it2 != nums.end(); )
			{
				if (*it2 == *it1)
					exist = true;
				if (exist && *it2 > *it1)
				{
					res.push_back(*it2);
					break;
				}
				it2++;
			}
			if (it2 == nums.end())
				res.push_back(-1);
		}
		/*
		for (int i = 0; i < findNums.size(); i++)
		{
			int j = 0;
			for (j = i; j < nums.size(); j++)
			{
				if (nums[j] > findNums[i])
				{
					res.push_back(nums[j]);
					break;
				}
			}
			if (j == nums.size())
				res.push_back(-1);
		}
		*/
		return res;
    }
};
int main()
{}
