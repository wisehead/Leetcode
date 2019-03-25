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
        vector<vector<int>> ans;
        vector<int> cur;
        subsets(nums, ans, cur);
        return ans;
    }
private:
    void subsets(vector<int> nums, vector<vector<int>>& result, vector<int>& cur){
        while(nums.size()){
            cur.push_back(nums[0]);
            nums.erase(nums.begin());
            subsets(nums, result, cur);
            cur.pop_back();
        }
        result.push_back(cur);
    }
};
int main()
{}
