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
/*
Use two variable to record current start and end point.
If the start of new interval is greater than current end, meaning NO overlapping, we can sum the current interval length to result and then update start and end.
Otherwise just update the current end;
 */
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;
        
        int result = 0, start = timeSeries[0], end = timeSeries[0] + duration;
        for (int i = 1; i < timeSeries.size(); i++) {
            if (timeSeries[i] > end) {
                result += end - start;
                start = timeSeries[i];
            }
            end = timeSeries[i] + duration;
        }
        result += end - start;
        
        return result;
    }
};
int main()
{}
