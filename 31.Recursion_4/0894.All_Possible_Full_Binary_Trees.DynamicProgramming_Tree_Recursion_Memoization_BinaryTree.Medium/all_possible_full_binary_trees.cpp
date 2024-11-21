/*******************************************************************************
 *      file name: all_possible_full_binary_trees.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/12-21:05:51                              
 *  modified time: 2021/12/12-21:05:51                              
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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if (n == 1) {
            TreeNode* root = new TreeNode();
            res.push_back(root);
            return res;
        }
        for (int i = 1; i < n-1; i =i+2) {
            vector<TreeNode*> vec1 = allPossibleFBT(i);
            vector<TreeNode*> vec2 = allPossibleFBT(n-1-i);
            for (auto left : vec1) {
                for (auto right : vec2) {
                    TreeNode* root = new TreeNode(0, left, right);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    //void fun(vector<TreeNode*> vec, )
};
int main()
{}
