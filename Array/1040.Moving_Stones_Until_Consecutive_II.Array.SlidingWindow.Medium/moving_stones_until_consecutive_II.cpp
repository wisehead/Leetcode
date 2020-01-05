/*******************************************************************************
 *      file name: moving_stones_until_consecutive_II.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/05-15:20:24                              
 *  modified time: 2020/01/05-15:20:24                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int getFirstGap(vector<int>& stores) {
		int n = stones.size();
		for (int i = 0; i < n; i++)
		{
			if (i+1 < n && stones[i+1] - stones[i] > 1)
				return i;
		}
		return 0;
	}

	int getLastGap(vector<int>& stores) {
		int n = stones.size();
		for (int i = n - 1; i >= 0; i--)
		{
			if (i-1 >= 0 && stones[i] - stones[i-1] > 1)
				return i-1;
		}
		return 0;
	}

	int fixOneGap(vector<int>& stores, int gap_start) {
		int gap_size = stores[gap_start+1] - stores[gap_start];
		if (gap_size == 1) return 1;
		return 2;
	}

    vector<int> numMovesStonesII(vector<int>& stones) {
		int steps = 0;
		sort(stones.begin(), stones.end());
		int first = getFistGap(stones);
		if (!first) return steps;
		int last = getLastGap(stones);
		int first_gap = stones[first+1] - stones[first];
		int last_gap = stones[last+1] - stones[last];
    }
};
int main()
{}
