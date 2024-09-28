/*******************************************************************************
 *      file name: convert_sorted_array_2_BST.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/13-11:11                                    
 * modified time: 17/11/13-11:11                                    
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
    TreeNode* fun(vector<int>& nums, int l, int r) {
        if (l >= r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        //if (l == r) return root;
        root->left = fun(nums, l, mid);
        root->right = fun(nums, mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums, 0, nums.size());
    }
};
int main()
{}
