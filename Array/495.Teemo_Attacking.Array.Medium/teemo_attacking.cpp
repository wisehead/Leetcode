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
		int n = timeSeries.size();
        if (!n) return 0;
		int sum = 0;
		for (int i = 0; i < n-1; i++)
		{
			int attack = (timeSeries[i+1] - timeSeries[i] >= duration) ? duration : timeSeries[i+1] - timeSeries[i];
			sum += attack;
		}
		sum += duration; 
		return sum;
    }
};
int main()
{}
