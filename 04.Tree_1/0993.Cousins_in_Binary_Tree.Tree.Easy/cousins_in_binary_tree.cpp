/*******************************************************************************
 *      file name: cousins_in_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/21-10:05:30                              
 *  modified time: 2019/02/21-10:05:30                              
 *******************************************************************************/
#include <iostream>
#include <queue>
#include <set>
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
    bool isCousins(TreeNode* root, int x, int y) {
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(root);
		while (!q1.empty() || !q2.empty())
		{
			set<int> s1;
			while (!q1.empty())
			{
				TreeNode* node = q1.front();
				q1.pop();
				if (node->left && node->right)
				{
					if ((node->left->val == x && node->right->val == y)
						|| (node->left->val == y && node->right->val == x) ) 
						return false;
				}
				if (node->left) q2.push(node->left);
				if (node->right) q2.push(node->right);
				s1.insert(node->val);
			}
			if (s1.count(x) && s1.count(y)) return true;
			while (!q2.empty())
			{
				TreeNode* pt = q2.front();
				q2.pop();
				q1.push(pt);
			}
		}
		return false;
    }
};
int main()
{}
