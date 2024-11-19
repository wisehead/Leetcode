/*******************************************************************************
 *      file name: two_out_of_three.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/26- 9:09                                    
 * modified time: 24/09/26- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int,int> ht;
        set<int> st;
        vector<vector<int>> vv = {nums1, nums2, nums3};
        vector<int> res;
        for (auto v: vv) {
            for (auto n : v) {
                st.insert(n);
            }
            for (auto iter : st) {
                ht[iter]++;
            }
            st.clear();
        }

        for (auto iter : ht) {
            if (iter.second >= 2) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
};
