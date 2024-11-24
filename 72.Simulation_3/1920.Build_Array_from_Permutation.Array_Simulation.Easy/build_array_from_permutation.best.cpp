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
        int n = nums.size();
        for(int i=0; i<n; i++) {
            nums[i] += n * (nums[nums[i]] % n);
        }
        for(int i=0; i<n; i++) {
            nums[i] /= n;
        }
        return nums;
    }
};
