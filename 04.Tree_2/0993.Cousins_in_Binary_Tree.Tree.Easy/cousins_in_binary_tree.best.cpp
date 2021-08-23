/*******************************************************************************
 *      file name: cousins_in_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/21-10:05:30                              
 *  modified time: 2019/02/21-10:05:30                              *******************************************************************************/
#include <iostream>
#include <queue>
#include <set>
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
	bool isCousins(TreeNode* root, int x, int y, bool siblings = false, bool cousin = false) {
	  queue<TreeNode*> q, q1;
	  q.push(root);
	  while (!q.empty() && !cousin) {
		while (!q.empty()) {
		  auto n = q.front();
		  q.pop();
		  if (n == nullptr) siblings = false;
		  else {
			if (n->val == x || n->val == y) {
			  if (!cousin) cousin = siblings = true;
			  else return !siblings;
			}
			q1.push(n->left), q1.push(n->right), q1.push(nullptr);
		  }
		}
		swap(q, q1);
	  }
	  return false;
	}
};
int main()
{}
