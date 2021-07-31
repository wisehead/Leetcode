/*******************************************************************************
 *      file name: sum_of_left_leaves.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/03/01- 3:03                                    
 *  modified time: 18/03/01- 3:03                                    
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
    int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		int count = 0;
		TreeNode *l_child = root->left;
		TreeNode *r_child = root->right;
		if (l_child && !l_child->left && !l_child->right)
			count = l_child->val;
		return count + sumOfLeftLeaves(l_child) + sumOfLeftLeaves(r_child);
    }
};
int main()
{}
