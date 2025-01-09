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
        int n = nums.size();
        int max_v = nums[0], max_index = 0;
        int min_v = nums[0], min_index = 0;
        int max_l = 1;
        int start = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > max_v) {
                max_v = nums[i];
                max_index = i;
            }
            if (nums[i] < min_v) {
                min_v = nums[i];
                min_index = i;
            }
            if (max_v > min_v + limit) {
                if (max_index < min_index) {
                    start = max_index + 1;
                    while (nums[start] == max_v) start++;
                    max_v = nums[start];
                    max_index = start;
                    for (int j = start; j <= i; j++) {
                        if (nums[j] > max_v) {
                            max_v = nums[j];
                            max_index = j;
                        }
                    }

                } else if (max_index > min_index) {
                    start = min_index + 1;
                    while (nums[start] == min_v) start++;
                    min_v = nums[start];
                    min_index = start;
                    for (int j = start; j <= i; j++) {
                        if (nums[j] < min_v) {
                            min_v = nums[j];
                            min_index = j;
                        }
                    }
                }
            } else {
                int len = i - start + 1;
                max_l = max(max_l, len);
            }
        }
        return max_l;
    }
};
