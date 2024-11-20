/*******************************************************************************
 *      file name: path_sum.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/15-11:11                                    
 * modified time: 17/11/15-11:11                                    
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
            return false;
		if (!root->left && !root->right)
		{
			if(sum == root->val)
				return true;
			else 
				return false;
		}
		return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};

int main()
{}
