/*******************************************************************************
 *      file name: permutations_II.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/24-09:34:57                              
 *  modified time: 2020/10/24-09:34:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> p(vector<int> nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size == 0) return res;
        if (size == 1) {
            vector<int> vec;
            vec.push_back(nums[0]);
            res.push_back(vec);
            return res;
        }
        
        int x = nums[0];
        vector<int> new_nums(nums.begin()+1, nums.end());
        vector<vector<int>> v = p(new_nums);
        for (auto v1 : v) {
            for (int i = 0; i <= v1.size(); i++) {
                vector<int> v2 = v1;
                v2.insert(v2.begin()+i, x);
                res.push_back(v2);
            }
            
        }
        return res;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> vec = p(nums);
        set<vector<int>> st(vec.begin(), vec.end());
        vec.assign(st.begin(),st.end());
        return vec;
    }
};
int main()
{}
