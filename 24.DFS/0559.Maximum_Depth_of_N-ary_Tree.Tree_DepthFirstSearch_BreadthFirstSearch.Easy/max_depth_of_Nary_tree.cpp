/*******************************************************************************
 *      file name: max_depth_of_Nary_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-18:03:01                              
 *  modified time: 2018/08/25-18:03:01                              
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
    int maxDepth(Node* root) {
		if (!root)
			return 0;
		int n = root->children.size();
		int max_depth = 0;
		for (int i = 0; i < n; i++)
		{
			int temp  = maxDepth(root->children[i]);
			max_depth = max(max_depth, temp); 
		}
		return max_depth + 1;
    }
};
int main()
{}
