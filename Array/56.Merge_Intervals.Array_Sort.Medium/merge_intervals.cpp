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
bool cmp(Interval x, Interval y)
{
	return (x.start < y.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		int size = intervals.size();
        if (!size) return res;
        if (size == 1) return intervals;
		sort(intervals.begin(), intervals.end(), cmp);
        
        Interval merge(intervals[0].start, intervals[0].end);
		for (int i = 1; i < size; i++)
		{
			if (merge.end >= intervals[i].start)
			{
				merge.start = merge.start;
                merge.end = max(merge.end, intervals[i].end);;
			}
			else
            {
				res.push_back(merge);
				merge.start = intervals[i].start;
                merge.end = intervals[i].end;
            }
            if (i == size - 1) res.push_back(merge);
		}
		return res;
    }
};

int main()
{
	Solution sol;
	int arr[] = {};
}
