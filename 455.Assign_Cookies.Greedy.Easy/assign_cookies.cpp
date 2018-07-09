/*******************************************************************************
 *      file name: assign_cookies.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/09-22:48:53                              
 *  modified time: 2018/07/09-22:48:53                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end()); 
		sort(s.begin(), s.end()); 
		vector<int>::iterator it_g, it_s;
		int count = 0;
		for (it_g = g.begin(), it_s = s.begin(); it_g != g.end() && it_s != s.end(); )
		{
			if (*it_g <= *it_s)
			{
				count++;
				it_g++; it_s++;
			}
			else
			{
				it_s++;
			}
		}
		return count;
    }
};
int main()
{}
