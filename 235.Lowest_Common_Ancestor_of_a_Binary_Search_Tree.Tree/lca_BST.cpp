/*******************************************************************************
 *      file name: lca_BST.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/29-12:12                                    
 *  modified time: 17/12/29-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;
		vector<TreeNode*> vec_p;
		vector<TreeNode*> vec_q;
		stack<TreeNode*> m_stack;
		TreeNode* t = NULL;

		TreeNode* parent = p;
		while (parent != root)
		{
			vec_p.push_back(parent);
			cout<<"path for p:"<<parent->val<<endl;
			parent = getParent(root, parent); 
		}

		parent = q;
		while (parent != root)
		{
			vec_q.push_back(parent);
			cout<<"path for q:"<<parent->val<<endl;
			parent = getParent(root, parent); 
		}

		vector<TreeNode*>::iterator it_q;
		vector<TreeNode*>::iterator it_p;
		for (it_q = vec_q.begin(); it_q != vec_q.end(); it_q++)
		{
			for (it_p = vec_p.begin(); it_p != vec_p.end(); it_p++)
			{
				if (*it_p == *it_q)
					return *it_p;
			}
		}
		return root; 
    }
};
int main()
{
	Solution sol;
	TreeNode node1(2);
	TreeNode node2(1);
	TreeNode node3(3);

	node1.left = &node2;
	node1.right = &node3;

	TreeNode* ret;
	ret = sol.lowestCommonAncestor(&node1, &node2, &node3);
	cout<<"ret is:"<<ret->val<<endl;
}

