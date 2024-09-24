/*******************************************************************************
 *      file name: find_greatest_common_divisor_of_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/24- 9:09                                    
 * modified time: 24/09/24- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int y = nums[0];
        int x = nums[0];
        for (auto n : nums) {
            if (n < y) y = n;
            if (n > x) x = n;
        }

        int n = x % y;
        while (n != 0) {
            x = y;
            y = n;
            n = x % y;
        }
        return y;
    }
};
