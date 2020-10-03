/*******************************************************************************
 *      file name: construct_binary_tree_from_preorder_and_postorder_trversal.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/03-12:43:15                              
 *  modified time: 2020/10/03-12:43:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return bt(pre, 0, post, 0, pre.size());
    }

    TreeNode* bt(vector<int>& pre, int pre_l, vector<int>& post, int post_l, int len) {
        if (len == 0) return nullptr;
        int x = pre[pre_l];
        TreeNode* root = new TreeNode(x);
        if (len == 1) return root;
        for (int i = post_l + len - 1; i >= post_l; i--) {
            if (post[i] == x) {
                int y = pre[pre_l + 1];
                for (int j = post_l; j < post_l + len; j++) {
                    if (post[j] == y) {
                        int len_left = j-post_l+1;
                        root->left = bt(pre, pre_l + 1, post, post_l, len_left);
                        root->right = bt(pre, pre_l + 1 + len_left, post, post_l + len_left, i - j -1);
                        break;
                    } 
                }
                break;
            }
        }
        return root;
    }
    
};
int main()
{}
