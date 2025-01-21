/*******************************************************************************
 *      file name: number_of_subarrays_that_match_a_pattern.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int cnt = 0;
        int m = pattern.size();
        int n = nums.size();
        for (int i = 0; i < n - m; i++) {
            bool flag = true;
            for (int j = i+1; j <= i+m; j++ ) {
                int p = pattern[j-i-1];
                // cout<<"i:"<<i<<",j:"<<j<<",p:"<<p<<",nums[j-1]:"<<nums[j-1]<<",nums[j]:"<<nums[j]<<endl;
                if (p == 0) {
                    if (nums[j] != nums[j-1]) {
                        flag = false;
                        break;
                    }
                } else if (p == 1) {
                    if (nums[j-1] >= nums[j]) {
                        flag = false;
                        break;
                    }
                } else {//p == -1
                    if (nums[j-1] <= nums[j]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};
