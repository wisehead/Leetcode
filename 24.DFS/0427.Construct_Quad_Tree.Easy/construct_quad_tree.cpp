/*******************************************************************************
 *      file name: construct_quad_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/16-16:46:33                              
 *  modified time: 2018/10/16-16:46:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
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
    Node* dfs(vector<vector<int> >& grid, int x_start, int y_start, int len) {
        if (len == 1)
        {
            Node *node = new Node(grid[x_start][y_start], true, NULL, NULL, NULL, NULL);
            return node;
        }
        int newlen = len/2;
        Node* topLeft = dfs(grid, x_start, y_start, newlen);
        Node* topRight = dfs(grid, x_start, y_start + newlen, newlen);;
        Node* bottomLeft = dfs(grid, x_start + newlen, y_start, newlen);
        Node* bottomRight = dfs(grid, x_start + newlen, y_start + newlen, newlen);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf
                && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            bool val = topLeft->val;
            delete topLeft; topLeft = NULL;
            delete topRight; topRight = NULL;
            delete bottomLeft; bottomLeft = NULL;
            delete bottomRight; bottomRight = NULL;
            Node* node = new Node(val, true, NULL, NULL, NULL, NULL);
            return node;
        }
        Node *node = new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        return node;
    }
    Node* construct(vector<vector<int> >& grid) {
        int len = grid.size();
        if (len == 0 ) return NULL;
        Node* node = dfs(grid, 0, 0, len);
        return node;
    }
};


int main()
{}
