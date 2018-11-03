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
		int len = cost.size();
		map<int, int> f;
		map<int, int> flag;
		for (int i = 1; i <= len; i++)
		{
			if (i == 1) 
			{
				f[1] = cost[0];
				flag[1] = 1;
				continue;
			}

			if (i == 2) 
			{
				flag[2] = 0;
				f[2] = min(cost[0], cost[1]);
				if (f[2] == cost[1])
					flag[2] = 1;
				continue;
			}
			
			if (i == 3) 
			{
				flag[3] = 0;
				f[3] = min(cost[0] + cost[2], cost[1]);
				if (f[3] == cost[0] + cost[2])
					flag[3] = 1;
				continue;
			}

			if (i == 4) 
			{
				flag[4] = 0;
				f[4] = min(cost[0] + cost[2], cost[1] + cost[2]);
				f[4] = min(f[4], cost[1] + cost[3]);
				if (f[4] == cost[1] + cost[3])
					flag[4] = 1;
				continue;
			}

			if (flag[i-4])
			{
				flag[i] = 0;
				f[i] = min(f[i-4] + cost[i-4] + cost[i-2], f[i-4] + cost[i-3] + cost[i-2]);
				f[i] = min(f[i], f[i-4] + cost[i-3] + cost[i-1]);
				if (f[i] == f[i-4] + cost[i-3] + cost[i-1])
					flag[i] = 1;
			}
			else
			{
				flag[i] = 0;
				f[i] = min(f[i-4] + cost[i-4] + cost[i-2], f[i-4] + cost[i-4] + cost[i-3] + cost[i-1]);
				if (f[i] == f[i-4] + cost[i-4] + cost[i-3] + cost[i-1])
					flag[i] = 1;
			}
		}
		return f[len];
    }
};
int main()
{}
