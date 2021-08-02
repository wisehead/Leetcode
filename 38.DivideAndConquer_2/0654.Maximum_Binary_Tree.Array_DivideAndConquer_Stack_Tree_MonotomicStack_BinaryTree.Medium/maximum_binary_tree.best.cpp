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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
        if (end == start) return NULL;
        int pos = 0;
        int max_val = INT_MIN;
        for (int i = start; i < end; i++)
            if (nums[i] > max_val)  {
                max_val = nums[i];
                pos = i;
            }
        //cout<<"max:"<<max_val<<",i:"<<i<<",start:"<<start<<",end:"<<end<<endl;
        TreeNode* root = new TreeNode(max_val);
        root->left = constructMaximumBinaryTree(nums, start, pos);
        root->right = constructMaximumBinaryTree(nums, pos+1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size());
    }
};
int main()
{}
