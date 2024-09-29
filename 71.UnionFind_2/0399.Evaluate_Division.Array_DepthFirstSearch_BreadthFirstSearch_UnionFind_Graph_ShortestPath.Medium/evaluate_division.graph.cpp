/*******************************************************************************
 *      file name: evaluate_division.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/16-20:20:39                              
 *  modified time: 2022/01/16-20:20:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
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
        vector<double> ans;

        for (int i = 0; i < equations.size(); i++) {
            children[equations[i].first].push_back(make_pair(equations[i].second, values[i]));      // build graph list a->b
            children[equations[i].second].push_back(make_pair(equations[i].first, 1.0 / values[i]));// build graph list b->a
        }

        for (auto p : queries) {
            unordered_set<string> visited;                                                          // to record visited nodes
            // p.first == p.second is special case
            ans.push_back(p.first == p.second && children.count(p.first) ? 1.0 : search(p.first, p.second, visited, 1.0).second);
        }

        return ans;
    }
private:
    unordered_map<string, vector<pair<string, double>>> children;                               // adjacency list

    pair<bool, double> search(string& a, string& b, unordered_set<string>& visited, double val) {
        if (visited.count(a) == 0) {
            visited.insert(a);                                                                  // mark a as visited
            for (auto p : children[a]) {
                double temp = val * p.second;                                                   // potential result
                if (p.first == b) { return make_pair(true, temp); }                             // found result

                auto result = search(p.first, b, visited, temp);
                if (result.first) { return result; }
            }
        }
        return make_pair(false, -1.0);
    }

};
int main()
{}
