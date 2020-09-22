/*******************************************************************************
 *      file name: bin_tree_level_order.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/09-11:11                                    
 * modified time: 17/11/09-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
		vector<vector<int> > vec_out;
		stack<vector<int> > stack_out;
		if (root == NULL)
			return vec_out;
		TreeNode* p=NULL;
	   	queue<TreeNode*> myqueue;  
	   	queue<TreeNode*> myqueue_2;  
		myqueue.push(root);
		while(!myqueue.empty() || !myqueue_2.empty())
		{
			vector<int> vec;
			while(!myqueue.empty())
			{
			   p=myqueue.front();
			   myqueue.pop();
			   vec.push_back(p->val);
			   if(p->left)
				   myqueue_2.push(p->left);
			   if(p->right)
				   myqueue_2.push(p->right);
			}
			if(!vec.empty())
				stack_out.push(vec);

			vector<int> vec_2;
			while(!myqueue_2.empty())
			{
			   p=myqueue_2.front();
			   myqueue_2.pop();
			   vec_2.push_back(p->val);
			   if(p->left)
				   myqueue.push(p->left);
			   if(p->right)
				   myqueue.push(p->right);
			}
			if(!vec_2.empty())
				stack_out.push(vec_2);
		}
		while(!stack_out.empty())
		{
			vec_out.push_back(stack_out.top());
			stack_out.pop();
		}
		return vec_out;
    }
};
int main()
{}
