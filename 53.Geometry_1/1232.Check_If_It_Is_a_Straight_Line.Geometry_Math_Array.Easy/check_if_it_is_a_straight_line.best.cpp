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
        if(coordinates.size() <= 2) return true;
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        for(int i=2;i<coordinates.size();i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if((y2 - y1) * (x1 - x) != (y1 - y) * (x2 - x1))
                return false;
        }
        return true;
    }
};
int main()
{}
