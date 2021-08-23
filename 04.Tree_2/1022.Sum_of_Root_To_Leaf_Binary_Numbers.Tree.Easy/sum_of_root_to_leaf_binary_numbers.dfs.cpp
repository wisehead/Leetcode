/*******************************************************************************
 *      file name: sum_of_root_to_leaf_binary_numbers.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/17-14:17:00                              
 *  modified time: 2020/09/17-14:17:00                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    int sumRootToLeaf(TreeNode* root) {
        vector<int> vec;
        int res = 0;
        fun(res, vec, root);
        return res;
    }
    
    void fun(int& res, vector<int>& vec, TreeNode* root) {
        res = 0;
        if (!root) {
            return;
        }
        vec.push_back(root->val);
        if (!root->left && !root->right) {
            for (auto e : vec) {
                res = res*2 + e;
            }
            return;
        }
        
        int ret_l = 0, ret_r = 0;
        fun(ret_l, vec, root->left);
        if (root->left) vec.pop_back();
        fun(ret_r, vec, root->right);
        if (root->right) vec.pop_back();
        res = ret_l + ret_r;
    }
};

int main()
{}
