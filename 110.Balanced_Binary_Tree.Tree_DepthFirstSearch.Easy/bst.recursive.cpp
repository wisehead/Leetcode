/*******************************************************************************
 *      file name: bst.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/14-11:11                                    
 * modified time: 17/11/14-11:11                                    
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
    int height(TreeNode* root) {
       if (!root) 
		   return 0;
	   if (!root->left && !root->right) {
		   return 1;
	   } 
	   return 1+ (height(root->left) > height(root->right) ? height(root->left):height(root->right));
    }

    bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		int diff = height(root->left) - height(root->right);
		if ( diff > 1 ||  diff < -1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
    }
};
int main()
{}
