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
        if (n <= 1) return 0;
		map<int, int> m;
		int dups = 0;
		int sum1 = 0, sum2 = 0;
		vector<int> vec;
		vector<int> vec2;
		for (auto e : A)
		{
			if (m.count(e))
			{
				m[e]++;
				sum1 += e;
                vec.push_back(e);
			}
			else
				m[e] = 1;
		}
        int size = vec.size();
        if (size == 0) return 0;
        sort(vec.begin(), vec.end());
		for (int i = 0; i <= vec[size-1] + n; i++)
		{
			if (!m.count(i)) 
				vec2.push_back(i);
		}
        for (auto e : vec)
        {
			vector<int>::iterator it = upper_bound(vec2.begin(), vec2.end(), e);
			sum2 += *it;
			vec2.erase(it);
        }
		return (sum2 - sum1);
    }
};
int main()
{}
