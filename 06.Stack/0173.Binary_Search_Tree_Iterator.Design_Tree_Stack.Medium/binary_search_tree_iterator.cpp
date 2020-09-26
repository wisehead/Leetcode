/*******************************************************************************
 *      file name: binary_search_tree_iterator.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/26-18:21:46                              
 *  modified time: 2020/09/26-18:21:46                              
 *******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (!root) return;
        TreeNode* p = root;
        s.push(p);
        while (p->left)
        {
            p = p->left;
            s.push(p);
        }
    }
    
    /** @return the next smallest number */
    int next() {
        //if (current) return current->val;
        int ret = -1;
        if (!s.empty())
        {
            TreeNode* p = s.top();
            s.pop();
            ret = p->val;
            if (p->right)
            {
                s.push(p->right);
                p = p->right;
                while (p->left)
                {
                    p = p->left;
                    s.push(p);
                }
            }
        }
        return ret;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    } 
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
}
