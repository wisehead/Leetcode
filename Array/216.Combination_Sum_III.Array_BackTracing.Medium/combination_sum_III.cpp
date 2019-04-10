/*******************************************************************************
 *      file name: combination_sum_III.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/10-22:32:35                              
 *  modified time: 2019/04/10-22:32:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    void cs(set<vector<int> >& s, vector<int>& vec, vector<int>& nums, int k, int n) {
		if (k==0) return;
		if (k==1)
		{
			vector<int>::iterator it;
			it = find(nums.begin(),nums.end(),n);
			if (it != nums.end())
			{
				vec.push_back(n);
                vector<int> v(vec);
                sort(v.begin(), v.end());
				s.insert(v);
				vec.pop_back();
			}
			return;
		}
		int size = nums.size();
		for (int i=0; i<size; i++)
		{
			int tmp = nums[i];
			nums.erase(nums.begin()+i);
			vec.push_back(tmp);
			cs(s, vec, nums, k-1, n-tmp);
			nums.insert(nums.begin()+i, tmp);
			vec.pop_back();
		}
    }
    vector<vector<int> > combinationSum3(int k, int n) {
		set<vector<int> > s;
		vector<int> vec;
		int arr[] = {1,2,3,4,5,6,7,8,9};
		vector<int> nums(arr, arr+9);
		cs(s, vec, nums,k, n);
		vector<vector<int> > res(s.begin(), s.end());
		return res;
    }
};
int main()
{}
