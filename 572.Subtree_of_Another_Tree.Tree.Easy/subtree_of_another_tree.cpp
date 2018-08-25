/*******************************************************************************
 *      file name: subtree_of_another_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-17:26:36                              
 *  modified time: 2018/08/25-17:26:36                              
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
    bool isSametree(TreeNode* s, TreeNode* t) {
		if (!s && !t)
			return true;
		if ((!s && t) || (s && !t))
			return false;
		if (s->val != t->val)
			return false;
		return (isSametree(s->left, t->left) && isSametree(s->right, t->right));
	}
    bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s)
			return false;
		if (s->val == t->val)
		{
			if (isSametree(s, t))
				return true;
		}
	    return (isSubtree(s->left, t) || isSubtree(s->right, t));
	}
};
int main()
{}
