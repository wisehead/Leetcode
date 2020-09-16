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
    int searchLeft(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid = 0;
		while (left < right)
		{
			mid = (left + right)/2;
			if (target <= nums[mid])
				right = mid;
			else 
				left = mid + 1;
		}
		return left;
    }
    int searchRight(vector<int>& nums, int target, int oleft) {
		int left = oleft, right = nums.size() - 1, mid = 0;
		while (left < right)
		{
			cout<<"zzz left:"<<left<<"  right:"<<right<<endl;
			mid = (left + right)/2 + 1;
			if (target < nums[mid])
				right = mid - 1;
			else 
				left = mid;
		}
		return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int size = nums.size();
        if (size == 0) 
            return res;

		int left = 0, right = size - 1;
		left = searchLeft(nums, target);
		if (nums[left] != target)
			return res;
		res[0] = left;

		right = searchRight(nums, target, left);
        if (nums[right] != target)
			return res;

		res[1] = right;
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
	int ret = sol.searchRight(vec, target, 0);
	cout<<"ret:"<<ret<<endl;
	vector<int> res = sol.searchRange(vec, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout<<"res["<<i<<"]"<<res[i]<<endl;
	}
}
