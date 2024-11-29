/*******************************************************************************
 *      file name: remove_one_element_to_make_the_array_strictly_increasing.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/22- 9:09                                    
 * modified time: 24/09/22- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        vector<int> vec;
        vec.push_back(-2);
        vec.push_back(-1);
        vec.insert(vec.end(), nums.begin(), nums.end());
        vec.push_back(2000);
        int n = vec.size();
        int count = 0;
        for (int i = 2; i < n-1; i++) {
            if (vec[i] <= vec[i-1]) {
                count++;
                if (vec[i] > vec[i-2]) continue;
                else if (vec[i+1] > vec[i-1]) continue;
                else return false;
            }
        }
        if (count <= 1)
            return true;
        return false;
    }
};
