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
	vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
		int i = 0, j = n - 1;
		vector<int> ret(2, -1);
        if (n == 0) return ret;
		// Search for the left one
		while (i < j)
		{
			int mid = (i + j) /2;
			if (nums[mid] < target) i = mid + 1;
			else j = mid;
		}
		if (nums[i]!=target) return ret;
		else ret[0] = i;
		
		// Search for the right one
		j = n-1;  // We don't have to set i to 0 the second time.
		while (i < j)
		{
			int mid = (i + j) /2 + 1;	// Make mid biased to the right
			if (nums[mid] > target) j = mid - 1;  
			else i = mid;				// So that this won't make the search range stuck.
		}
		ret[1] = j;
		return ret; 
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
