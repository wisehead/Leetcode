/*******************************************************************************
 *      file name: search_in_rotated_sorted_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/28-09:43:08                              
 *  modified time: 2019/02/28-09:43:08                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int size = nums.size();
		int left = 0, right = size - 1, mid = (left + right)/2;
		while (left < right)
		{
			mid = (left + right)/2;
			cout<<"xxx left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
			//cout<<"xxx left:"<<nums[left]<<"	right:"<<nums[right]<<"	mid:"<<nums[mid]<<endl;
			if (nums[mid] == target)  return mid;
			if (target < nums[mid])  
			{
				if (target < nums[left])
					left = mid+1;
				else
					right = mid;
			}
			else// target > mid
			{
				if (target < nums[right])
					left = mid+1;
				else
					right = mid;
			}
			cout<<"yyy left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
			cout<<"yyy nums[left]:"<<nums[left]<<"	nums[right]:"<<nums[right]<<"	nums[mid]:"<<nums[mid]<<endl;
		}
		return -1;
    }
};
int main()
{
	Solution sol;
	//int arr[] = {4,5,6,7,0,1,2};
	int arr[] = {4,5,6,7,0,1,2};
	//int target = 3;
	int target = 0;
	vector<int> vec(arr, arr+7);
	int ret = sol.search(vec, target);
	cout<<"ret:"<<ret<<endl;
}
