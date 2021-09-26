/*******************************************************************************
 *      file name: pow.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/05-09:36:08                              
 *  modified time: 2021/08/05-09:36:08                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n % 2 == 0) return myPow(x*x,n/2);
        if (n > 0)
            return x*myPow(x*x,n/2);
        else 
            return 1/x*myPow(x*x,n/2);
    }
};
int main()
{}
