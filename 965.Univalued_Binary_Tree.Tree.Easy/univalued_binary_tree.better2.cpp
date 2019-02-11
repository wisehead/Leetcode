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
    bool isUnivalTree(TreeNode* root, int val) {
		if (!root) return true;
		if (root->val != val) return false;
		return (isUnivalTree(root->left, val) && isUnivalTree(root->right, val));
	}
    bool isUnivalTree(TreeNode* root) {
		return isUnivalTree(root, root->val);
    }
};
int main()
{}
