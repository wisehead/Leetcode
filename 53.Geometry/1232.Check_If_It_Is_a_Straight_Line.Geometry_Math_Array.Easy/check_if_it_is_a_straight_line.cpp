/*******************************************************************************
 *      file name: check_if_it_is_a_straight_line.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/22-08:56:25                              
 *  modified time: 2020/11/22-08:56:25                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        int g = 0;
        for (int i = 0; i < coordinates.size() - 1; i++) {
            if (i == 0) {
                if (coordinates[i+1][0] != coordinates[i][0])
                    g = (coordinates[i+1][1] - coordinates[i][1])/(coordinates[i+1][0] - coordinates[i][0]);
                else g = INT_MAX;
                continue;
            }
            if (coordinates[i+1][0] == coordinates[i][0]) {
                if (g != INT_MAX) return false;
                continue;
            }
            if ((coordinates[i+1][1] - coordinates[i][1])/(coordinates[i+1][0] - coordinates[i][0]) != g) return false;
        }
        return true;
    }
};
int main()
{}
