/*******************************************************************************
 *      file name: course_schedule.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/09-20:00:34                              
 *  modified time: 2021/10/09-20:00:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        set<int> sk;
        map<int, vector<int>> out_map;
        map<int, int> in_map;
        for (auto edge : prerequisites) {
            in_map[edge[1]]++;
            out_map[edge[0]].push_back(edge[1]);
        }
        // for(auto it = in_map.begin(); it != in_map.end(); it++) {
        //     cout<<"key:"<<it->first<<",value:"<<it->second<<endl;
        //     if (it->second == 0) q.push(it->first);
        // }
        for (int i = 0; i < numCourses;i ++) {
            if (!in_map.count(i)) {
                q.push(i);
                sk.insert(i);
            }
        }
        if (q.empty()) return false;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            //sk.insert(x);
            for (auto xout : out_map[x]) {
                in_map[xout]--;
                if(in_map[xout] == 0) {
                    if (sk.count(xout)) return false;
                    q.push(xout);
                    sk.insert(xout);
                }
            }
        }
        //cout<<"size:"<<in_map.size()<<endl;
        int cnt = 0;
        for(auto it = in_map.begin(); it != in_map.end(); it++) {
            //cout<<"key:"<<it->first<<",value:"<<it->second<<endl;
            if (it->second != 0) cnt++;
        }
        return cnt == 0;
    }
};
