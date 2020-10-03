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
    TreeNode* bt(vector<int>& postorder, int post_r, vector<int>& inorder, int in_l, int len) {
        if (len == 0) return nullptr;
        int x = postorder[post_r];
        TreeNode* root = new TreeNode(x);
        for (int i = in_l; i < in_l + len; i++) {
            if (inorder[i] == x) {
                root->left = bt(postorder, post_r-1 -(in_l + len - i - 1), inorder, in_l, i-in_l);
                root->right = bt(postorder, post_r - 1, inorder, i+1, in_l + len - i - 1);
                break;
            }
        }
        return root;
    }    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return bt(postorder, inorder.size()-1, inorder, 0, inorder.size());
    }
};
int main()
{}
