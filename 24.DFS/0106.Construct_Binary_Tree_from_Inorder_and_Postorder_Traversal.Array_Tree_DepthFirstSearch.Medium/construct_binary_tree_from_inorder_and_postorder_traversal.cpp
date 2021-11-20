/*******************************************************************************
 *      file name: construct_binary_tree_from_inorder_and_postorder_traversal.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/01-10:07:03                              
 *  modified time: 2019/04/01-10:07:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bt(vector<int>::iterator post_i, vector<int>::iterator post_j, vector<int>::iterator in_i, vector<int>::iterator in_j) {
		if (post_i == post_j || in_i == in_j) return NULL;
		int r = *(post_j - 1);
		TreeNode* root = new TreeNode(r);
		vector<int>::iterator result = find(in_i, in_j, r); 
		if (result == in_j) return root;
		int size = result - in_i;
		root->left = bt(post_i, post_i + size, in_i, result);
		root->right = bt(post_i+size, post_j-1, result+1, in_j);
		return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.empty() || inorder.empty()) return NULL;
		vector<int>::iterator pre_i = postorder.begin(); 
		vector<int>::iterator pre_j = postorder.end(); 
		vector<int>::iterator in_i = inorder.begin();
		vector<int>::iterator in_j = inorder.end();
		return bt(pre_i, pre_j, in_i, in_j);
    }
};
int main()
{}
