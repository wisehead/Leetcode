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
using namespace std;
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<int> res;
        set<int> nodes;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (auto v : prerequisites) {
            int i = v[1];
            int j = v[0];
            arr[i][j] = 1;
            nodes.insert(i);
            nodes.insert(j);
        }
        
        
        for (int i = 0; i < N; i++) {
            if (!nodes.count(i))
                res.push_back(i);
        }
            
        
        while (!nodes.empty()) {
            set<int>::iterator it;
            //find the input degree = 0
            for (it = nodes.begin(); it != nodes.end(); it++) {
                int j = *it;
                int i = 0;
                for (i = 0; i < N; i++) {
                    if (arr[i][j]) break;
                }         
                // i == N means, we got the indegree = 0 node.
                if (i == N) break;
            }
            //can't find any nodes with indgree=0
            if (it == nodes.end()) {
                vector<int> tmp;
                return tmp;
            }
                
            int i = *it;
            res.push_back(i);
            nodes.erase(i);
            for (int j = 0; j < N; j++) {
                arr[i][j] = 0;
            } 
        }
        return res;
    }


    
};
int main()
{}
