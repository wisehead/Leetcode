/*******************************************************************************
 *      file name: divide_array_into_equal_pairs.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/28- 9:09                                    
 * modified time: 24/09/28- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

       for(int i = 0; i < n; i += 2){
           if((nums[i]^nums[i+1]) != 0)
                return false;
       }
       return true;
    }
};
