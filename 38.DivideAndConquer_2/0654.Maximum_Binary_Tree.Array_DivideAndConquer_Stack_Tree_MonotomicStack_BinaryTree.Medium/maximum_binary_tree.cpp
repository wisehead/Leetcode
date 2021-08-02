/*******************************************************************************
 *      file name: maximum_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/02-07:35:23                              
 *  modified time: 2021/08/02-07:35:23                              
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
    int get_max(vector<int>& vec, int& pos) {
        int ret = INT_MIN;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] > ret) {
                pos = i;
                ret = vec[i];
            };
        }
        return ret;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        int pos = 0;
        int max_val = get_max(nums, pos);
        TreeNode* root = new TreeNode(max_val);
        vector<int> vec_left(nums.begin(), nums.begin()+pos);
        root->left = constructMaximumBinaryTree(vec_left);
        vector<int> vec_right(nums.begin()+pos+1, nums.end());                                       
        root->right = constructMaximumBinaryTree(vec_right);
        return root;
    }
};
int main()
{}
