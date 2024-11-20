/*******************************************************************************
 *      file name: same_tree.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/07-11:11                                    
 * modified time: 17/11/07-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p); q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            p = q1.front();q1.pop();
            q = q2.front();q2.pop();
            if (!p || !q) {
                if (p != q) return false;
                continue;
            }
            if (p->val != q->val) return false;
            q1.push(p->left);q1.push(p->right);
            q2.push(q->left);q2.push(q->right);
        }
        // return q1.empty() && q2.empty();
        return true;
    }
};
