/*******************************************************************************
 *      file name: search_in_rotated_sorted_array_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/28-09:24:34                              
 *  modified time: 2019/03/28-09:24:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n =  nums.size();
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while (lo<=hi) {
            cout<<"lo:"<<lo<<"  hi:"<<hi<<endl;
            if (lo == hi) 
            {
                if (lo + 1 < n && nums[lo] > nums[lo+1])
                    lo++;
                break;
            }
            int mid=(lo+hi)/2;
            cout<<"mid:"<<mid<<endl;
            if(nums[mid]==nums[hi]) 
            {
                lo =  mid;
                while(lo < hi && nums[lo] == nums[hi]) lo++; 
                if (nums[lo] < nums[hi]) break;
            }
            else if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }
        while(lo >= 1 && nums[lo] >= nums[lo-1]) lo--; 
        cout<<"rotate:"<<lo<<endl;
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            cout<<"lo:"<<lo<<"  hi:"<<hi<<" mid:"<<mid<<"   realmid:"<<realmid<<endl;
            if(nums[realmid]==target)return true;
            if(nums[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
};
int main()
{}
