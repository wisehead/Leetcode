/*******************************************************************************
 *      file name: convert_sorted_array_2_BST.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/13-11:11                                    
 * modified time: 17/11/13-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        int mid = nums.size()/2;
        TreeNode *node = new TreeNode(nums[mid]);
        vector<int> v_left(nums.begin(), nums.begin() + mid);
        node->left = sortedArrayToBST(v_left);

        vector<int> v_right(nums.begin()+mid+1, nums.end());
        node->right = sortedArrayToBST(v_right);
        return node;
    }
};
