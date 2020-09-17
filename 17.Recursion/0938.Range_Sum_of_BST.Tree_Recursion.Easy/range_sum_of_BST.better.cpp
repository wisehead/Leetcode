/*******************************************************************************
 *      file name: range_sum_of_BST.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/09/04-11:10:08                              
 *  modified time: 2019/09/04-11:10:08                              
 *******************************************************************************/
#include <iostream>
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL) return 0; // base case.
        if (root->val < L) return rangeSumBST(root->right, L, R); // left branch excluded.
        if (root->val > R) return rangeSumBST(root->left, L, R); // right branch excluded.
        return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R); // count in both children.
    }
};

int main()
{}
