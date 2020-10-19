/*******************************************************************************
 *      file name: validate_binary_search_tree.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/19-10:36:09                              
 *  modified time: 2020/10/19-10:36:09                              
 *******************************************************************************/
#include <iostream>
#include <climits>
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
    bool fun(TreeNode* root, int& min_v, int& max_v ) {
        if (!root) return true;
        int min_l = INT_MIN, max_l = INT_MAX;
        int min_r = INT_MIN, max_r = INT_MAX;
        bool ret_l = true;
        bool ret_r = true;
        
        if (root->left) {
            if (root->left->val >= root->val) return false;
            min_l = INT_MIN; max_l = INT_MAX;
            ret_l = fun(root->left, min_l, max_l);
            //cout<<"ret_l:"<<ret_l<<"    min_l:"<<min_l<<"   max_l:"<<max_l<<endl;
            min_v = min_l;
        } else {
            min_v = root->val;
            max_l = root->val;
        }
        
        if (root->right) {
            if (root->right->val <= root->val) return false;
            min_r = INT_MIN; max_r = INT_MAX;
            ret_r = fun(root->right, min_r, max_r);        
            //cout<<"ret_r:"<<ret_r<<"    min_r:"<<min_r<<"   max_r:"<<max_r<<endl;
            max_v = max_r;            
        } else {
            max_v = root->val;
            min_r = root->val;
        } 
            
        if (!root->left && !root->right) {
            return true;
        }
        if (!root->left && root->right) 
            return  ret_r && (min_r > root->val);
        if (!root->right && root->left) 
            return ret_l  && (max_l < root->val);        
        return ret_l && ret_r && (max_l < root->val) && (min_r > root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        int min_v = 0, max_v = 0;
        return fun(root, min_v, max_v);
    }
};
int main()
{}
