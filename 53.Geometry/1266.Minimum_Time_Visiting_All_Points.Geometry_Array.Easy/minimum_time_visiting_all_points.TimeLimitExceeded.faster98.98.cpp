/*******************************************************************************
 *      file name: minimum_time_visiting_all_points.TimeLimitExceeded.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/12/15-14:26:27                              
 *  modified time: 2020/12/15-14:26:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int c_x = points[0][0];
        int c_y = points[0][1];
        int n_x = 0;
        int n_y = 0; 
        int steps = 0;
        for (int i = 1; i < n; i++) {
            n_x = points[i][0];
            n_y = points[i][1];
            int step = max(abs(n_x - c_x), abs(n_y - c_y));
            steps += step;
            c_x = n_x;
            c_y = n_y;
        }
        return steps;
        
    }
};
int main()
{}
