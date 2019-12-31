/*******************************************************************************
 *      file name: find_the_town_judge.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/12/31-22:07:44                              
 *  modified time: 2019/12/31-22:07:44                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> ss;
		int index = 0;
		for (int i = 0; i < trust.size(); i++)
		{
			if (trust[i][0] == trust[0][0])
				ss.push_back(trust[i][1]);
		}
		for (int i = 0; i < trust.size(); i++)
		{
			vector<int> s;
		    vector<int> c;
			vector<int> vec = trust[i];
			if (i == 0) index = vec[0];
			if (vec[0] == index)
			{
				s.push_back(vec[1]);
			}
			else
			{
				index = vec[0];
				set_intersection(ss.begin(), ss.end(), s.begin(), s.end(), c.begin());
				ss.swap(c);
			}
		}
		if (ss.size() == 1)
			return ss[0];
		return -1;
    }
};
int main()
{}
