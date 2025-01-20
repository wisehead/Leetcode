/*******************************************************************************
 *      file name: number_of_longest_increasing_subsequence.DP.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/20- 1:01                                    
 * modified time: 25/01/20- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> lens;
    vector<int> cnts;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        lens.resize(n,1);
        cnts.resize(n,1);
        int max_len = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                if (lens[j]+1 > lens[i]) {
                    lens[i] = lens[j]+1;
                    max_len = max(max_len, lens[i]);
                    cnts[i] = cnts[j];
                } else if (lens[j]+1 == lens[i]) {
                    cnts[i] += cnts[j];
                }
            }
        }
        int len = lens[n-1];
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (lens[i] == max_len) {
                res += cnts[i];
            }
        }
        return res;
    }
};
