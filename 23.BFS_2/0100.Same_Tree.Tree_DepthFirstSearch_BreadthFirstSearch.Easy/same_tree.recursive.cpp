/*******************************************************************************
 *      file name: same_tree.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/07-11:11                                    
 * modified time: 17/11/07-11:11                                    
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p==NULL || q==NULL)
			return p==q;
		if (p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return false;
		/*
		stack<TreeNode*> mystack;
		TreeNode *p_left = NULL;
		TreeNode *p_right = NULL;
		if (p->val == q->val)
		{
			if(p->left)
			{
				re
			}
		}
		*/
    }
};

int main()
{
}
