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
// Approach 2: DFS BASED SOLUTION
// ===============================
class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int current, int end) {
        if(current == end)
            return true;
        if(visited[current])
            return false;

        visited[current] = 1;

        for(int i=0; i<graph[current].size(); i++){
            if(dfs(graph, visited, graph[current][i], end))
                return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, start, end);
    }
};
int main()
{}
