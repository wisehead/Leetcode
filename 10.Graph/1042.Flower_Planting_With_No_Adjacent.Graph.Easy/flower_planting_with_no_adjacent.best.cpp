/*******************************************************************************
 *      file name: flower_planting_with_no_adjacent.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/23-10:19:30                              
 *  modified time: 2020/09/23-10:19:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> G(N);
        for (vector<int>& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < N; ++i) {
            int colors[5] = {};
            for (int j : G[i])
                colors[res[j]] = 1;
            for (int c = 4; c > 0; --c)
                if (!colors[c])
                    res[i] = c;
        }
        return res;
    }
};
int main()
{}
