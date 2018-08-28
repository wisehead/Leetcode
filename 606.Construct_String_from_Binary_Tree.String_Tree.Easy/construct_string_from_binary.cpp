/*******************************************************************************
 *      file name: construct_string_from_binary.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/28-16:29:24                              
 *  modified time: 2018/08/28-16:29:24                              
 *******************************************************************************/
#include <iostream>
#include <sstream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    string tree2str(TreeNode* t) {
		string res;
		if (!t)
			return res;
        stringstream stream;  
        stream<<t->val;  
        res = stream.str();
		if (!t->left && !t->right)
			return res;
		res += "(";
		if (t->left)
			res += tree2str(t->left);
		res += ")";
		if (t->right)
		{
			res += "(";
			res += tree2str(t->right);
			res += ")";
		}
		return res;
    }
};
int main()
{}
