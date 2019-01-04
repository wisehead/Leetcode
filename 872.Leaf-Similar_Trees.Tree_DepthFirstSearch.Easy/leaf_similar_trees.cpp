/*******************************************************************************
 *      file name: leaf_similar_trees.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/04-10:50:44                              
 *  modified time: 2019/01/04-10:50:44                              
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
	void getLeafs(TreeNode* r, vector<int> &vec) {
		if (!r) return;
		if (!r->left && !r->right)
		{
			vec.push_back(r->val);
			return;
		}
		if (r->left)
			getLeafs(r->left, vec);
		if (r->right)
			getLeafs(r->right, vec);
        /*
        for (int i=0; i<vec.size();i++)
        {
            cout<<"vec["<<i<<"]"<<vec[i]<<endl;
        }
        */
	}
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        cout<<"hahaha"<<endl;
		if (!root1 || !root2)
		{
			if (root1 != root2) return false;
			return true;
		}
		vector<int> vec_left;
		getLeafs(root1, vec_left);
        for (int i=0; i<vec_left.size();i++)
        {
            cout<<" ["<<i<<"]:"<<vec_left[i];
        }
        cout<<endl;
		vector<int> vec_right;
		getLeafs(root2, vec_right);

        for (int i=0; i<vec_right.size();i++)
        {
            cout<<" ["<<i<<"]:"<<vec_right[i];
        }
        cout<<endl;
		return (vec_left == vec_right);
    }
};;
int main()
{}
