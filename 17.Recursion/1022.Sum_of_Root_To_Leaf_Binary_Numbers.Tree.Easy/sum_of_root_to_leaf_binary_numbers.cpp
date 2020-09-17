/*******************************************************************************
 *      file name: sum_of_root_to_leaf_binary_numbers.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/17-14:17:00                              
 *  modified time: 2020/09/17-14:17:00                              
 *******************************************************************************/
#include <iostream>
using namespace std;

//Definition for a binary tree node.
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
    int sumRootToLeaf(TreeNode* root) {
        return sum_tree(root,0);
    }
    
    int sum_tree(TreeNode* root, int parent_sum) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val + parent_sum;
        return sum_tree(root->left, (root->val + parent_sum)*2) + sum_tree(root->right, (root->val + parent_sum)*2);
    }
};
int main()
{}
