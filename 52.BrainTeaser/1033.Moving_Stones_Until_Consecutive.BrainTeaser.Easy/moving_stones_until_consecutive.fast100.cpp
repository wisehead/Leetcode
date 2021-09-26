/*******************************************************************************
 *      file name: moving_stones_until_consecutive.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/22-09:15:58                              
 *  modified time: 2020/09/22-09:15:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> res;
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        sort(vec.begin(), vec.end());
        int d1 = vec[1] - vec[0] - 1;
        int d2 = vec[2] - vec[1] - 1;
        int max_v = d1 + d2;
        int min_v = min(d1, d2);
        if ((min_v == 0) && (d1 != d2)) min_v = 1;
        if (min_v > 2) min_v = 2;
        res.push_back(min_v);
        res.push_back(max_v);
        return res;
    }
};
int main()
{}
