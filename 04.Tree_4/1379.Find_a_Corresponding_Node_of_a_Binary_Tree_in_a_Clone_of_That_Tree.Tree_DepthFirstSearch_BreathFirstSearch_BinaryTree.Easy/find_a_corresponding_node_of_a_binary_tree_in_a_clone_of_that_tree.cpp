/*******************************************************************************
 *      file name: find_a_corresponding_node_of_a_binary_tree_in_a_clone_of_that_tree.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/07/31- 7:07                                    
 * modified time: 22/07/31- 7:07                                    
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned) return NULL;
        if (target == original) return cloned;
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
