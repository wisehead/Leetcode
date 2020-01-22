/*******************************************************************************
 *      file name: array_of_doubled_pairs.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/06-21:40:22                              
 *  modified time: 2019/07/06-21:40:22                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map> 
using namespace std;
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
		map<int, int> m;
		for (auto e: A)
		{
			if (m.count(e))
				m[e]++;
			else
				m[e] = 1;
		}
		map<int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++)
		{
			int e = it->first;
            //cout<<"e:"<<e<<endl;
			
            while (m[e] > 0)
            {
			    m[e]--;
			    if (e >= 0)
			    {
				    if (m.count(2*e) && m[2*e] > 0)
					    m[2*e]--;
				    else
				    	return false;
			    }
			    else//<0
			    {
				    if (m.count(e/2) && m[e/2] > 0)
					    m[e/2]--;
				    else
				    	return false;
			    }
            }
		}
		return true;
    }
};
int main()
{}
