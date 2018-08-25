/*******************************************************************************
 *      file name: n_ary_tree_postorder_traversal.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-23:07:28                              
 *  modified time: 2018/08/25-23:07:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
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
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> postorder(Node* root) {
		vector<int> res;
		if (!root)
			return res;
		//res.push_back(root->val);
		int n = root->children.size();
		for (int i = 0; i< n; i++)
		{
			vector<int> temp = postorder(root->children[i]);
			res.insert(res.end(), temp.begin(), temp.end());
		}
		res.push_back(root->val);
		return res;
    }
};
int main()
{}
