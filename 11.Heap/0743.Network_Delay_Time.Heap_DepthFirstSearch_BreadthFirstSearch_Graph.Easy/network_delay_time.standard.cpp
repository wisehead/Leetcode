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
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
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
