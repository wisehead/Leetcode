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
        int size = coordinates.size();
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        double g = 0.0;
        if (size > 1) {
            if (coordinates[1][0] != x)
                g = (double)(coordinates[1][1] - y)/(coordinates[1][0] - x);
            else g = INT_MAX;
        }
        //cout<<"g:"<<g<<endl;
        for (int i = 2; i < size; i++) {
            if (coordinates[i][0] == x) {
                if (g != INT_MAX) return false;
                continue;
            }
            double temp = (double)(coordinates[i][1] - y)/(coordinates[i][0] - x);
            //cout<<"temp:"<<temp<<endl;
            if (temp != g) return false;
            //if ((coordinates[i][1] - y)/(coordinates[i][0] - x) != g) return false;
        }
        return true;
    }
};
int main()
{}
