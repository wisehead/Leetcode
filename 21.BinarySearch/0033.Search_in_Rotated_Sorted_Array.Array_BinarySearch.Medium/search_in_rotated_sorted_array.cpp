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
		while (left <= right)
		{
			if (left == right) return left;
			mid = (left + right)/2;
            if (mid+1<size && nums[mid+1] < nums[mid]) 
                return mid;
            
            if (nums[mid] == nums[right]) 
			{
				cout<<"xxx left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
				return mid;
			}
			else if (nums[mid] > nums[right])
			{
				cout<<"yyy left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
				left = mid + 1;
			}
			else if (nums[left] <= nums[mid]) 
			{
				cout<<"zzz left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
                left = mid + 1;
			}
            else
			{
				cout<<"aaa left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
				right = mid;
			}
		}
        //if (size == 2 && nums[1] > nums[0]) return 1;
		return mid;

	}
    int search(vector<int>& nums, int target) {
		int size = nums.size();
        if (size == 0) return -1;
		int left = 0, right = size - 1, mid = (left + right)/2;
		int pos = getPos(nums);
        cout<<"pos:"<<pos<<endl;
		if (target == nums[pos] ) return pos;
		if (target < nums[pos] && target >= nums[left])
		{
			right = pos; 
		}
		else if (target < nums[pos] && target <= nums[right])
		{
			left = pos + 1;
		}
		else
			return -1;
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
			
			//cout<<"xxx left:"<<nums[left]<<"	right:"<<nums[right]<<"	mid:"<<nums[mid]<<endl;
			cout<<"yyy left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
			//cout<<"yyy nums[left]:"<<nums[left]<<"	nums[right]:"<<nums[right]<<"	nums[mid]:"<<nums[mid]<<endl;
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
	int arr[] = {1,3};
	vector<int> vec(arr, arr+2);
	//vector<int> vec(arr, arr+7);
	//int ret = sol.search(vec, target);
	int ret = sol.getPos(vec);
	cout<<"ret:"<<ret<<endl;
}
