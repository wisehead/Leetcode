/*******************************************************************************
 *      file name: search_in_a_BST.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-18:06:04                              
 *  modified time: 2018/09/21-18:06:04                              
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
    TreeNode* searchBST(TreeNode* root, int val) {
		if (!root) return NULL;
		if (root->val == val) return root;
		if (val < root->val) return searchBST(root->left, val);
		//if (val > root->val) 
		return searchBST(root->right, val);
    }
};
int main()
{}
