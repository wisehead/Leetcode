/*******************************************************************************
 *      file name: construct_tree_from_preorder_and_inorder_traversal.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/30-09:22:58                              
 *  modified time: 2019/03/30-09:22:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
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
    TreeNode* bt(vector<int>::iterator pre_i, vector<int>::iterator pre_j, vector<int>::iterator in_i, vector<int>::iterator in_j) {
		if (pre_i == pre_j || in_i == in_j) return NULL;
		int r = *pre_i;
		TreeNode* root = new TreeNode(r);
		vector<int>::iterator result = find(in_i, in_j, r); 
		if (result == in_j) return root;
		int size = result - in_i;
		root->left = bt(pre_i+1, pre_i + 1 + size, in_i, result);
		root->right = bt(pre_i+1+size, pre_j, result+1, in_j);
		return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return NULL;
		vector<int>::iterator pre_i = preorder.begin(); 
		vector<int>::iterator pre_j = preorder.end(); 
		vector<int>::iterator in_i = inorder.begin();
		vector<int>::iterator in_j = inorder.end();
		return bt(pre_i, pre_j, in_i, in_j);
    }
};
int main()
{}
