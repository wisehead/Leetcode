/*******************************************************************************
 *      file name: course_schedule_II.timeout.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/13-11:14:11                              
 *  modified time: 2021/10/13-11:14:11                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<int> res;
        queue<int> q;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        vector<int> in(N,0) ;
        for (auto v : prerequisites) {
            int i = v[1];
            int j = v[0];
            arr[i][j] = 1;
            in[j]++;
        }
        for(int i=0;i<N;i++)  //n  节点的总数
            if(in[i]==0) q.push(i);  //将入度为0的点入队列

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int j = 0; j < N; j++) {
                if (arr[x][j]) {
                    arr[x][j] = 0;
                    in[j]--;
                    if (!in[j]) q.push(j);
                }
            }
        }

        if (res.size() == N) return res;
        vector<int> tmp;
        return tmp;
    }
};
int main()
{}
