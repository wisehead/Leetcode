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
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> vec(n+1,0);
        vec[1] = 1;
        for (int i = 2; i <= n; i++) {
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec[n];
    }
};
