/*******************************************************************************
 *      file name: bst_paths.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/30-12:12                                    
 *  modified time: 17/12/30-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <sstream> 
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
	TreeNode* getParent(TreeNode* root, TreeNode* x)
	{
		if (root == NULL)
			return NULL;
		if (root->left == x || root->right == x)
			return root;
		//return  (getParent(root->left, x) ||  getParent(root->left, x));
		TreeNode* ret_left =  getParent(root->left, x);
		if (ret_left)
			return ret_left;
		return  getParent(root->right, x);
	}

    vector<string> binaryTreePaths(TreeNode* root) 
	{
		stack<TreeNode*> s;
		stack<string> path_stack;
		vector<string> ret;
		if (root == NULL)
			return ret;
		s.push(root);
		path_stack.push(to_string(root->val));

		while (!s.empty())
		{
			TreeNode* cur = s.top(); s.pop();
			string path = path_stack.top(); path_stack.pop();
			if (cur->left == NULL && cur->right == NULL)
			{
				ret.push_back(path);
			}
			
			if (cur->left)
			{
				s.push(cur->left);
				path_stack.push(path + "->" + to_string(cur->left->val));
			}

			if (cur->right)
			{
				s.push(cur->right);
				path_stack.push(path + "->" + to_string(cur->right->val));
			}
		}
		return ret;
	}
};

int main()
{
	Solution sol;
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n5;
	vector<string> ret;
	ret = sol.binaryTreePaths(&n1);
	vector<string>::iterator it;
	for(it = ret.begin(); it != ret.end(); it++)
	{
		cout<<"ret :"<<*it<<endl;
	}
}
