/*******************************************************************************
 *      file name: balance_a_binary_search_tree.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/10- 1:01                                    
 * modified time: 25/01/10- 1:01                                    
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vec;
        tranverse(vec, root);
        int n = vec.size();
        for (int i = 0; i < n-1; i++) {
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }
        vec[n-1]->left = NULL;
        vec[n-1]->right = NULL;
        return dac(vec[0]);
    }

    void tranverse(vector<TreeNode*>& vec, TreeNode* root) {
        if (!root) return;
        tranverse(vec, root->left);
        vec.push_back(root);
        tranverse(vec, root->right);
    }

    TreeNode* dac(TreeNode* root) {
        if (!root) return NULL;
        int cnt = 0;
        TreeNode* p = root;
        while (p) {
            p = p->right;
            cnt++;
        }
        // cout<<"cnt:"<<cnt<<endl;
        if (cnt == 1) return root;
        cnt /= 2;
        // cout<<"cnt:"<<cnt<<endl;
        TreeNode* mid = root;
        TreeNode* pre = root;
        while (cnt) {
            pre = mid;
            mid = mid->right;
            cnt--;
        }
        pre->right = NULL;
        mid->left = dac(root);
        mid->right = dac(mid->right);
        return mid;
    }
};
