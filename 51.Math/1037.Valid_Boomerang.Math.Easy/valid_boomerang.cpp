/*******************************************************************************
 *      file name: valid_boomerang.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/23-09:34:01                              
 *  modified time: 2020/09/23-09:34:01                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        //return !((points[1][1] - points[0][1])/(points[1][0] - points[0][0]) == (points[2][1] - points[1][1])/(points[2][0] - points[1][0]) );
        return !((points[1][1] - points[0][1])*(points[2][0] - points[1][0]) == (points[2][1] - points[1][1])*(points[1][0] - points[0][0]));
    }
};
int main()
{}
