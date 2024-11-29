/*******************************************************************************
 *      file name: minimum_distance_to_the_target_element.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/17- 9:09                                    
 * modified time: 24/09/17- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_dis = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                min_dis = min(abs(i-start), min_dis);
            }
        }
        return min_dis;
    }
};
