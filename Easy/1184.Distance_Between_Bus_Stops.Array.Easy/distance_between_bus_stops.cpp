/*******************************************************************************
 *      file name: distance_between_bus_stops.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/23-20:03:45                              
 *  modified time: 2020/01/23-20:03:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int n = distance.size();
		int s = min(start, destination);
		int d = max(start, destination);
		int left = 0, right = 0;
		for (int i = 0; i < n; i++)
		{
			if (i < s)
				left += distance[i];
			else if (i < d)
				right += distance[i];
			else
				left += distance[i];
		}
		return min(left, right);
    }
};
int main()
{}
