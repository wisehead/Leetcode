/*******************************************************************************
 *      file name: add_one_row_to_tree.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/20-11:11                                    
 * modified time: 24/11/20-11:11                                    
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
struct Node {
    int level;
    TreeNode* tnode;
};
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<Node> q;
        if (!root) return NULL;
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        Node node = Node(1,root); q.push(node);
        while (!q.empty()) {
            Node node = q.front(); q.pop();
            if (node.level < depth-1) {
                if (node.tnode->left) q.push(Node(node.level+1,node.tnode->left));
                if (node.tnode->right) q.push(Node(node.level+1,node.tnode->right));
            } else if (node.level = depth-1) {
                TreeNode* left = new TreeNode(val);
                left->left = node.tnode->left;
                node.tnode->left = left;
                TreeNode* right = new TreeNode(val);
                right->right = node.tnode->right;
                node.tnode->right = right;                
            } //else break;
        }
        return root;
    }
};
