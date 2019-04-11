/*******************************************************************************
 *      file name: summary_ranges.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/11-19:19:04                              
 *  modified time: 2019/04/11-19:19:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int size = nums.size();
        if (!size) return res;
		int start = nums[0], end = nums[0];
		for (int i = 1; i < size; i++)
		{
			if (nums[i] != nums[i-1] + 1) 
			{
                string s;
                if (start != end)
				    s = to_string(start) + "->" + to_string(end);
                else
                    s = to_string(start);
				res.push_back(s);
				start = nums[i];
			}
            end = nums[i];
		}
        string s;
        if (start != end)
			s = to_string(start) + "->" + to_string(end);
        else
            s = to_string(start);
		res.push_back(s);
		return res;
    }
};
int main()
{}
