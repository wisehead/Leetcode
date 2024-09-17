/*******************************************************************************
 *      file name: fibonacci_number.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/22-18:45:01                              
 *  modified time: 2019/02/22-18:45:01                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int N) {
		if (N == 0) return 0;
		if (N == 1) return 1;
		return fib(N - 1) + fib(N - 2);
    }
};
int main()
{}
