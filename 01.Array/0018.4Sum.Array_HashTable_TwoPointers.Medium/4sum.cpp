/*******************************************************************************
 *      file name: 4sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/26-09:36:14                              
 *  modified time: 2019/02/26-09:36:14                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num, int target) {
		vector<vector<int> > res;
		//std::sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++) {
			int t = target - num[i];
			int front = i + 1;
			int back = num.size() - 1;
			while (front < back) {
				int sum = num[front] + num[back];
				// Finding answer which start from number num[i]
				if (sum < t)
					front++;
				else if (sum > t)
					back--;
				else {
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					res.push_back(triplet);
					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && num[front] == triplet[1]) front++;
					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}
			}
			// Processing duplicates of Number 1
			while (i + 1 < num.size() && num[i + 1] == num[i]) 
				i++;
		}
		return res;
	}

    vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> > res;
        if (nums.size() < 4) return res;
		set<vector<int> > st;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++)
		{
			vector<vector<int> > temp;
			vector<int> vec(nums.begin() + i + 1, nums.end());
			temp = threeSum(vec, target - nums[i]);
			if (temp.size() > 0)
			{
				for (int k = 0; k < temp.size(); k++)
				{
					vector<int> v;
					v.push_back(nums[i]);
					v.insert(v.begin() + 1, temp[k].begin(), temp[k].end());
					st.insert(v);
					//res.push_back(v);
				}
			}
		}
		res.assign(st.begin(), st.end());
		return res;
    }
};
int main()
{}
