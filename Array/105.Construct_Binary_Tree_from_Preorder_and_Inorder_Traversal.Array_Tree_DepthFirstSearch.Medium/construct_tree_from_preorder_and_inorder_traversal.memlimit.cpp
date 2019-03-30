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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return NULL;
		int r = preorder[0];
		TreeNode* root = new TreeNode(r);
		vector<int>::iterator result = find(inorder.begin(), inorder.end(), r); 
		if (result == inorder.end()) return root;

		vector<int> in_l(inorder.begin(), result);
		vector<int> in_r(result+1, inorder.end());
		vector<int> pre_l(preorder.begin()+1, preorder.begin()+1+in_l.size());
		vector<int> pre_r(preorder.begin()+1+in_l.size(), preorder.end());
		root->left = buildTree(pre_l, in_l);
		root->right = buildTree(pre_r, in_r);
		return root;
    }
};
int main()
{}
