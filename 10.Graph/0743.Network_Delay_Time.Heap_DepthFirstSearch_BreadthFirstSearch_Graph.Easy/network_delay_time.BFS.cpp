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
using namespace std;
#include <queue>
struct Node {
    int id;
    int time;
    Node(int n, int t) {
        id = n;
        time = t;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int max_time = 0;
        queue<Node> q;
        map<int, vector<vector<int>>> ht;
        vector<int> distance(N+1, INT_MAX);
        distance[0] = 0;
        distance[K] = 0;
        for (auto e : times)
        {
            if (ht.count(e[0]))
                ht[e[0]].push_back(e);
            else
            {
                vector<vector<int>> vec;
                vec.push_back(e);
                ht[e[0]] = vec;
            }
                
        }
        
        Node node(K,0);
        q.push(node);
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            if (!ht.count(node.id)) continue;
            vector<vector<int>> vec = ht[node.id];
            for (auto e : vec) {
                Node tmp(0, 0);
                tmp.id = e[1];
                tmp.time = node.time + e[2];
                if (tmp.time < distance[tmp.id]) {
                    q.push(tmp);
                    distance[tmp.id] = tmp.time;
                }
            }
        }
        for (auto e : distance)
        {
            if (e > max_time)
                max_time = e;
        }
        if (max_time == INT_MAX) return -1;
        return max_time;
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
