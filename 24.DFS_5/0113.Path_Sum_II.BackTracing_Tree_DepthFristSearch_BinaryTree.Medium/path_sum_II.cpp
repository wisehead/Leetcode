/*******************************************************************************
 *      file name: path_sum_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/04-17:40:40                              
 *  modified time: 2021/10/04-17:40:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> visited;
        int sum = 0;
        dfs(res, root, visited, sum, targetSum);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, TreeNode* root, vector<int> visited, int sum, int target) {
        if (!root) return;
        visited.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right && sum == target) {
            res.push_back(visited);
            return;
        }

        dfs(res, root->left,visited, sum, target);
        dfs(res, root->right,visited, sum, target);
    }
};
int main()
{}
