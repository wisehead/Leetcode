/*******************************************************************************
 *      file name: network_delay_time.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/05-11:43:04                              
 *  modified time: 2018/11/05-11:43:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include<algorithm>
using namespace std;
#include <queue>
typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> g[n + 1];
        for (const auto& t : times) {
            g[t[0]].emplace_back(t[1], t[2]);
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.emplace(0, k);
        int u, v, w;
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};

int main()
{
	Solution sol;
	int arr[3] = {1,2,1};
	vector<int> vec(arr, arr+3);
	vector<vector<int> > input; 
	input.push_back(vec);
	int N = 2;
	int K = 1;
	int ret = 0;
	ret = sol.networkDelayTime(input, N, K);
	cout<<"ret:"<<ret<<endl;
}
