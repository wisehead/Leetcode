/*******************************************************************************
 *      file name: teemo_attacking.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/23-09:44:37                              
 *  modified time: 2019/04/23-09:44:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int begin = timeSeries[0], total = 0;
        for (auto t : timeSeries) {
            total = total + (t < begin + duration ? t - begin : duration);
            begin = t;
        }   
        return total + duration;
    }
};
int main()
{}
