/*******************************************************************************
 *      file name: subsets_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/29-10:07:44                              
 *  modified time: 2019/03/29-10:07:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		int size = nums.size();
		vector<int> vec;
		res.push_back(vec);
		if (size == 0) return res;
        sort(nums.begin(), nums.end());
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
        set<vector<int>> st(res.begin(), res.end());
        res.assign(st.begin(), st.end());
		return res;
    }
};

int main()
{}
