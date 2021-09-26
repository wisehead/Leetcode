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
        if(N < 2) return N;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
int main()
{}
