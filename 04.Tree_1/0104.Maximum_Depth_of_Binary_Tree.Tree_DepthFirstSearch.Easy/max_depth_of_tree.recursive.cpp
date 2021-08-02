/*******************************************************************************
 *      file name: max_depth_of_tree.recursive.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/08-11:11                                    
 * modified time: 17/11/08-11:11                                    
 *******************************************************************************/
#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return (1 + maxDepth(root->left) > 1 + maxDepth(root->right))? 1 + maxDepth(root->left) : 1 + maxDepth(root->right);
    }
};
