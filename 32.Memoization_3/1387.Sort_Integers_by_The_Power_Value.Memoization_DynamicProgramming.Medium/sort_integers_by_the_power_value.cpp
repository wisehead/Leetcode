/*******************************************************************************
 *      file name: sort_integers_by_the_power_value.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/15- 1:01                                    
 * modified time: 25/01/15- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    unordered_map<int, int> mem;
    int power(int n) {
        // if (mem.count(n)) return mem[n];
        int steps = 0;
        while (n != 1) {
            if (n % 2) {
                n = n*3 + 1;
            } else {
                n /= 2;
            }
            steps++;
        }
        // mem[n] = steps;
        return steps;
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> res;
        for (int i = lo; i <= hi; i++) {
            int step = power(i);
            vector<int> vec = {step, i};
            res.emplace_back(vec);
        }
        sort(res.begin(), res.end());
        return res[k-1][1];
    }
};
