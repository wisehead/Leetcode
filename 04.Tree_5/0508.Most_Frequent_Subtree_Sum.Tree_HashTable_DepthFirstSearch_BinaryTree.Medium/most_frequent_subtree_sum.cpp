/*******************************************************************************
 *      file name: most_frequent_subtree_sum.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/19-11:11                                    
 * modified time: 24/11/19-11:11                                    
 *******************************************************************************/
#include <iostream>
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int ret = sum_subtree(root);
        vector<int> res;
        int max_cnt = 0;
        for (auto it : ht) {
            if (it.second == max_cnt) res.push_back(it.first);
            else if (it.second > max_cnt) {
                res.clear();
                max_cnt = it.second;
                res.push_back(it.first);
            }
        }
        return res;
    }
    int sum_subtree(TreeNode* root) {
        if (!root) return 0;
        int sum = sum_subtree(root->left) + sum_subtree(root->right) + root->val;
        ht[sum]++;
        return sum;
    }
public:
    unordered_map<int,int> ht;
};
