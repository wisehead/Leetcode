/*******************************************************************************
 *      file name: populating_next_right_pointers_in_each_node.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/05-18:50:10                              
 *  modified time: 2021/10/05-18:50:10                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
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
Node* connect(Node *root) {
    if(!root)
        return root;
    Node* temp = root;
    while(root -> left)
    {
        Node *p = root;
        while(p)
        {
            p -> left -> next = p -> right;
            if(p -> next)
                p -> right -> next = p -> next -> left;
            p = p -> next;
        }
        root = root -> left;
    }
    return temp;
}
};
int main()
{}