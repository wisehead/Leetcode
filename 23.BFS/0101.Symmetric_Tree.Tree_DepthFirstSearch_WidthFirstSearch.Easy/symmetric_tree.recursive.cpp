/*******************************************************************************
 *      file name: symmetric_tree.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/08-11:11                                    
 * modified time: 17/11/08-11:11                                    
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
    bool isSymmetricTree(TreeNode* p, TreeNode* q) {
		if (p==NULL || q==NULL)
			return p==q;
		if (p->val == q->val)
			return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left);
		else
			return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetricTree(root->left, root->right);
    }
};
int main()
{}
