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
        if (mem.count(n)) return mem[n];
        int steps = 1;
        if (n == 1) return 0;
        if (n % 2) {
            steps += power(n*3 + 1);
        } else {
            steps += power(n/2);
        }
        mem[n] = steps;
        return steps;
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> res;
        for (int i = lo; i <= hi; i++) {
            int step = power(i);
            // cout<<"i:"<<i<<", step:"<<step<<endl;
            vector<int> vec = {step, i};
            res.emplace_back(vec);
        }
        sort(res.begin(), res.end());
        return res[k-1][1];
    }
};
