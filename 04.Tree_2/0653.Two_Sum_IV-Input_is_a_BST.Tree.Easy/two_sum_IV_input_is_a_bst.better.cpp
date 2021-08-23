/*******************************************************************************
 *      file name: two_sum_IV_input_is_a_bst.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-15:03:43                              
 *  modified time: 2018/09/08-15:03:43                              
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
    bool is_in_tree(TreeNode* root, int x) {
        if (!root) return false;
        if (root->val == x) return true;
        if (x > root->val) return is_in_tree(root->right, x);
        return is_in_tree(root->left, x);
    }

    void tranverse(TreeNode* root) {
        if (!root) return;
        tranverse(root->left);
        vec.push_back(root->val);
        tranverse(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        tranverse(root);
        for (auto e : vec) {
            if (e != k-e && is_in_tree(root, k-e)) return true;
        }
        return false;
    }
private:
    vector<int> vec;
};
int main()
{}
