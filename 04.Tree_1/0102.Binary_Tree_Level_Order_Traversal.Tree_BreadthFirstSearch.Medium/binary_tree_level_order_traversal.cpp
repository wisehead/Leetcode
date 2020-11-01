/*******************************************************************************
 *      file name: binary_tree_level_order_traversal.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/01-09:11:00                              
 *  modified time: 2020/11/01-09:11:00                              
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> q2;
            vector<int> vec;
            while (!q.empty()) {
                TreeNode* p = q.front();
                q.pop();
                vec.push_back(p->val);
                if (p->left) q2.push(p->left);
                if (p->right) q2.push(p->right);
            } 
            res.push_back(vec);
            q.swap(q2);
        }
        return res;

    }
private:
    queue<TreeNode*> q;
};
int main()
{}
