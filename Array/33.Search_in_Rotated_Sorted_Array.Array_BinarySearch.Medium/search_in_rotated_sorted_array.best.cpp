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
		int n =  nums.size();
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(nums[realmid]==target)return realmid;
            if(nums[realmid]<target)lo=mid+1;
            else hi=mid-1;
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
	int ret = sol.search(vec, target);
	cout<<"ret:"<<ret<<endl;
}
