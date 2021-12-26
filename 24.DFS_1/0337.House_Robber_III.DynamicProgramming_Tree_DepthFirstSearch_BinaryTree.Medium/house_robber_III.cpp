/*******************************************************************************
 *      file name: house_robber_III.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/26-20:29:28                              
 *  modified time: 2021/12/26-20:29:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
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
    int rob(TreeNode* root) {
        return max(dfs(root,true), dfs(root,false));
    }
    
    int dfs(TreeNode* root, bool thief) {
        if (!root) return 0;
        
        if (thief) {
            if (mm1.count(root)) return mm1[root];
            int ret = root->val + dfs(root->left, false) + dfs(root->right, false);
            mm1[root] = ret;
            return ret;
        } else {
            if (mm0.count(root)) return mm0[root];
            int left1 = dfs(root->left, true);
            int left2 = dfs(root->left, false);
            int left = max(left1, left2);
            int right1 = dfs(root->right, true);
            int right2 = dfs(root->right, false);
            int right = max(right1, right2);
            mm0[root] = left + right;
            return left + right;
        }
    }
private:
    map<TreeNode*, int> mm1;
    map<TreeNode*, int> mm0;
};
int main()
{}
