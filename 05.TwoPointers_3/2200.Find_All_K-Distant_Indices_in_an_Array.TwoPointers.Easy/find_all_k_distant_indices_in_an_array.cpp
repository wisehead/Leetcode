/*******************************************************************************
 *      file name: find_all_k_distant_indices_in_an_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/31-12:12                                    
 * modified time: 24/12/31-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = max(0, i-k); j < min(n,i+k+1); j++) {
                if (nums[j] == key) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
