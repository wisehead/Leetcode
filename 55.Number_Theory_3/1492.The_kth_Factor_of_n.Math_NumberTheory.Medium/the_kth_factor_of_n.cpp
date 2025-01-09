/*******************************************************************************
 *      file name: the_kth_factor_of_n.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/09- 1:01                                    
 * modified time: 25/01/09- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) res.push_back(i);
            if (res.size() >= k) return res[k-1];
        }
        return -1;
    }
};`
