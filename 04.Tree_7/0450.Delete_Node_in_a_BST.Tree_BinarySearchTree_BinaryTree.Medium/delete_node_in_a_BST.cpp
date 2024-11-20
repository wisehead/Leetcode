/*******************************************************************************
 *      file name: delete_node_in_a_BST.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/18-11:11                                    
 * modified time: 24/11/18-11:11                                    
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
// 这是核心函数，用于删除二叉搜索树中值为 val 的节点。根据节点的子节点情况分为以下三种情况：
// 情况一：节点是叶子节点（没有子节点）：直接删除该节点，并将父节点指向该节点的指针设为 nullptr。
// 情况二：节点有一个子节点：将父节点指向该节点的指针改为指向该节点的唯一子节点，然后删除该节点。
// 情况三：节点有两个子节点：先在该节点的右子树中找到最小节点 minNode，将当前节点的值替换为 minNode 的值，然后再删除 minNode。
class Solution {
public:
    TreeNode* deleteNode(TreeNode* cur, int key) {
        if (!cur) return NULL;
        //根节点
        if (key == cur->val) {
            if (!cur->left && !cur->right) return NULL;
            if (cur->left && cur->right) {
                //先在该节点的右子树中找到最小节点 minNode，将当前节点的值替换为 minNode 的值，
                //然后再删除 minNode。
                TreeNode* right_min_parent = findMin(cur->right);
                TreeNode* node = NULL;
                if (right_min_parent->left) {
                    node = right_min_parent->left;
                    right_min_parent->left = node->right;
                } else {
                    node = right_min_parent;
                }

                cur->val = node->val;
                if (node == cur->right) {
                    cur->right = node->right;
                }
                return cur;
            } else {
                if (cur->left) return cur->left;
                else return cur->right;
            }
        } else if (key < cur->val) {
            TreeNode* node = deleteNode(cur->left,key);
            cur->left = node;
        } else  {//key > root->val
            TreeNode* node = deleteNode(cur->right,key);
            cur->right = node;
        }
        return cur;
    }

    TreeNode* findMin(TreeNode* root) {
        TreeNode *p = root, *parent = root;
        while (p->left) {
            parent = p;
            p = p->left;
        }
        return parent;
    }
};
