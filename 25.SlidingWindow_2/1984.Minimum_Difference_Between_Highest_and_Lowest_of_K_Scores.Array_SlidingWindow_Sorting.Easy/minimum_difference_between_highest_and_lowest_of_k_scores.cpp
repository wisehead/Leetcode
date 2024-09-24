/*******************************************************************************
 *      file name: minimum_difference_between_highest_and_lowest_of_k_scores.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/24- 9:09                                    
 * modified time: 24/09/24- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = nums[k-1] - nums[0];
        for (int i = 1; i < nums.size()-k+1; i++) {
            ret = min(ret, nums[i+k-1] - nums[i]);
        }
        return ret;
    }
};
