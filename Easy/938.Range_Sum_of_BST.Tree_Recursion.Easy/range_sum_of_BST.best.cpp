/*******************************************************************************
 *      file name: range_sum_of_BST.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/09/04-11:10:08                              
 *  modified time: 2019/09/04-11:10:08                              
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
    int rangeSumBST(TreeNode* root, int L, int R) {
		if (!root) return 0;
		int sum = 0;
		if (root->val >= L && root->val <= R) sum += root->val;
		sum += rangeSumBST(root->left, L, R);
		sum += rangeSumBST(root->right, L, R);
		return sum; 
    }
};

int main()
{}
