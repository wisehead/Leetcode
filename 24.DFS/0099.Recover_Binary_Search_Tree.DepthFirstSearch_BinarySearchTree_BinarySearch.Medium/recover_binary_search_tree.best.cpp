/*******************************************************************************
 *      file name: recover_binary_search_tree.best.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/07-17:03:51                              
 *  modified time: 2021/08/07-17:03:51                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Just use the "first" and "second" pointer to find the 2 nodes that violate the order. 
Then change the value of the first node ad the second node by their value.
*/
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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        help(root);
        //cout<<"first:"<<first->val<<endl;
        //cout<<"second:"<<second->val<<endl;
        swap(first->val, second->val);
    }

    void help(TreeNode* root){
        if(root==NULL)  return;
        help(root->left);
        if(first==NULL && prev->val > root->val)   first=prev;
        if(first!=NULL && prev->val > root->val)   second=root;
        prev=root;
        help(root->right);
    }
};
int main()
{}
