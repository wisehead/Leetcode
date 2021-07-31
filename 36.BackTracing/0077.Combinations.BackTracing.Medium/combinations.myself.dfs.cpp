/*******************************************************************************
 *      file name: combinations.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/24-10:53:54                              
 *  modified time: 2020/10/24-10:53:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; 
        vector<int> temp;
        dfs(res, temp, 1, n, k);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, int start, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            dfs(res, temp, i+1, n, k);
            temp.pop_back();
        }
    }
};
int main()
{}
