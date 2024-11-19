/*******************************************************************************
 *      file name: binary_tree_right_side_view.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/18-12:04:23                              
 *  modified time: 2021/12/18-12:04:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        int sum = 0;
        while (!q1.empty()) {
            TreeNode *back = q1.back();
            res.push_back(back->val);
            while (!q1.empty()) {
                TreeNode* node = q1.front();
                q1.pop();
                if (node->left) q2.push(node->left);
                if (node->right) q2.push(node->right);
            }
            swap(q1, q2);
        }
        return res;
    }
};
int main()
{}
