/*******************************************************************************
 *      file name: sum_of_square_numbers.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/28-19:21:18                              
 *  modified time: 2018/08/28-19:21:18                              
 *******************************************************************************/
#include <iostream>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
		set<int> s;
		int sqrt_val = sqrt(c);
		for (int i=0; i < sqrt_val + 1; i++)
		{
			s.insert(i*i);
		}
		for (int i = 0; i < sqrt_val + 1; i++)
		{
			int temp = c - i*i;
			if (s.find(temp) != s.end())
				return true;
		}
		return false;
    }
};
int main()
{}
