/*******************************************************************************
 *      file name: fibonacci_number.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/28- 9:09                                    
 * modified time: 24/09/28- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int fib(int n) {
        if (ht.count(n)) return ht[n];
        if (n == 0) return 0;
        if (n == 1) return 1;
        int ret = fib(n-1) + fib(n-2);
        ht[n] = ret;
        return ret;
    }
    map<int,int> ht;
};
