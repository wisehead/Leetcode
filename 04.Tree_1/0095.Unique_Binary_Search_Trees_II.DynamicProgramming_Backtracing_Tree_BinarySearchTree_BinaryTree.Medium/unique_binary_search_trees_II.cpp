/*******************************************************************************
 *      file name: unique_binary_search_trees_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/28-11:19:29                              
 *  modified time: 2021/09/28-11:19:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
    
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> res;
        
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = dfs(start, i-1);
            vector<TreeNode*> right = dfs(i+1, end);
            for (auto v1 : left) {
                for (auto v2 : right) {
                    TreeNode *temp = new TreeNode(i);
                    temp->left = v1;
                    temp->right = v2;
                    res.push_back(temp);
                }
            }
        }
        return res;
        
    }

};
int main()
{}
