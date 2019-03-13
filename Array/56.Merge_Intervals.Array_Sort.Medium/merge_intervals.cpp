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
	if(x.start < y.start)
		return true;
	if(x.start > y.start)
		return false;
	if (x.end <= y.end)
		return true;
	return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		int size = intervals.size();
		for (auto& e : intervals)
		{
			cout<<"start:"<<e.start<<"	end:"<<e.end<<endl;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		for (auto& e : intervals)
		{
			cout<<"start:"<<e.start<<"	end:"<<e.end<<endl;
		}
		bool is_merge = false;
		for (int i = 0; i < size - 1; i++)
		{
			is_merge = false;
			if (intervals[i].end >= intervals[i+1].start)
			{
				Interval merge(intervals[i].start, intervals[i+1].end);
				res.push_back(merge);
				is_merge = true;
			}
			else
				res.push_back(intervals[i]);
		}
		if (!is_merge) res.push_back(intervals[size - 1]);
		return res;
    }
};

int main()
{
	Solution sol;
	int arr[] = {};
}
