/*******************************************************************************
 *      file name: longest_continous_subarray_with_absolute_diff_less_than_or_equal_to_limit.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/09- 1:01                                    
 * modified time: 25/01/09- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase;
        deque<int> decrease;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!increase.empty() && nums[right] < increase.back()) {
                increase.pop_back();
            }
            increase.push_back(nums[right]);

            while (!decrease.empty() && nums[right] > decrease.back()) {
                decrease.pop_back();
            }
            decrease.push_back(nums[right]);

            while (decrease.front() - increase.front() > limit) {
                if (nums[left] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front()) {
                    increase.pop_front();
                }
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
