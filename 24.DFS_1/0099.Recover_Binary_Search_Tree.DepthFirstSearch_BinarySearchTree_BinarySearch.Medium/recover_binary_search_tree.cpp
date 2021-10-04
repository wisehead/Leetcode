/*******************************************************************************
 *      file name: recover_binary_search_tree.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/07-16:43:38                              
 *  modified time: 2021/08/07-16:43:38                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
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
    TreeNode* findBig(TreeNode* root, int value) {
        if (!root) return NULL;
        if (root->val > value) return root;
        TreeNode* left = findBig(root->left, value);
        TreeNode* right = findBig(root->right,value);
        if (left) return left;
        if (right) return right;
        return NULL;
    }
    
    TreeNode* findSmall(TreeNode* root, int value) {
        if (!root) return NULL;
        if (root->val < value) return root;
        TreeNode* left = findSmall(root->left, value);
        TreeNode* right = findSmall(root->right, value);
        if (left) return left;
        if (right) return right;
        return NULL;
    }
    
    set<TreeNode*> ss;
    
    void recoverTree2(TreeNode* root) {
        if (!root) return;
        TreeNode* left = findBig(root->left, root->val);
        TreeNode* right = findSmall(root->right, root->val);
        if (left || right) ss.insert(root);
        if (left) ss.insert(left);
        if (right) ss.insert(right);
        recoverTree2(root->left);
        recoverTree2(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        recoverTree2(root);
        set<TreeNode*>::iterator it = ss.begin();
        TreeNode* max_node = *it;
        TreeNode* min_node = *it;
        for (; it != ss.end(); it++) {
            if ((*it)->val > max_node->val) max_node = *it;
            if ((*it)->val < min_node->val) min_node = *it;
        }
        int temp = max_node->val;
        max_node->val = min_node->val;
        min_node->val = temp;
        
    }
};
int main()
{}
