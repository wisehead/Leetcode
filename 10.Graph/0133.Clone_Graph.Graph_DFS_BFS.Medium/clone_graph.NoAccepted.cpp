/*******************************************************************************
 *      file name: clone_graph.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-09:40:21                              
 *  modified time: 2020/10/31-09:40:21                              
 *******************************************************************************/
#include <iostream>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* out = new Node(node->val);
        set<int> visited;
        map<int, Node*> ht;
        dfs(visited, ht, node, out);
        visited.clear();
        pp(visited, node);
        cout<<"------ out ------"<<endl;
        visited.clear();
        pp(visited, out);
        //visited.clear();
        //dfs(visited, ht, node, out);
        return out;
    }
    
    void pp(set<int> &visited, Node *node) {
        if (!node) return;
        if (visited.count(node->val)) return;
        visited.insert(node->val);
        cout<<"node:"<<node<<"  node->val:"<<node->val<<endl;
        for (auto e : node->neighbors) {
            cout<<"node->val:"<<node->val<<"    e:"<<e->val<<endl;
            pp(visited, e);
        }
    }
    
    void dfs(set<int> &visited, map<int, Node*> ht, Node* node, Node *out) {
        if (!node || !out) return;
        //cout<<"node->val:"<<node->val<<endl;
        if (visited.count(node->val)) return;
        visited.insert(node->val);
        //out->val = node->val;
        ht[out->val] = out;
        for (auto e : node->neighbors) {
            Node* temp = nullptr;
            if (!ht.count(e->val)) {
                temp = new Node(e->val);
            } else {
                temp = ht[e->val];
            }
            //cout<<"node->val:"<<node->val<<"    e->val:"<<e->val<<endl;
            out->neighbors.push_back(temp);
            dfs(visited, ht, e, temp);
            //cout<<"out->val:"<<out->val<<"    temp->val:"<<temp->val<<endl;
        }
    }
};
int main()
{}
