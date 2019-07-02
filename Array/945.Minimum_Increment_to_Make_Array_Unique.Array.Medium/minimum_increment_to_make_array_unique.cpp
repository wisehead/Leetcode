/*******************************************************************************
 *      file name: minimum_increment_to_make_array_unique.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/02-19:07:36                              
 *  modified time: 2019/07/02-19:07:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
		int n = A.size();
		map<int, int> m;
		int dups = 0;
		int sum1 = 0, sum2 = 0;
		vector<int> vec;
		for (auto e : A)
		{
			if (m.count(e))
			{
				m[e]++;
				dups++;
				sum1 += e;
                //cout<<"sum1:"<<sum1<<endl;
                vec.push_back(e);
			}
			else
				m[e] = 1;
		}
        sort(vec.begin(), vec.end());
        for (auto e : vec)
        {
            //cout<<"e:"<<e<<endl;
		    for (int i = e+1; dups > 0; i++)
		    {
			    if (!m.count(i)) 
			    {
				    dups--;
				    sum2 += i;
                    //cout<<"sum2:"<<sum2<<endl;
                    m[i] = 1;
                    break;
			    }
		    }
        }
		return (sum2 - sum1);
    }
};
int main()
{}
