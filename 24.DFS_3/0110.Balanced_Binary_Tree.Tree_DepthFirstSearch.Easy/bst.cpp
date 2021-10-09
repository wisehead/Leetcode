/*******************************************************************************
 *      file name: bst.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/14-11:11                                    
 * modified time: 17/11/14-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
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

	/*
    bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		stack<TreeNode*> my_stack;
		TreeNode *p = NULL;
		my_stack.push(root);
		while(!my_stack.empty())
		{
			p = my_stack.top();
			my_stack.pop();
			int diff = height(root->left) - height(root->right);
			if ( diff > 1 ||  diff < -1)
				return false;
			return true;
		}
    }
	*/
    bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		bool left_is_bst = isBalanced(root->left);
		bool right_is_bst = isBalanced(root->right);
		if (!left_is_bst || !right_is_bst)
			return false;
        int diff = height(root->left) - height(root->right);
        if ( diff > 1 ||  diff < -1)
            return false;
		return true;
	}
};
int main()
{}
