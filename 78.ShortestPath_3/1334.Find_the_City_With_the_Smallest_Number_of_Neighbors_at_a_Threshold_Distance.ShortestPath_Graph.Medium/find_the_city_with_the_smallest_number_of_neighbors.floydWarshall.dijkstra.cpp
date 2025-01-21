/*******************************************************************************
 *      file name: find_the_city_with_the_smallest_number_of_neighbors.floydWarshall.dijkstra.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>
const int INF = INT_MAX;


// 表示图中的边
struct Edge {
    int destination;
    int weight;
};


class Graph {
private:
    int numVertices;
    std::vector<std::vector<Edge>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}

    // 添加边
    void addEdge(int source, int destination, int weight) {
        Edge edge;
        edge.destination = destination;
        edge.weight = weight;
        adjacencyList[source].push_back(edge);
    }

    // Dijkstra 算法
    vector<int> dijkstra(int source) {
        vector<int> distance(numVertices, INF);
        distance[source] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>> > pq;
        pq.push(std::make_pair(0, source));
        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (const Edge& edge : adjacencyList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(std::make_pair(-distance[v], v));
                }
            }
        }
        return distance;
    }
};

class Solution {
public:
    vector<set<int>> res;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        Graph g(n);
        for (auto e : edges) {
            g.addEdge(e[0], e[1], e[2]);
            g.addEdge(e[1], e[0], e[2]);
        }
        res.resize(n, set<int>());

        int min_v = INT_MAX;
        int record = 0;
        for (int i = 0; i < n; i++) {
            vector<int> vec = g.dijkstra(i);
            for (int j = 0; j < n; j++) {
                int dist = vec[j];
                if (dist <= distanceThreshold) res[i].insert(j);
            }
            if (res[i].size() <= min_v) {
                min_v = res[i].size();
                record = i;
            }

        }

        return record;
    }
};
