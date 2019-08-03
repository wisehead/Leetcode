/*******************************************************************************
 *      file name: height_checker.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/08/03-10:44:16                              
 *  modified time: 2019/08/03-10:44:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
		int n = heights.size();
		int ret = 0;
		vector<int> vec(102, 0);
		vector<int> vec2(102, 0);
		for (auto e: heights)
			vec[e]++;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			vec2[i] = cnt;
			cnt += vec[i];
		}
		for (int i = 0; i < n; i++)
		{
			int x = heights[i];
			if (i >= vec2[x] && i < vec2[x+1])
				continue;
			ret++;
		}
		return ret;
    }
};
int main()
{}
