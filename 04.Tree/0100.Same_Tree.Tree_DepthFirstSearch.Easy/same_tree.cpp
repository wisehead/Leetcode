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
	TreeNode* init_tree(int array[], int len)
	{
		//TreeNode* tree_array = (TreeNode*)malloc(len * sizeof(TreeNode*));
		TreeNode* tree_array[10] = {0};
		for(int i=0; i<len; i++)
		{
			tree_array[i] = new TreeNode(array[i]);
		}
		tree_array[1] = NULL;
		tree_array[0]->left = tree_array[1];
		tree_array[0]->right = tree_array[2];
		return tree_array[0];
	}
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p==NULL || q==NULL)
			return p==q;
		stack<TreeNode*> p_stack;
		stack<TreeNode*> q_stack;
		TreeNode *p_ptr = p;
		TreeNode *q_ptr = q;
		if (p_ptr->val != q_ptr->val)
		{
			return false;
		}
push_loop:
		while (p_ptr && q_ptr)
		{
			p_stack.push(p_ptr);
			q_stack.push(q_ptr);
			p_ptr = p_ptr->left;
			q_ptr = q_ptr->left;
		}
		if (p_ptr != q_ptr)
			return false;
		while(!p_stack.empty() && !q_stack.empty())
		{
			p_ptr = p_stack.top();
			q_ptr = q_stack.top();
			p_stack.pop();
			q_stack.pop();
			if (p_ptr->val != q_ptr->val)
				return false;
			if (p_ptr->right && q_ptr->right)
			{
				p_ptr = p_ptr->right;
				q_ptr = q_ptr->right;
				goto push_loop;
			}
			else if(p_ptr->right==NULL && q_ptr->right==NULL)
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		/*
		if (p->val != q->val)
		{
			return false;
		}
		if (p->left)
		{
			p_stack.push(p->left);
		}
		*/
		return true;
    }
};

int main()
{
	Solution sol;
	int array1[] = {12,0,-70};
	int array2[] = {12,0,60};
	TreeNode* tree1 = sol.init_tree(array1, 3);
	TreeNode* tree2 = sol.init_tree(array2, 3);
	bool ret = false;
	ret = sol.isSameTree(tree1,tree2);
	cout<<"the result is:"<<ret<<endl;
	/*
	tree1 = sol.init_tree(array1, 1);
	tree2 = sol.init_tree(array2, 1);
	ret = sol.isSameTree(tree1,NULL);
	cout<<"the result is:"<<ret<<endl;
	*/
}
