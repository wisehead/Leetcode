/*******************************************************************************
 *      file name: sqrt_best.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/11-17:57:07                              
 *  modified time: 2020/09/11-17:57:07                              
 *******************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = x;
        while (l < r)
        {
            long long m = (l+r)/2;
            if (m*m == x) return m;
            if (m*m < x) l = m + 1;
            else r = m;
        }
        if (l*l > x) return l-1;
        return l;
    }
};

int main()
{}
