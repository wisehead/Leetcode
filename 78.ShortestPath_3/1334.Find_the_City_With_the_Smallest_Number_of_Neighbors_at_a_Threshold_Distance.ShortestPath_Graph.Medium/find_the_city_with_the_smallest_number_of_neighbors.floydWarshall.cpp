/*******************************************************************************
 *      file name: find_the_city_with_the_smallest_number_of_neighbors.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>
const int INF = 99999;

class Graph {
public:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;


public:
    Graph(int vertices) : numVertices(vertices), adjacencyMatrix(vertices, vector<int>(vertices, INF) ) {
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[i][i] = 0;
        }
    }


    // 添加边
    void addEdge(int source, int destination, int weight) {
        adjacencyMatrix[source][destination] = weight;
    }


    // Floyd-Warshall 算法
    void floydWarshall() {
        for (int k = 0; k < numVertices; ++k) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (adjacencyMatrix[i][k]!= INF && adjacencyMatrix[k][j]!= INF) {
                        if (adjacencyMatrix[i][j] > adjacencyMatrix[i][k] + adjacencyMatrix[k][j]) {
                            adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                        }
                    }
                }
            }
        }


        // 输出结果
        // for (int i = 0; i < numVertices; ++i) {
        //     for (int j = 0; j < numVertices; ++j) {
        //         if (adjacencyMatrix[i][j] == INF) {
        //             std::cout << "INF ";
        //         } else {
        //             std::cout << adjacencyMatrix[i][j] << " ";
        //         }
        //     }
        //     std::cout << std::endl;
        // }
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
        g.floydWarshall();
        res.resize(n, set<int>());

        int min_v = INT_MAX;
        int record = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int dist = g.adjacencyMatrix[i][j];
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
