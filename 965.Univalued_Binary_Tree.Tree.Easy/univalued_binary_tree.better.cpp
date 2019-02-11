/*******************************************************************************
 *      file name: univalued_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/11-13:23:14                              
 *  modified time: 2019/02/11-13:23:14                              
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
    bool isUnivalTree(TreeNode* root) {
		if (!root) return true;
		if (root->left &&  root->left->val != root->val) return false;
		if (root->right && root->right->val != root->val) return false;
		return (isUnivalTree(root->left) && isUnivalTree(root->right));
    }
};
int main()
{}
