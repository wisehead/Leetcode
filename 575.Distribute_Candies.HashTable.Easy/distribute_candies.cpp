/*******************************************************************************
 *      file name: distribute_candies.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-22:23:07                              
 *  modified time: 2018/08/25-22:23:07                              
 *******************************************************************************/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
		set<int> s;
		int size_candy = candies.size();
		for (int i = 0; i < size_candy; i++)
			s.insert(candies[i]);
		int size_set = s.size();
		return min(size_set, size_candy/2);
    }
};
int main()
{}
