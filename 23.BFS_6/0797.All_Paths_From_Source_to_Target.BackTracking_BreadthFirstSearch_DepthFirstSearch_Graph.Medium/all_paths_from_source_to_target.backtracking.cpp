/*******************************************************************************
 *      file name: all_paths_from_source_to_target.backtracking.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/25-11:11                                    
 * modified time: 24/11/25-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path(1,0);
        bt(graph,path);
        return res;
    }
    void bt(vector<vector<int>>& graph, vector<int>& path) {
        //vector<vector<int>> res;
        int n = graph.size();
        int len = path.size();
        int node = path[len-1];
        if (node == n-1) {
            res.push_back(path);
            return;
        }
        vector<int> next_vec = graph[node];
        for (auto next : next_vec) {
            auto path2(path);
            path2.push_back(next);
            bt(graph, path2);
        }
        return;
    }
public:
    vector<vector<int>> res;
};
