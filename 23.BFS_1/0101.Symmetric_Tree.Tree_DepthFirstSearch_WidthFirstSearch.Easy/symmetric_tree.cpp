/*******************************************************************************
 *      file name: symmetric_tree.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/08-11:11                                    
 * modified time: 17/11/08-11:11                                    
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
		stack<TreeNode*> p_stack;
		stack<TreeNode*> q_stack;
		TreeNode* p = NULL;
		TreeNode* q = NULL;
		if (!root->left || !root->right )
			return root->left == root->right;
		p_stack.push(root->left);
		q_stack.push(root->right);
		while(!p_stack.empty() && !q_stack.empty() )
		{
			p = p_stack.top();
			q = q_stack.top();
			p_stack.pop();
			q_stack.pop();
			if (p->val != q->val)
				return false;
			if (p->left)
				p_stack.push(p->left);
			if (q->right)
				q_stack.push(q->right);
			if (p_stack.size() != q_stack.size())
				return false;

			if (p->right)
				p_stack.push(p->right);
			if (q->left)
				q_stack.push(q->left);
			if (p_stack.size() != q_stack.size())
				return false;
		}
		return p_stack.size() == q_stack.size() ;
		
    }
};
int main()
{}
