/*******************************************************************************
 *      file name: average_of_levels_in_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/28-19:45:22                              
 *  modified time: 2018/08/28-19:45:22                              
 *******************************************************************************/
#include <iostream>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		if (!root)
			return res;
		q1.push(root);
		while (!q1.empty() || !q2.empty())
		{
			int count = 0;
			int64_t sum = 0;
			double avg = 0;
			if (!q1.empty())
			{
				while (!q1.empty())
				{
					TreeNode* pnode = q1.front();
					q1.pop();
					sum += pnode->val;
					count++;
					if (pnode->left)
						q2.push(pnode->left);
					if (pnode->right)
						q2.push(pnode->right);
				}
				avg = (double)sum/count;
                cout<<"sum:"<<sum<<"    count:"<<count<<"   avg:"<<avg<<endl;
				res.push_back(avg);
				continue;
			}
			if (!q2.empty())
			{
				while (!q2.empty())
				{
					TreeNode* pnode = q2.front();
					q2.pop();
					sum += pnode->val;
					count++;
					if (pnode->left)
						q1.push(pnode->left);
					if (pnode->right)
						q1.push(pnode->right);
				}
				avg = (double)sum/count;
                cout<<"sum:"<<sum<<"    count:"<<count<<"   avg:"<<avg<<endl;
				res.push_back(avg);
				continue;
			}
		}
		return res;
    }
};
int main()
{}
