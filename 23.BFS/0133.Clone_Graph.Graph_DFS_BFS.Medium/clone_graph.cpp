/*******************************************************************************
 *      file name: clone_graph.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-09:40:21                              
 *  modified time: 2020/10/31-09:40:21                              
 *******************************************************************************/
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* out = new Node(node->val, {});
        set<int> visited;
        dfs(visited, node, out);
        return out;
    }

    void dfs(set<int> &visited, Node* node, Node *out) {
        if (!node || !out) return;
        if (visited.count(node->val)) return;
        visited.insert(node->val);
        ht[out->val] = out;
        for (auto e : node->neighbors) {
            Node* temp = nullptr;
            if (!ht.count(e->val)) 
                temp = new Node(e->val, {});
            else 
                temp = ht[e->val];
            
            out->neighbors.push_back(temp);
            dfs(visited, e, temp);
        }
    }
private:    
     unordered_map<int, Node*> ht;
};
int main()
{}
