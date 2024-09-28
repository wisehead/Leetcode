/*******************************************************************************
 *      file name: kth_smallest_element_in_a_BST.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/05-20:59:36                              
 *  modified time: 2021/12/05-20:59:36                              
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
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
    int find(TreeNode* root, int& k) {
        if (root) {
            int x = find(root->left, k);
            //return !k ? x : !--k ? root->val : find(root->right, k);
            if (!k) return x;
            if (!--k) return root->val;
            return find(root->right, k);
        }
        return 0;
    }
};
int main()
{}
