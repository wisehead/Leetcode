/*******************************************************************************
 *      file name: count_special_quadruplets_array.best.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/05-11:11                                    
 * modified time: 24/11/05-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        int len = nums.size();

        unordered_map<int, int> count;
        count[nums[len-1] - nums[len-2]] = 1;

        for (int b = len - 3; b >= 1; b--) {
            for (int a = b - 1; a >= 0; a--) {
                res += count[nums[a] + nums[b]];
            }

            for (int x = len - 1; x > b; x--) {
                count[nums[x] - nums[b]]++;
            }
        }

        return res;
    }
};
