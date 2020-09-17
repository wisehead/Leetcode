/*******************************************************************************
 *      file name: set_mismatch.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/30-13:58:28                              
 *  modified time: 2018/08/30-13:58:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		int len = nums.size();
		int dup = 0, miss = 0;
		vector<int> res;
		vector<int> vec(len, 0);
		for (int i = 0; i<len; i++)
		{
			int index = nums[i];
			vec[index-1]++;
		}
		for (int i = 0; i<len; i++)
		{
			if (vec[i] == 0) 
				miss = i+1 ;
			if (vec[i] == 2) 
				dup = i+1 ;
		}
		res.push_back(dup);
		res.push_back(miss);
		return res;
    }
};
int main()
{}
