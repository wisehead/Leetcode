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
        vector<int> vec(501,0);
        for (auto n : nums) {
            vec[n]++;
        }
        for (auto n : vec) {
            //if (n % 2) return false;
            if (n & 0x01) return false;
        }
        return true;
    }
};
