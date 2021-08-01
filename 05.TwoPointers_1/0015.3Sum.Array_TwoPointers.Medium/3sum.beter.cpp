/*******************************************************************************
 *      file name: 3sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/24-08:46:52                              
 *  modified time: 2019/02/24-08:46:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		set<int > s1;
		set<vector<int> > st;
		int size = nums.size();
		vector<vector<int> > res;
		for (int i = 0; i < size; i++)
		{
			int x = nums[i];
			s1.insert(x);
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				vector<int> tmp;
				int x = nums[i] + nums[j];
				if (-x < nums[j]) continue;
				if (-x == nums[j])
				{
					if ( (j+1 < size && nums[j+1] != nums[j]) || (j == size - 1))
						continue;
				}	
				if (s1.count(-x))
				{
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					tmp.push_back(-x);
					st.insert(tmp);
				}
			}
		}
		res.assign(st.begin(), st.end());
		return res;
    }
};
int main()
{}
