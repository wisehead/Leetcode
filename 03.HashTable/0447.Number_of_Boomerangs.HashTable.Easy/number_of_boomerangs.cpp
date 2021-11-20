/*******************************************************************************
 *      file name: number_of_boomerangs.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/07/08- 7:07                                    
 *  modified time: 18/07/08- 7:07                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
		int count = 0;
		vector<pair<int, int> >::iterator it, it2;
		for (it = points.begin(); it != points.end(); it++)
		{
			map<int, int> m;
			for (it2 = points.begin(); it2 != points.end(); it2++)
			{
				int dis =  ((*it).first - (*it2).first)*((*it).first - (*it2).first) + ((*it).second - (*it2).second)*((*it).second - (*it2).second);
				map<int, int>::iterator it_map = m.find(dis);
			    if (it_map == m.end())
			    {
				    m[dis] = 1;
			    }
			    else
			    {
				    count += m[dis] * 2;
					m[dis]++;
			    }
			}
		}
		return count;
    }
};
int main()
{}
