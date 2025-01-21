/*******************************************************************************
 *      file name: find_the_city_with_the_smallest_number_of_neighbors.floydWarshall.dfs.TimeLimiteExceed.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    map<vector<int>, int> ht;
    vector<set<int>> sp;
    int N;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        N = n;
        for (auto e : edges) {
            ht[{e[0],e[1]}] = e[2];
            ht[{e[1],e[0]}] = e[2];
        }
        sp.resize(n,set<int>());
        int min_v = INT_MAX;
        int record = 0;
        vector<int> res(n,0);
        for (int i = 0; i < n; i++) {
            set<int> v;
            dfs(v,i, i, distanceThreshold);
            // cout<<"i:"<<i<<",sp[i]:"<<sp[i].size()<<endl;
            if (sp[i].size() <= min_v) {
                min_v = sp[i].size();
                record = i;
            }

        }

        return record;
    }
    void dfs(set<int>& s, int start, int node, int cost) {
        // cout<<"node:"<<node<<",cost:"<<cost<<endl;
        set<int> res;
        if (cost < 0) return;

        for (int i = 0; i < N; i++) {
            if (i == node) continue;
            if (i == start) continue;
            if (s.count(i)) continue;
            if (ht.count({node,i})) {
                int c = ht[{node,i}];
                if (c > cost) continue;
                s.insert(i);
                sp[start].insert(i);
                dfs(s, start, i, cost-c);
                s.erase(i);
            }
        }
    }
};
