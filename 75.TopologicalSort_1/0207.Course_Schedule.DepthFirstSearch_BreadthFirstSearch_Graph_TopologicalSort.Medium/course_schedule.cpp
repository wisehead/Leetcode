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
        map<int, vector<int>> mp;
        for (auto vec : prerequisites) {
            if (mp.count(vec[1])) {
                mp[vec[1]].push_back(vec[0]);
            } else {
                vector<int> v(1, vec[0]);
                mp[vec[1]] = v;
            }
        }
        vector<bool> visited(numCourses, false);
        map<int, vector<int>>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            int start = it->first;
            set<int> st;
            if (!dfs(visited, mp, st, start)) return false; 
        }        
        return true;
    }
    
    bool dfs(vector<bool> & visited, map<int, vector<int>>& mp, set<int>& st, int start) {
        if (visited[start]) return true;
        visited[start] = true;
        st.insert(start);
        if (mp.count(start)) {
            for (auto e : mp[start]) {
                if (st.count(e)) return false;
                if (!dfs(visited, mp, st, e)) return false;
                st.erase(e);
            }
        }        
        return true;
    }
};
int main()
{}
