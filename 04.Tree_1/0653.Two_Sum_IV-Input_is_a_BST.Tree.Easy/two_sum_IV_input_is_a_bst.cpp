/*******************************************************************************
 *      file name: two_sum_IV_input_is_a_bst.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-15:03:43                              
 *  modified time: 2018/09/08-15:03:43                              
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
    vector<int> inorder(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		if (root->left)
		{
			vector<int> temp = inorder(root->left);
			res.insert(res.end(), temp.begin(), temp.end());
		}
		res.push_back(root->val);
		if (root->right)
		{
			vector<int> temp = inorder(root->right);
			res.insert(res.end(), temp.begin(), temp.end());
		}
		return res;
    }
    bool find(TreeNode* root, int k) {
		if (!root) return false;
        if (k == root->val) return true;
		if (k > root->val) return find(root->right, k);
		return find(root->left, k);
	}

    bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		vector<int> vec;
		vec = inorder(root);
		int len = vec.size();
        cout<<"len:"<<len<<"    vec[0]:"<<vec[0]<<"  vec[len-1]:"<<vec[len-1]<<endl;
		if (k < vec[0] + vec[1] || k > vec[len - 1] + vec[len - 2] || len==1) return false;
		for (int i=0; i< len; i++)
		{
            if (vec[i] == k/2)
            {
                if (i+1 < len && vec[i+1] == k/2) return true; 
                continue;
            }
			bool found = find(root, k - vec[i]);
			if (found) return true;
		}
		return false;
    }
};
int main()
{}
