/*******************************************************************************
 *      file name: longest_univalue_path.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/18-11:30:37                              
 *  modified time: 2018/09/18-11:30:37                              
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
	void lupath(TreeNode* root, int& max_depth, int& g_max ) {
		if (!root) return;
		int left_depth = 0, right_depth = 0;
		int left_gmax = 0, right_gmax = 0;
		lupath(root->left, left_depth, left_gmax);
		lupath(root->right, right_depth, right_gmax);
		if (root->left && root->right)
		{
			if (root->val == root->left->val && root->val == root->right->val)
			{
				g_max = max(g_max, left_depth + right_depth + 2);
			}
		}
		if (root->left)
		{
			if (root->left->val == root->val)
			{
				left_depth++;
				left_gmax = max(left_depth, left_gmax);
			}
			else{
				left_gmax = max(left_depth, left_gmax);
				left_depth = 0;
			}
		}
		if (root->right)
		{
			if (root->right->val == root->val)
			{
				right_depth++;
				right_gmax = max(right_depth, right_gmax);
			}
			else
			{
				right_gmax = max(right_depth, right_gmax);
				right_depth = 0;
			}
		}
		max_depth = max(left_depth, right_depth);
		g_max = max(left_gmax, g_max);
		g_max = max(g_max, right_gmax);
			
	}
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
		int max_depth = 0, g_max = 0;
		lupath(root, max_depth, g_max);
        //if (g_max == max_depth) g_max--;
        //if (root->left && root->right && root->left->val == root->val && root->right->val == root->val)
        //    g_max++;
		return g_max;
    }
};
int main()
{}
