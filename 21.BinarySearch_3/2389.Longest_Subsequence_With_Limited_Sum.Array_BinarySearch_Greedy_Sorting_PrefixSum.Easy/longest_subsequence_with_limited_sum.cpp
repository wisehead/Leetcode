/*******************************************************************************
 *      file name: longest_subsequence_with_limited_sum.best.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/05-11:11                                    
 * modified time: 24/11/05-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        for (auto q: queries) {
            int sum = 0, i = 0;
            for (i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (sum == q) i++;
                if (sum >= q) break;
            }
            res.push_back(i);
        }
        return res;
    }
};
