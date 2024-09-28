/*******************************************************************************
 *      file name: binary_tree_zigzag_level_order_traversal.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/07-18:08:30                              
 *  modified time: 2021/08/07-18:08:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> ss[2];
        vector<vector<int>> res;
        int flag = 0;//true:left to right, false:right to left
        if (!root) return res;
        ss[0].push(root);
        while (!ss[0].empty() || !ss[1].empty()) {
            vector<int> vec;
            while (!ss[flag].empty()) {
                TreeNode* x = ss[flag].top();
                ss[flag].pop();
                vec.push_back(x->val);
                if (flag == 0) {
                    if (x->left) ss[1].push(x->left);
                    if (x->right) ss[1].push(x->right);
                } else {
                    if (x->right) ss[0].push(x->right); 
                    if (x->left) ss[0].push(x->left);
                }
            }//inner while
            res.push_back(vec);
            flag = 1 - flag;   
        }//outer while
        return res;
    }
};
int main()
{}
