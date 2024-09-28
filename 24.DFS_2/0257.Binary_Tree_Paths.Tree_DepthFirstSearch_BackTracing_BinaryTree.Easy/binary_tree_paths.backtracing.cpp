/*******************************************************************************
 *      file name: bst_paths.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/30-12:12                                    
 *  modified time: 17/12/30-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <sstream> 
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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        bt(path, root);
        return res;
    }

    void bt(vector<int> path, TreeNode* root) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string str;
            for (int i = 0; i < path.size(); i++) {
                string s = to_string(path[i]);
                if (i == 0) str += s;
                else {
                    str += "->" + s;
                }
            }
            res.push_back(str);
            return;
        }
        bt(path, root->left);
        bt(path, root->right);
    }
    vector<string> res;
};
