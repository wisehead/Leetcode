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
		//vector<int>::iterator it;
		vector<int> negv, posv, zerov;
		set<int> negs, poss;
		int size = nums.size();
		vector<vector<int> > res;
		for (int i = 0; i < size; i++)
		{
			int x = nums[i];
			if (x < 0)
			{
				negv.push_back(x);
				negs.insert(x);
			}
			else if (nums[i] > 0)
			{
				posv.push_back(x);
				poss.insert(x);
			}
			else
			{
				zerov.push_back(x);
			}
		}
		// for zeros
		if (zerov.size() > 0)
		{
			//for 1 zero
			for (int i = 0; i < negv.size(); i++)
			{
				vector<int> tmp;
				int x = negv[i];
				if (poss.count(-x))
				{
					tmp.push_back(x);
					tmp.push_back(0);
					tmp.push_back(-x);
					res.push_back(tmp);
				}
			}
			if (zerov.size() >= 3)
			{
				vector<int> tmp;
				tmp.push_back(0);
				tmp.push_back(0);
				tmp.push_back(0);
				res.push_back(tmp);
			}
		}
		//for 2 neg values 
		for (int i = 0; i < negv.size(); i++)
		{
			for (int j = i + 1; j < negv.size(); j++)
			{
				vector<int> tmp;
				int x = negv[i] + negv[j];
				if (poss.count(-x))
				{
					tmp.push_back(negv[i]);
					tmp.push_back(negv[j]);
					tmp.push_back(-x);
					res.push_back(tmp);
				}
			}
		}
		//for 2 pos values 
		for (int i = 0; i < posv.size(); i++)
		{
			for (int j = i + 1; j < posv.size(); j++)
			{
				vector<int> tmp;
				int x = posv[i] + posv[j];
				if (negs.count(-x))
				{
					tmp.push_back(-x);
					tmp.push_back(posv[i]);
					tmp.push_back(posv[j]);
					res.push_back(tmp);
				}
			}
		}
		set<vector<int> > st(res.begin(), res.end());
		res.assign(st.begin(), st.end());
		return res;
    }
};
int main()
{}
