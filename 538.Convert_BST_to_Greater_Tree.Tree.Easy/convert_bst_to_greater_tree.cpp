/*******************************************************************************
 *      file name: convert_bst_to_greater_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/23-11:45:08                              
 *  modified time: 2018/08/23-11:45:08                              
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
	void postorderTraverse(TreeNode* root, int& maxval) {
		if (root->right != NULL) postorderTraverse(root->right, maxval);
		//if (val >= 0) min_dif = min(min_dif, root->val - val);
		root->val += maxval;
		maxval = root->val;
		if (root->left != NULL) postorderTraverse(root->left, maxval);
	}

    TreeNode* convertBST(TreeNode* root) {
		if (!root)
			return NULL;
		int maxval = 0;
		postorderTraverse(root, maxval);
		return root;
    }
};
int main()
{}
