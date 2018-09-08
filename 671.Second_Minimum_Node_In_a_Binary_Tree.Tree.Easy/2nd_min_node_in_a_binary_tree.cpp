/*******************************************************************************
 *      file name: 2nd_min_node_in_a_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/09-00:16:56                              
 *  modified time: 2018/09/09-00:16:56                              
 *******************************************************************************/
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * s
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
    int findSecondMinimumValue(TreeNode* root) {
		if (!root) return -1;
		if (!root->left) return -1;
		if (root->left->val == root->right->val)
		{
			int temp_l = findSecondMinimumValue(root->left);
			int temp_r = findSecondMinimumValue(root->right);
			if (temp_l == -1 || temp_r == -1)
			{
				if (temp_l == -1) return temp_r;
				return temp_l;
			}
			else
				return min(temp_l, temp_r);
		}	
		if (root->val == root->left->val)
		{
			int sec_min = root->right->val;
			int temp = findSecondMinimumValue(root->left);
			if (temp == -1) return sec_min;
			return min(sec_min, temp);
		}
		else//root->val == root->right->val
		{
			int sec_min = root->left->val;
			int temp = findSecondMinimumValue(root->right);
			if (temp == -1) return sec_min;
			return min(sec_min, temp);
		}
			
    }
};
int main()
{}
