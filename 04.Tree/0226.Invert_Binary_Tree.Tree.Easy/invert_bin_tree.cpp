/*******************************************************************************
 *      file name: invert_bin_tree.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/25-12:12                                    
 *  modified time: 17/12/25-12:12                                    
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
    TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		TreeNode* temp = NULL;
		temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(temp);
		return root;
    }
};
int main()
{}
