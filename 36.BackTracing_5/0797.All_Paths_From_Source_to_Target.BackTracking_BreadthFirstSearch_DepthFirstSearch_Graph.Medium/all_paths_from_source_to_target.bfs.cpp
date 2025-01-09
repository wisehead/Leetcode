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
        int n = graph.size();
        queue<vector<int>> q;
        vector<vector<int>> res;
        auto vec = graph[0];
        for (auto node : vec) {
            vector<int> path(1,0);
            path.push_back(node);
            q.push(path);
        }

        while (!q.empty()) {
            auto path = q.front(); q.pop();
            for (auto x : path)
                cout<<"path:"<<x<<endl;
            int len = path.size();
            auto next = graph[path[len-1]];
            for (auto x : next)
                cout<<"next:"<<x<<endl;
            if (next.empty()) {
                if (path[len-1] == n-1)
                    res.push_back(path);
            }
            else {
                if (path[len-1] == n-1)
                    res.push_back(path);
                else {
                    for (auto node : next) {
                        vector<int> path2(path);
                        path2.push_back(node);
                        q.push(path2);
                    }
                }
            }
        }
        return res;
    }
};
