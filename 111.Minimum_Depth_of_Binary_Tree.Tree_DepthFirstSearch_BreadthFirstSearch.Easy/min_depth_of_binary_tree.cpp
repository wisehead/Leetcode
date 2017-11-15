/*******************************************************************************
 *      file name: min_depth_of_binary_tree.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/15-11:11                                    
 * modified time: 17/11/15-11:11                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return 1;
        if (!root->left || !root->right)
        {
            if(!root->left)
                return 1+minDepth(root->right);
            if(!root->right)
                return 1+minDepth(root->left);
        }
		int depth_left = minDepth(root->left);
		int depth_right = minDepth(root->right);
		return 1 + ((depth_left > depth_right)? depth_right:depth_left);
    }
};
int main()
{}
