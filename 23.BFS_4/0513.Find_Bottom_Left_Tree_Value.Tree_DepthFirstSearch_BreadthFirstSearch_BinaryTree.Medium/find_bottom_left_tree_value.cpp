/*******************************************************************************
 *      file name: find_bottom_left_tree_value.cpp                                               
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
struct Node {
    int level;
    TreeNode* tnode;
};
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int max_level = 0;
        int val = 0;
        queue<Node> q;
        q.push(Node(1,root));
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            if (node.level > max_level) {
                max_level = node.level;
                val = node.tnode->val;
            }
            if (node.tnode->left) q.push(Node(node.level+1, node.tnode->left));
            if (node.tnode->right) q.push(Node(node.level+1, node.tnode->right));
        }
        return val;
    }
};
