/*******************************************************************************
 *      file name: minimum_subsequence_in_non_increasing_order.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/26-09:19:16                              
 *  modified time: 2021/09/26-09:19:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = 0;
        for (auto e : nums) total += e;
        int sum = 0;
        vector<int> res;
        for (int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            res.push_back(nums[i]);
            if (sum > total - sum) break;
        }
        return res;
    }
};
int main()
{}
