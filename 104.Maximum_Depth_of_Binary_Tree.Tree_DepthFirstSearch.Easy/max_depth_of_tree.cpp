/*******************************************************************************
 *      file name: max_depth_of_tree.cpp                                               
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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        stack<TreeNode*> p_stack;
        TreeNode* p = NULL;
		int max = 0;
		root->val = 1;
		p_stack.push(root);
        while(!p_stack.empty())
        {
            p = p_stack.top();
            p_stack.pop();
			if (p->val > max)
				max = p->val;
            if (p->left)
			{
				p->left->val = p->val + 1;
                p_stack.push(p->left);
			}
            if (p->right)
			{
				p->right->val = p->val + 1;
                p_stack.push(p->right);
			}
        }
        return max ;
    }
};

int main()
{}
