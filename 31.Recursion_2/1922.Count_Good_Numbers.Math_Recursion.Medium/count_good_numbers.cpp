/*******************************************************************************
 *      file name: count_good_numbers.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/15-10:07:32                              
 *  modified time: 2021/12/15-10:07:32                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ret = f(n);
        return ret;
    }
    
    
    long long f(long long n) {
        long long N = 1000000007;
        //if (n==0) return 1;
        if (n==1) return 5;
        if (n==2) return 20;
        if (n % 2 == 0) {
            if (n % 4 == 0) {
                long long x = f(n/2);
                return (x*x)%N;
            }
            else 
                return f(n-2)*20%N;
        }
        return (f(n-1))*5%N;
    }    

};
int main()
{}
