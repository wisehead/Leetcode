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
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
		int cnt = 0;
		sort(ages.begin(), ages.end());
		for (int i = 0; i < ages.size(); i++)
		{
            if (ages[i] > 14)
            {
			    for (int j = i+1; j < ages.size(); j++)
			    {
				    if (ages[j] != ages[i])
					    break;
				    cnt++;
			    }
            }
			for (int j = 0; j < i; j++)
			{
				if (ages[j] <= 0.5 * ages[i] + 7)
					continue;
				cnt++;
			}
		}
		return cnt;
    }
};
int main()
{}
