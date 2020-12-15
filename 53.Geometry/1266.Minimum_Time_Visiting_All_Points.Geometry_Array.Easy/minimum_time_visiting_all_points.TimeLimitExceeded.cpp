/*******************************************************************************
 *      file name: minimum_time_visiting_all_points.TimeLimitExceeded.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/12/15-14:26:27                              
 *  modified time: 2020/12/15-14:26:27                              
 *******************************************************************************/
#include <iostream>
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
            while (c_x != n_x || c_y != n_y) {
                vector<int> vec = step(c_x, c_y, n_x, n_y);
                c_x += vec[0];
                c_y += vec[1];
                steps++;
            }
        }
        return steps;
        
    }
    
    vector<int> step(int c_x, int c_y, int n_x, int n_y) {
        vector<int> res;
        if (n_x == c_x) {    
            res.push_back(0);
        } else if (n_x > c_x) {
            res.push_back(1);
        } else {//n_x < c_x
            res.push_back(-1);    
        }        

        if (n_y == c_y) {    
            res.push_back(0);
        } else if (n_y > c_y) {
            res.push_back(1);
        } else {//n_x < c_x
            res.push_back(-1);    
        }  
        return res;
    }
    
};
int main()
{}
