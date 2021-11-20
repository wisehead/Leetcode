/*******************************************************************************
 *      file name: subsets.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/25-09:56:29                              
 *  modified time: 2019/03/25-09:56:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.reserve(nums.size());
        for (int i = 0; i < 1 << nums.size(); i++) {
            int n = i;
            
            int j = 0;
            vector<int> subset;
            while (n > 0) {
                if (n & 1) {
                    subset.push_back(nums[j]);
                }
                n >>= 1;
                ++j;
            }
            result.push_back(subset);
        }
        return result;
    }
};
int main()
{}
