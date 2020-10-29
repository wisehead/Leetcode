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
    int getPos(vector<int>& nums) {
		int size = nums.size();
		int left = 0, right = size - 1, mid = (left + right)/2;
		while (left < right)
		{
			mid = (left + right)/2;
			if (nums[mid] > nums[right])
				left = mid + 1;
            else
				right = mid;
		}
		return left;

	}
    int search(vector<int>& nums, int target) {
		int size = nums.size();
        if (size == 0) return -1;
		int left = 0, right = size - 1, mid = (left + right)/2;
		int pos = getPos(nums);
        cout<<"pos:"<<pos<<endl;
		if (target < nums[pos] ) return -1;
		if (target == nums[pos] ) return pos;
        if (pos == 0)
        {
            //
        }
		else if (target >= nums[left])
		{
			right = pos; 
		}
		else if (target <= nums[right])
		{
			left = pos+1;
		}

		while (left <= right)
		{
            if (left == right)
            {
                if (nums[left] == target) return left;
                else
                    break;
            }
            cout<<"xxx left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
			mid = (left + right)/2;
			if (target == nums[mid]) return mid;
			if (target < nums[mid])
				right = mid;
			else
				left = mid + 1;
		}
		return -1;
    }
};
int main()
{
	Solution sol;
	//int arr[] = {4,5,6,7,0,1,2};
	//int arr[] = {5,6,7,0,1,2,4};
	//int target = 3;
	/*
	int target = 5;
	int arr[] = {1,3,5};
	vector<int> vec(arr, arr+3);
	*/
	int target = 1;
	int arr[] = {3,1};
	vector<int> vec(arr, arr+2);
	//vector<int> vec(arr, arr+7);
	//int ret = sol.search(vec, target);
	int ret = sol.getPos(vec);
	cout<<"ret:"<<ret<<endl;
}
