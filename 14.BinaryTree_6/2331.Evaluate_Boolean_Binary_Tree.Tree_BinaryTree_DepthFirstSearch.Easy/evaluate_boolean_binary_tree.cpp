/*******************************************************************************
 *      file name: evaluate_boolean_binary_tree.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/27- 9:09                                    
 * modified time: 24/09/27- 9:09                                    
 *******************************************************************************/
#include <iostream>
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
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val == 1;
        }
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }

        return evaluateTree(root->left) && evaluateTree(root->right);

    }
};
