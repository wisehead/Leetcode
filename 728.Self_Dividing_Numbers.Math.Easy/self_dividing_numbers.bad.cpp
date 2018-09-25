/*******************************************************************************
 *      file name: self_dividing_numbers.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/25-11:27:49                              
 *  modified time: 2018/09/25-11:27:49                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool is_sdn(int x)
	{
		int len = 0;
		if (x / 1000 != 0) len = 4;
		else if (x /100 != 0) len =3;
		else if (x /10 != 0) len =2;
		else if (x /1 != 0) len =1;
		if (x >= 10000) return false;
		for (int i = 0; i < len; i++)
		{
			int mask = 1 << i;
			if (x % mask == 0)
				return false;
			int digit = x / mask;
			if (x % digit != 0)
				return false;
		}
		return true;
	}

    vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int x = left; x <= right; x++)
		{
			if (is_sdn(x)) res.push_back(x);
		}
		return res;
    }
};
int main()
{}
