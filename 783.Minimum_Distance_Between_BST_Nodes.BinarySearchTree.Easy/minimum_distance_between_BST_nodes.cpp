/*******************************************************************************
 *      file name: minimum_distance_between_BST_nodes.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/05-12:47:35                              
 *  modified time: 2018/10/05-12:47:35                              
 *******************************************************************************/
#include <iostream>
//#include <algorithm>
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
	void dsf(TreeNode* root, int& minv, int& maxv, int& min_diff) {
		if (!root) return;
		int left_min = INT_MIN, left_max = INT_MAX, left_min_diff = INT_MAX;
        dsf(root->left, left_min, left_max, left_min_diff);
		int right_min = INT_MIN, right_max = INT_MAX, right_min_diff = INT_MAX;
        dsf(root->right, right_min, right_max, right_min_diff);
        minv = root->val;
        maxv = root->val;
        min_diff = INT_MAX;
        if (root->left)
        {
            cout<<"root->val:"<<root->val<<"   left_min_diff:"<<left_min_diff<<"  left_max:"<<left_max<<endl;
            min_diff = min(left_min_diff, root->val - left_max);
            minv = left_min;
        }
        if (root->right)
        {
            cout<<"root->val:"<<root->val<<"   right_min_diff:"<<right_min_diff<<"  right_min:"<<right_min<<endl;
            min_diff = min(min_diff, right_min_diff);
            min_diff = min(min_diff, right_min - root->val);
            maxv = right_max;
        }
        /*
		min_diff = min(root->val - left_max, right_min - root->val);
		min_diff = min(min_diff, left_min_diff);
		min_diff = min(min_diff, right_min_diff);
		minv = left_min;
		maxv = right_max;
        */
        cout<<"root->val:"<<root->val<<"   minv:"<<minv<<"  maxv:"<<maxv<<" min_diff:"<<min_diff<<endl;
	}

    int minDiffInBST(TreeNode* root) {
		int minv = INT_MIN, maxv = INT_MAX, min_diff = INT_MAX;
		dsf(root, minv, maxv, min_diff);
		return min_diff;
    }
};
int main()
{}
