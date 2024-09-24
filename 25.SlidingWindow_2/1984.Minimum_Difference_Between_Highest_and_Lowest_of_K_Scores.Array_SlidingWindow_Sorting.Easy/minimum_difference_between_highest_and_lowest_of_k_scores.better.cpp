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


        sort(nums.begin(),nums.end());
        int left = 0;
        int right = k-1;
        int res = INT_MAX;

        while(right<nums.size()){
            res = min(res,nums[right] - nums[left]);
            left++;
            right++;
        }

        return res;

    }
};
