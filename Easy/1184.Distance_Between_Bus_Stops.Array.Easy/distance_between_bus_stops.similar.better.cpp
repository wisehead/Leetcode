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
	  int sum1 = 0, sum2 = 0;
	  if (start > destination) swap(start, destination);
	  for (auto i = 0; i < distance.size(); ++i) {
	    if (i >= start && i < destination) sum1 += distance[i];
	    else sum2 += distance[i];
	  }
	  return min(sum1, sum2);
	}
};
int main()
{}
