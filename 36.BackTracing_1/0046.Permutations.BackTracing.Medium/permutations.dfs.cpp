/*******************************************************************************
 *      file name: permutations.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/24-08:54:34                              
 *  modified time: 2020/10/24-08:54:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visit(nums.size(), false);
        vector<int> temp;
        dfs(res, visit, temp, nums);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<bool>& visit, vector<int>& temp, vector<int> nums) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visit[i]) {
                visit[i] = true;
                temp.push_back(nums[i]);
                dfs(res, visit, temp, nums);
                temp.pop_back();
                visit[i] = false;                
            }

        }
    }    
};
int main()
{}
