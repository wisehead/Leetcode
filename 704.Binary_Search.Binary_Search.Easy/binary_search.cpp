/*******************************************************************************
 *      file name: binary_search.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-20:46:37                              
 *  modified time: 2018/09/21-20:46:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int len = nums.size();
		int i = 0, j = len - 1;
		while (i < j)
		{
		    int mid = (i + j)/2;
			cout<<"i:"<<i<<"	j:"<<j<<"	mid:"<<mid<<endl;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) 
			{
				i = mid + 1;
				continue;
			}
			else
				j = mid;
		}
        if (nums[i] == target) return i;
		return -1;
    }
};
int main()
{
	int arr[] = {-1,0,3,5,9,12};
	vector<int> vec(arr, arr+7);
	int target = 9;
	/*
	int arr[] = {-1,0,3,5,9,12};
	vector<int> vec(arr, arr+6);
	int target = 2;
	*/
	int ret = 0;
	Solution sol;
	ret = sol.search(vec, target);
	cout<<"target:"<<target<<"	ret:"<<ret<<endl;
}
