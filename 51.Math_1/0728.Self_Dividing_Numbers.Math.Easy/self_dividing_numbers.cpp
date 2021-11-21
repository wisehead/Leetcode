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
		string y = to_string(x);
		int len = y.length();
		for (int i = 0; i < len; i++)
		{
			char c = y[i];
			if (c == '0') return false;
			if (x % (c - 48) != 0)
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
