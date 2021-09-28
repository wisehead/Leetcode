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
    Node* dfs(vector<vector<int> >& grid, int x_start, int x_end, int y_start, int y_end) {
        if (y_end - y_start == 0 && x_end - x_start == 0)
        {
            Node *node = new Node(grid[x_start][y_start], true, NULL, NULL, NULL, NULL);
            return node;
        }
        int x_mid = (x_start + x_end)/2;
        int y_mid = (y_start + y_end)/2;
        Node* topLeft = dfs(grid, x_start, x_mid, y_start, y_mid);
        Node* topRight = dfs(grid, x_mid, x_end, y_start, y_mid);;
        Node* bottomLeft = dfs(grid, x_start, x_mid, y_mid, y_end);
        Node* bottomRight = dfs(grid, x_mid, x_end, y_mid, y_end);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf
                && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            delete topLeft; topLeft = NULL;
            delete topRight; topRight = NULL;
            delete bottomLeft; bottomLeft = NULL;
            delete bottomRight; bottomRight = NULL;
            Node* node = new Node(topLeft->val, true, NULL, NULL, NULL, NULL);
            return node;
        }
        Node *node = new Node(-1, false, topLeft, topRight, bottomLeft, bottomRight);
        return node;
    }
    Node* construct(vector<vector<int> >& grid) {
        int m_len = grid.size();
        int n_len = grid[0].size();
        if (m_len == 0 || n_len == 0) return NULL;
        Node* node = dfs(grid, 0, n_len, 0, m_len);
        return node;
    }
};


int main()
{}
