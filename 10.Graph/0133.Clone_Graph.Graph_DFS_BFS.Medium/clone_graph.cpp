/*******************************************************************************
 *      file name: clone_graph.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-09:40:21                              
 *  modified time: 2020/10/31-09:40:21                              
 *******************************************************************************/
#include <iostream>
#include <map>
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
        ht[node->val] = out;
        dfs(visited, node, out);
        /*
        visited.clear();
        pp(visited, node);
        cout<<"------ out ------"<<endl;
        visited.clear();
        pp(visited, out);
        */
        return out;
    }

    
    void pp(set<int> &visited, Node *node) {
        if (!node) return;
        if (visited.count(node->val)) return;
        visited.insert(node->val);
        cout<<"node:"<<node<<"  node->val:"<<node->val<<endl;
        for (auto e : node->neighbors) {
            cout<<"e:"<<e<<"    node->val:"<<node->val<<"    e:"<<e->val<<endl;
            pp(visited, e);
        }
    }
    
    void dfs(set<int> &visited, Node* node, Node *out) {
        if (!node || !out) return;
        //cout<<"node->val:"<<node->val<<endl;
        if (visited.count(node->val)) return;
        visited.insert(node->val);
        //out->val = node->val;
        //ht[out->val] = out;
        for (auto e : node->neighbors) {
            Node* temp = nullptr;
            if (!ht.count(e->val)) {
                temp = new Node(e->val, {});
                ht[temp->val] = temp;
            } else {
                temp = ht[e->val];
            }
            //cout<<"node:"<<node<<"  node->val:"<<node->val<<"   e:"<<e<<"    e->val:"<<e->val<<endl;
            out->neighbors.push_back(temp);
            dfs(visited, e, temp);
            //cout<<"out:"<<out<<"    out->val:"<<out->val<<"   temp:"<<temp<<"    temp->val:"<<temp->val<<endl;
        }
    }
private:    
     map<int, Node*> ht;
};
int main()
{}
