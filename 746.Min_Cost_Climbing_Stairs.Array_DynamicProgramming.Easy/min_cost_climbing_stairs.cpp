/*******************************************************************************
 *      file name: min_cost_climbing_stairs.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/03-21:44:56                              
 *  modified time: 2018/11/03-21:44:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2; i<n; ++i)
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
        return min(dp[n-2],dp[n-1]);
    }
};
int main()
{}
