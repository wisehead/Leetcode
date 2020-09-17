/*******************************************************************************
 *      file name: k_closest_points_to_origin.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/13-15:44:14                              
 *  modified time: 2019/02/13-15:44:14                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int> >(points.begin(), points.begin() + K);
    }
};
int main()
{}
