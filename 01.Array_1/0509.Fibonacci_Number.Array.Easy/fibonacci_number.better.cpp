/*******************************************************************************
 *      file name: fibonacci_number.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/22-18:45:01                              
 *  modified time: 2019/02/22-18:45:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int fib(int N) {
		if (N == 0) return 0;
		if (N == 1) return 1;
		vector<int> vec;
		for (int i = 0; i <= N; i++)
		{
			if (i == 0) 
			{
				vec.push_back(0);
			}
			else if (i==1)
			{
				vec.push_back(1);
			}
			else
			{
				int tmp = vec[i-1] + vec[i-2];
				vec.push_back(tmp);
			}
		}
		return vec[N];
    }
};
int main()
{}
