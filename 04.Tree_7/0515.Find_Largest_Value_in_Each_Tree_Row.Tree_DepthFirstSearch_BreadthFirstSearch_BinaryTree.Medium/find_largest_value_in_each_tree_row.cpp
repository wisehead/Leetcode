/*******************************************************************************
 *      file name: find_largest_value_in_each_tree_row.cpp                                               
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
    TreeNode* tn;
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> vec;
        if(!root) return vec;
        queue<Node> q;
        q.push(Node(0,root));
        while (!q.empty()) {
            Node node = q.front(); q.pop();
            if (vec.size() < node.level+1) {
                vec.push_back(node.tn->val);
            } else {
                if (node.tn->val > vec[node.level])
                    vec[node.level] = node.tn->val;
            }
            if (node.tn->left) q.push(Node(node.level+1, node.tn->left));
            if (node.tn->right) q.push(Node(node.level+1, node.tn->right));
        }
        return vec;

    }

public:
    //unordered_map<int,int> ht;
};
