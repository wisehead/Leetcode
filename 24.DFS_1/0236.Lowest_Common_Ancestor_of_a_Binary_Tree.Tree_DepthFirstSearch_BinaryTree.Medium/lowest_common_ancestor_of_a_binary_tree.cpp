/*******************************************************************************
 *      file name: lowest_common_ancestor_of_a_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/19-20:05:52                              
 *  modified time: 2021/12/19-20:05:52                              
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool ret1 = false, ret2 = false;
        TreeNode* node = dfs(ret1, ret2, root, p, q);
        return node;
    }
    
    TreeNode* dfs(bool& ret1, bool& ret2, TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val == p->val) ret1 = true;
        else if (root->val == q->val) ret2 = true;
        
        bool ret1_left = false, ret1_right = false;
        bool ret2_left = false, ret2_right = false;
        TreeNode* node1 = dfs(ret1_left, ret2_left, root->left, p, q);
        if (node1) return node1;
        
        TreeNode* node2 = dfs(ret1_right, ret2_right, root->right, p, q);
        if (node2) return node2;
        
        if (!ret1) ret1 = ret1_left || ret1_right;
        if (!ret2) ret2 = ret2_left || ret2_right;
        if (ret1 && ret2) return root;
        return NULL;
    }
};
int main()
{}
