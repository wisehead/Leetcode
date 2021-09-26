/*******************************************************************************
 *      file name: diameter_of_BT.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/23-12:34:48                              
 *  modified time: 2018/08/23-12:34:48                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
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
	void postorderTraverse(TreeNode* root, int& diameter, int& maxpath) {
		int diameter1 = 0, diameter2 = 0;
		int maxpath1 = 0, maxpath2 = 0;
        if (!root->left && !root->right)
        {
            diameter = 0;
            maxpath = 0;
            cout<<"node:"<<root->val<<"::   diameter:"<<diameter<<"  maxpath:"<<maxpath<<endl;
            return;
        }
            
		if (root->left != NULL) postorderTraverse(root->left, diameter1, maxpath1);
        cout<<"node:"<<root->val<<"::  diameter1:"<<diameter1<<"  maxpath1:"<<maxpath1<<endl;
		if (root->right != NULL) postorderTraverse(root->right, diameter2, maxpath2);
        cout<<"node:"<<root->val<<"::   diameter2:"<<diameter2<<"  maxpath2:"<<maxpath2<<endl;
		maxpath = (maxpath1 > maxpath2)? maxpath1+1 : maxpath2+1;
        if (root->left && root->right)
    		diameter = maxpath1 + maxpath2 + 2;
        else
            diameter = maxpath1 + maxpath2 + 1;
        diameter = max(diameter, diameter1);
        diameter = max(diameter, diameter2);
        cout<<"node:"<<root->val<<"::   diameter:"<<diameter<<"  maxpath:"<<maxpath<<endl;
        
	}
    int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		int diameter = 0, maxpath = 0;
		postorderTraverse(root, diameter, maxpath);
		return diameter;
    }
};
int main()
{}
