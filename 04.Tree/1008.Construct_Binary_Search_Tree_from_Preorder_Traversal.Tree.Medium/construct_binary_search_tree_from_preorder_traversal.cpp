/*******************************************************************************
 *      file name: construct_binary_search_tree_from_preorder_traversal.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/03-10:06:04                              
 *  modified time: 2020/10/03-10:06:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root = nullptr;
        TreeNode* parent = nullptr;
        for (int i = 0; i < preorder.size(); i++) {
            int x = preorder[i];
            //cout<<"i:"<<i<<"    x:"<<x<<endl;
            if (!root) {
                root = new TreeNode(x);
                st.push(root);
                parent = root;
                continue;
            }
            if (x < parent->val) {
                TreeNode* node = new TreeNode(x);
                parent->left = node;
                st.push(node);
                parent = node;
            } else {
                TreeNode* node = new TreeNode(x);
                while (!st.empty() && st.top()->val < x) {
                    parent = st.top();
                    st.pop();
                }
                
                //cout<<"parent:"<<parent<<endl;
                parent->right = node;
                st.push(node);
                parent = node;                
            }
            
        }//for
        return root;
    }
};
int main()
{}
