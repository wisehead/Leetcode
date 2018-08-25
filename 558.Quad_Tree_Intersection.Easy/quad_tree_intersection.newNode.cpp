/*******************************************************************************
 *      file name: quad_tree_intersection.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-11:09:07                              
 *  modified time: 2018/08/25-11:09:07                              
 *******************************************************************************/
#include <iostream>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
		if (!quadTree1 && !quadTree2)
			return NULL;
		Node *node = NULL;
		node = new Node(false, false, NULL, NULL, NULL, NULL);
		if (!quadTree1)
		{
			node->val = quadTree2->val;
			node->isLeaf = quadTree2->isLeaf;
			node->topLeft = quadTree2->topLeft;
			node->topRight = quadTree2->topRight;
			node->bottomLeft = quadTree2->bottomLeft;
			node->bottomRight = quadTree2->bottomRight;
			return node;
		}
		if (!quadTree2)
		{
			node->val = quadTree1->val;
			node->isLeaf = quadTree1->isLeaf;
			node->topLeft = quadTree1->topLeft;
			node->topRight = quadTree1->topRight;
			node->bottomLeft = quadTree1->bottomLeft;
			node->bottomRight = quadTree1->bottomRight;
			return node;
		}

		if ((quadTree1->isLeaf && quadTree1->val) || (quadTree2->isLeaf && quadTree2->val))
		{
			node->isLeaf = true;
			node->val = true;
			return node;
		}
		if (quadTree1->isLeaf && !quadTree1->val && quadTree2->isLeaf && !quadTree2->val) {
			node->isLeaf = true;
			node->val = false;
			return node;
		}
		node->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
		node->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
		node->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
		node->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
		if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf)
		{
			if (node->topLeft->val == node->topRight->val 
					&& node->topRight->val == node->bottomLeft->val
					&& node->bottomLeft->val == node->bottomRight->val)
			{
				node->topLeft->isLeaf = true;
				node->val =  node->topLeft->val;
			}
		}
		return node;
    }
};
int main()
{}
