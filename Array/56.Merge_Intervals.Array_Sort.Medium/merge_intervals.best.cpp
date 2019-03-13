/*******************************************************************************
 *      file name: merge_intervals.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/13-09:52:40                              
 *  modified time: 2019/03/13-09:52:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) 
	{
		vector<Interval> res;
		if (intervals.empty())return res;
		sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {return lhs.start < rhs.start; });
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (res.back().end >= intervals[i].start) res[res.size() - 1].end = (res.back().end < intervals[i].end)? intervals[i].end:res.back().end;
			else res.push_back(intervals[i]);
		}
		return res;
	}
};

int main()
{
	Solution sol;
	int arr[] = {};
}
