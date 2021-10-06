/*******************************************************************************
 *      file name: subsets.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/25-09:56:29                              
 *  modified time: 2019/03/25-09:56:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int size = nums.size();
		vector<int> vec;
		res.push_back(vec);
		if (size == 0) return res;
		vec.push_back(nums[0]);
		res.push_back(vec);
		for (int i = 1; i < size; i++)
		{
            int n = res.size();
			for (int j = 0; j < n; j++)
			{
				vector<int> v = res[j]; 
				v.push_back(nums[i]);
				res.push_back(v);
			}
		}
		return res;
    }
};
int main()
{}
