/*******************************************************************************
 *      file name: contains_duplicate_III.best.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/15-09:10:56                              
 *  modified time: 2021/08/15-09:10:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
/*
 bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window; // set is ordered automatically 
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
        // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
        auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
        // x - nums[i] <= t ==> |x - nums[i]| <= t    
        if (pos != window.end() && *pos - nums[i] <= t) return true;
        window.insert(nums[i]);
    }
    return false;
}
*/
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            long n = nums[i];
            
            if (i > k)
                window.erase(nums[i-k-1]);
            
            auto pos = window.lower_bound(n - t);
            
            if (pos != window.end() && (*pos - n) <= t)
                return true;
            
            window.insert(n);
        }
        return false;
    }    
};
int main()
{}
