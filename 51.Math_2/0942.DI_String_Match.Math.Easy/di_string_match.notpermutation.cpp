/*******************************************************************************
 *      file name: di_string_match.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/31-10:41:38                              
 *  modified time: 2019/01/31-10:41:38                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string S) {
		int floor = 0, upper = 0, x = 0;
		//int floor_pos = 0, upper_pos = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if ((S[i] == 'I') && (++x > upper))
			{
				upper = x;
				//upper_pos = i;
			}
			else if (--x < floor)
			{
				floor = x;
				//floor_pos = i;
			}
		}
		vector<int> vec;
		int val = 0 - floor;
		vec.push_back(val);
		for (auto &e : S)
		{
			if (e == 'I')
				vec.push_back(++val);
			else
				vec.push_back(--val);
		}
		return vec;

    }
};
int main()
{}
