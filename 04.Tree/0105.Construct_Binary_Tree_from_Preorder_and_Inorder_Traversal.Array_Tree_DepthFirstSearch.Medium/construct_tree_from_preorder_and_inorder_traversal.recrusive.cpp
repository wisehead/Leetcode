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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bt(preorder, 0, inorder, 0, preorder.size());
    }
    TreeNode* bt(vector<int>& preorder, int pre_l, vector<int>& inorder, int in_l, int len) {
        if (len == 0) return nullptr;
        int x = preorder[pre_l];
        TreeNode* root = new TreeNode(x);
        for (int i = in_l; i < in_l + len; i++) {
            if (inorder[i] == x) {
                root->left = bt(preorder, pre_l + 1, inorder, in_l, i-in_l);
                root->right = bt(preorder, pre_l + 1 + i - in_l, inorder, i+1, in_l + len - i - 1);
                break;
            }
        }
        return root;
    }
};
int main()
{}
