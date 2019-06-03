/*******************************************************************************
 *      file name: friends_of_appropriate_ages.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/03-09:24:35                              
 *  modified time: 2019/06/03-09:24:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
		int cnt = 0;
		map<int,int> count;
		for (auto e: ages)
			count[e]++;
		map<int,int>::iterator it;
		map<int,int>::iterator it2;
		for (it = count.begin(); it != count.end(); it++)
		{
			for (it2 = count.begin(); it2 != count.end(); it2++)
			{
				if (it2->first > it->first)
					continue;
				if (it2->first == it->first)
				{
					if (it->first > 14)
						cnt += it->second * (it->second -1);
					continue;
				}
				if (it2->first < it->first)
				{
					if (it2->first > 0.5 * it->first + 7)
						cnt += it2->second * it->second;
				}
				
			}
		}
		return cnt;
    }
};
int main()
{}
