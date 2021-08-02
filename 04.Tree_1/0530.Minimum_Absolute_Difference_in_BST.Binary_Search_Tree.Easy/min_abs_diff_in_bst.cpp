/*******************************************************************************
 *      file name: min_abs_diff_in_bst.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/22-10:40:50                              
 *  modified time: 2018/08/22-10:40:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> tranverse(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		vector<int> res_left;
		vector<int> res_right;
		if (root->left)
		{
			res_left = tranverse(root->left);
			res.insert(res.end(), res_left.begin(), res_left.end());
		}
		res.push_back(root->val);
		if (root->right)
		{
			res_right = tranverse(root->right);
			res.insert(res.end(), res_right.begin(), res_right.end());
		}
		return res;
	}
    int getMinimumDifference(TreeNode* root) {
		vector<int> vec = tranverse(root);
		if (vec.size() < 2)
			return -1;
		int min = abs(vec[1] - vec[0]);
		for (int i = 1; i < vec.size(); i++)
		{
			int delta = vec[i] - vec[i-1]; 
			if (delta < min)
				min = delta;
		}
		return min;
    }
};
int main()
{}
