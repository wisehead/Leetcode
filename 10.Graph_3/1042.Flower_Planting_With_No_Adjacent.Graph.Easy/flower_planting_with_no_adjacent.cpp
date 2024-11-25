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
        map<int, vector<int>> mm;
        vector<int> res(N+1, 0);
        for (auto e: paths)
        {
            mm[e[0]].push_back(e[1]);
            mm[e[1]].push_back(e[0]);
            //cout<<"e[0]:"<<e[0]<<"  e[1]:"<<e[1]<<endl;
        }
        res[1] = 1;
        for (int i = 1; i <= N; i++)
        {
            //cout<<"i:"<<i<<endl;
            if (res[i]) continue;
            if (mm.count(i)) {
                bool flags[4] = {false};
                for (auto k: mm[i])
                {
                    if (res[k])
                        flags[res[k] - 1] = true;
                }
                for (int j = 0; j < 4; j++)
                {
                    //cout<<"flags["<<j<<"]:"<<flags[j]<<endl;
                    if (!flags[j]) {
                        res[i] = j+1;
                        break;
                    }
                        
                }
            } else {
                res[i] = 1;
            }
            //cout<<"res["<<i<<"]:"<<res[i]<<endl;
        }
        res.erase(res.begin());
        return res;
    }
};
int main()
{}
