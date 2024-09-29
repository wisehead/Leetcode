/*******************************************************************************
 *      file name: find_if_path_exists_in_graph.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/03-20:10:23                              
 *  modified time: 2021/10/03-20:10:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0; i < n; i++) {
            id.push_back(i);
        }

        for (auto edge : edges) {
            Union(edge[0], edge[1]);
        }
        int id_a = Find(source);
        int id_b = Find(destination);
        return id_a == id_b;
    }
    int Find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA == rootB) return;
        id[rootA] = rootB;
    }
public:
    vector<int> id;

};
