/*******************************************************************************
 *      file name: find_mode_in_BST.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/20-14:05:12                              
 *  modified time: 2018/08/20-14:05:12                              
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
    vector<int> tranverse(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		vector<int> res_left;
		vector<int> res_right;
		if (root->left)
		{
			res_left = tranverse(root->left);
			res.insert(res.end(), res_left.begin(), res_left.end());
		}
		res.push_back(root->val);
		if (root->right)
		{
			res_right = tranverse(root->right);
			res.insert(res.end(), res_right.begin(), res_right.end());
		}
		return res;
	}
    vector<int> findMode(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		vector<int> order;
		order = tranverse(root);
        cout<<"order.size is:"<<order.size()<<endl;
        if (order.size() == 1)
        {
            res.push_back(order[0]);
            return res;
        }
		vector<int>::iterator it;
		int count = 1, max = 1, pre = order[0];
        //cout<<"1st round pre:"<<pre<<endl;
		for (it = order.begin() + 1; it != order.end(); it++)
		{
            //cout<<"1st round:"<<*it<<endl;
			if(*it == pre) 
			{
				count++;
				if (count > max)
					max = count;
			}
            else
                count = 1;
			pre = *it;
		}
        cout<<"max is:"<<max<<endl;
        pre = order[0];
        //cout<<"2nd round pre:"<<pre<<endl;
        count = 1;
        for (it = order.begin(); it != order.end(); it++)
		{
            //cout<<"2nd round:"<<*it<<endl;
			if(it != order.begin() && *it == pre) 
			{
				count++;
			}
            else
                count = 1;
			if (count == max)
				res.push_back(*it);
			pre = *it;
		}
        /*
		for (it = order.begin() + 1; it != order.end(); it++)
		{
            //cout<<"2nd round:"<<*it<<endl;
			if(*it == pre) 
			{
				count++;
			}
            else
                count = 1;
			if (count == max)
				res.push_back(*it);
			pre = *it;
		}
        */
		return res;
    }
};
int main()
{}
