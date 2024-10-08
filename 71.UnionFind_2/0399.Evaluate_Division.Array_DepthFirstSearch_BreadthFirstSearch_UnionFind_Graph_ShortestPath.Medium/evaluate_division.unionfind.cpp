/*******************************************************************************
 *      file name: evaluate_division.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/16-20:20:39                              
 *  modified time: 2022/01/16-20:20:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
    // date: 2016-09-12     location: Santa Clara City Library
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<pair<string, string>> eq;
        for (auto v : equations) {
            eq.push_back(make_pair(v[0], v[1]));
        }
        vector<pair<string, string>> q;
        for (auto v : queries) {
            q.push_back(make_pair(v[0], v[1]));
        }
        return calcEquation(eq, values, q);
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> map;
        vector<double> res;
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (map.count(s1) == 0 && map.count(s2) == 0) {
                map[s1] = new Node();
                map[s2] = new Node();
                map[s1] -> value = values[i];
                map[s2] -> value = 1;
                map[s1] -> parent = map[s2];
            } else if (map.count(s1) == 0) {
                map[s1] = new Node();
                map[s1] -> value = map[s2] -> value * values[i];
                map[s1] -> parent = map[s2];
            } else if (map.count(s2) == 0) {
                map[s2] = new Node();
                map[s2] -> value = map[s1] -> value / values[i];
                map[s2] -> parent = map[s1];
            } else {
                unionNodes(map[s1], map[s2], values[i], map);
            }
        }

        for (auto query : queries) {
            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
                res.push_back(-1);
            else
                res.push_back(map[query.first] -> value / map[query.second] -> value);
        }
        return res;
    }

private:
    struct Node {
        Node* parent;
        double value = 0.0;
        Node()  {parent = this;}
    };

    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * num / node1 -> value;
        for (auto it = map.begin(); it != map.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }

    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
};
int main()
{}
