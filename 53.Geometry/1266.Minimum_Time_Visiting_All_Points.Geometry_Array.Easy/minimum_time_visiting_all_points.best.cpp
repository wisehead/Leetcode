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
        int steps = 0;
        for (int i = 0; i < points.size()-1; i++) {
            steps += max(abs(points[i+1][0] - points[i][0]), abs(points[i+1][1] - points[i][1]));
        }
        return steps; 
    }
};
int main()
{}
