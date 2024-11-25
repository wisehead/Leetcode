/*******************************************************************************
 *      file name: n-ary_tree_level_order_traversal.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/16-18:55:35                              
 *  modified time: 2018/10/16-18:55:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
		vector<vector<int> > res;
		if (!root) return res; 
		queue<Node*> q1;
		q1.push(root);
		while (!q1.empty())
		{
			int size = q1.size();
			vector<int> vec;
			for (int i = 0; i < size; i++)
			{
				Node* node = q1.front();
				q1.pop();
				vec.push_back(node->val);
				for (int j = 0; j < node->children.size(); j++)
				{
					q1.push(node->children[j]);
				}
			}
			res.push_back(vec);
		}
		return res;
    }
};
int main()
{}
