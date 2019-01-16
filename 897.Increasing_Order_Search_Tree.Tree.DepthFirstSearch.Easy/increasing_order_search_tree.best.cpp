/*******************************************************************************
 *      file name: increasing_order_search_tree.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/16-10:57:00                              
 *  modified time: 2019/01/16-10:57:00                              
 *******************************************************************************/
#include <iostream>
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
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};
int main()
{
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / | 
//1        7   9
	TreeNode* nodes[10];
	for (int i=1; i<10; i++)
	{
		nodes[i] = new TreeNode(i);
	}
	nodes[2]->left = nodes[1];
	nodes[3]->left = nodes[2];
	nodes[3]->right = nodes[4];
	nodes[5]->left = nodes[3];
	nodes[5]->right = nodes[6];
	nodes[6]->right = nodes[8];
	nodes[8]->left = nodes[7];
	nodes[8]->right = nodes[9];
	Solution sol;
	TreeNode *res = sol.increasingBST(nodes[5]);
	cout<<"---------------------"<<endl;
	TreeNode *p = res;
	while(p)
	{
		cout<<p<<":"<<p->val<<endl;
		if (p->left)
		{	
			cout<<"start xxxxxxxxxxxxx error xxxxxxxxxxxxxxxx"<<endl;
			cout<<p->left<<":"<<p->left->val<<endl;
			cout<<"end  xxxxxxxxxxxxx error xxxxxxxxxxxxxxxx"<<endl;
		}
		p = p->right;
	}
}
