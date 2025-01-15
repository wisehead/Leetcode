/*******************************************************************************
 *      file name: contains_duplicate_III.timeout.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/14-21:15:19                              
 *  modified time: 2021/08/14-21:15:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    long get_min_delta(set<int> & ss) {
        if (ss.size() ==0 ) return (long)(INT_MAX)*2;
        set<int>::iterator it = ss.begin();
        long minv = (long)(INT_MAX)*2;
        int prev = *it;
        it++;
        for (; it != ss.end(); it++) {
            long delta = (long)*it - (long)prev;
            if (delta < minv) minv = delta;
            prev = *it;
        }
        return minv;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> ss;
        for (int i = 0; i <= k && i < nums.size(); i++) {
            if (ss.count(nums[i])) return true;
            ss.insert(nums[i]);
        }
        long minv = get_min_delta(ss);
        //cout<<"minv:"<<minv<<endl;
        if (minv <= t) return true;

        for (int x = k+1; x < nums.size(); x++) {
            if (x-k-1>=0 ) ss.erase(nums[x-k-1]);
            if (ss.count(nums[x])) return true;
            ss.insert(nums[x]);

            long minv = get_min_delta(ss);
            //cout<<"x:"<<x<<",minv:"<<minv<<endl;
            if (minv <= t) return true;
        }
        return false;

    }
};
int main()
{}
