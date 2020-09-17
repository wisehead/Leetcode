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
	int max_of_3(int a, int b, int c) {
		int temp = max(a, b);
		return max(temp, c);
	}
    int maxDepth(Node* root) {
		if (!root)
			return 0;
		int a = 0, b =0, c = 0;
		a = maxDepth(root->children[0]);
		b = maxDepth(root->children[1]);
		c = maxDepth(root->children[2]);
		return max_of_3(a,b,c) + 1;
    }
};
int main()
{}
