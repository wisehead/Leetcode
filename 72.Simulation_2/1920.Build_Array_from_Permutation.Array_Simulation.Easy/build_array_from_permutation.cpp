/*******************************************************************************
 *      file name: build_array_from_permutation.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/23- 9:09                                    
 * modified time: 24/09/23- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        for (auto n :  nums) {
            res.push_back(nums[n]);
        }
        return res;
    }
};
