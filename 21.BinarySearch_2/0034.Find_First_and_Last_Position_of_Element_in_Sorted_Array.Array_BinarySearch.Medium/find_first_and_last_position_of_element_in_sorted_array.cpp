/*******************************************************************************
 *      file name: find_first_and_last_position_of_element_in_sorted_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/01-09:21:24                              
 *  modified time: 2019/03/01-09:21:24                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target, bool isleft) {
		int size = nums.size();
		int left = 0, right = size - 1, mid = 0;
		while (left < right)
		{
			mid = (left + right)/2;
			if (target==nums[mid])
			{
				if (isleft)
					right = mid;
				else
					left = mid + 1;
			}
			else if (target < nums[mid])
				right = mid;
			else 
				left = mid + 1;
		}
		return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		int size = nums.size();
        if (size == 0) 
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
		int left = 0, right = size - 1;
		left = search(nums, target, true);
		right = search(nums, target, false);
		//cout<<"zzz left:"<<left<<"  right:"<<right<<endl;
		if (nums[left] == target)
			res.push_back(left);
		else 
			res.push_back(-1);
        
        if (nums[right] == target)
            res.push_back(right);
		else if (right - 1 >= 0 && nums[right - 1] == target) 
			res.push_back(right-1);
		else 
			res.push_back(-1);
		return res;
    }
};
int main()
{
	Solution sol;
	/*
	int arr[] = {5,7,7,8,8,10};
	vector<int> vec(arr, arr+6);
	*/
	int arr[] = {5,7,7,8,8,8,8,8,8,8,8,8,8,8,10};
	//vector<int> vec(arr, arr+(sizeof(arr) / sizeof(arr[0])));
	vector<int> vec(arr, arr+15);
	int target = 8;
//	int ret = sol.search(vec, target);
//	cout<<"ret:"<<ret<<endl;
	vector<int> res = sol.searchRange(vec, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout<<"res["<<i<<"]"<<res[i]<<endl;
	}
}
