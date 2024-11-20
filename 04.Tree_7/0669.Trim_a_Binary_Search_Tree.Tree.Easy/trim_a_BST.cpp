/*******************************************************************************
 *      file name: trim_a_BST.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-23:52:06                              
 *  modified time: 2018/09/08-23:52:06                              
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return NULL;
		if (root->val < L) return trimBST(root->right, L, R);
		if (root->val == L) {
			root->left = NULL;
			root->right = trimBST(root->right, L, R);
			return root;
		}
		if (root->val > L && root->val < R)
		{
			root->left = trimBST(root->left, L, root->val);
			root->right = trimBST(root->right, root->val, R);
			return root;
		}
		if (root->val == R)
		{
			root->right = NULL;
			root->left = trimBST(root->left, L, R);
			return root;
		}
		else if (root->val > R)
			return trimBST(root->left, L, R);
    }
};
int main()
{}
