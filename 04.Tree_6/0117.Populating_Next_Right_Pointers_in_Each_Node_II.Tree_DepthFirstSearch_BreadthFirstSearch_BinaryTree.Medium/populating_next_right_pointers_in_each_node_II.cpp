/*******************************************************************************
 *      file name: populating_next_right_pointers_in_each_node_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/03-17:15:20                              
 *  modified time: 2021/12/03-17:15:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        queue<Node*> q2;
        if (!root) return root;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            //cout<<"node->val:"<<node->val<<endl;
            q.pop();
            if (!q.empty()) node->next = q.front();
            if (node->left)
                q2.push(node->left);
            if (node->right)
                q2.push(node->right);
            if (q.empty())
                swap(q, q2);
        }
        return root;
    }
};
int main()
{}
