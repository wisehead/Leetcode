/*******************************************************************************
 *      file name: sum_root_to_leaf_numbers.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/03-19:44:15                              
 *  modified time: 2021/12/03-19:44:15                              
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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int cur) {
        cur = cur*10 + root->val;
        if (!root->left && !root->right) return cur; 
        int sum = 0;
        if (root->left) 
            sum += dfs(root->left, cur);
        if (root->right)
            sum += dfs(root->right, cur);
        return sum;
    }
    
    
};
int main()
{}
