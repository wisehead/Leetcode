/*******************************************************************************
 *      file name: contains_duplicate_III.timeout.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/14-21:15:19                              
 *  modified time: 2021/08/14-21:15:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<long long> vec(nums.begin(), nums.end());
        for (int i = 1; i <= k; i++ ) {
            for (int j = 0; j < nums.size() - i;j ++) {
                long long delta = abs((long long)nums[j] - (long long)nums[j+i]);
                //delta = abs(delta);
                if (i == 1) {
                    vec[j] = delta;
                } else {
                    vec[j] = min(vec[j], vec[j+1]);
                    vec[j] = min(vec[j], delta);                    
                }

                if (vec[j] <= t) return true;
            }
        }
        return false;
        
    }
};
int main()
{}
