/*******************************************************************************
 *      file name: binary_tree_tilt.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-17:03:19                              
 *  modified time: 2018/08/25-17:03:19                              
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
    void findTiltXX(TreeNode* root, int& valsum, int& tiltsum) {
		if (!root)
			return;
		/*
		if (!root->left && !root->right)
		{
			valsum += root->val;
		}
		*/
		int valsum_l = 0, tiltsum_l = 0;
		int valsum_r = 0, tiltsum_r = 0;
		int tilt = 0;
		if (root->left)
			findTiltXX(root->left, valsum_l, tiltsum_l);
		if (root->right)
			findTiltXX(root->right, valsum_r, tiltsum_r);
		valsum = valsum_l + valsum_r + root->val;
		tilt = abs(valsum_l - valsum_r);
		tiltsum = tiltsum_l + tiltsum_r + tilt;
	}
    int findTilt(TreeNode* root) {
		int valsum = 0, tiltsum = 0;
		findTiltXX(root, valsum, tiltsum);
		return tiltsum;
    }
};
int main()
{}
