/*******************************************************************************
 *      file name: find_minium_in_rotated_sorted_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/04-09:30:59                              
 *  modified time: 2019/04/04-09:30:59                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
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
		return lo;
    }
};
int main()
{}
